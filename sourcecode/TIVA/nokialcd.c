#include "nokialcd.h"

#define delay_major 1
//#define delay_minor 1

#define DATA GPIO_PIN_7
#define CLK GPIO_PIN_6
#define CS GPIO_PIN_5
#define SHDN GPIO_PIN_4

#define BGCOLOR WHITE

#define LCD_RESET_LOW GPIOPinWrite(GPIO_PORTC_BASE,CS,0xFF);
#define LCD_RESET_HIGH GPIOPinWrite(GPIO_PORTC_BASE,CS,0x00);

// 12-bit color definitions
int WHITE;
int BLACK;
int RED;
int GREEN;
int BLUE;
int CYAN;
int MAGENTA;
int YELLOW;
int mode;

void Delay (unsigned long a)
{
	while (--a!=0);
}

void setbit(unsigned char ch)
{
	GPIOPinWrite(GPIO_PORTC_BASE,ch,0xFF);
}

void resetbit(unsigned char ch)
{
	GPIOPinWrite(GPIO_PORTC_BASE,ch,0x00);
}

void WriteSpiCommand(char command)
{
	resetbit(CLK);
	resetbit(DATA);
	resetbit(CLK);
	setbit(CLK);
	Delay(delay_major);
	resetbit(CLK);
//	Delay(delay_minor);
	unsigned char mask=0x80;
	int i;
	for(i=0;i<8;i++)
	{
		if(mask&command)
		{
			setbit(DATA);
		}
		else
		{
			resetbit(DATA);
		}
		mask=mask>>1;
		resetbit(CLK);
		setbit(CLK);
		Delay(delay_major);
		resetbit(CLK);
//		Delay(delay_minor);
	}
}

void WriteSpiData(char data)
{
	resetbit(CLK);
	setbit(DATA);
	resetbit(CLK);
	setbit(CLK);
	Delay(delay_major);
	resetbit(CLK);
//	Delay(delay_minor);
	unsigned char mask=0x80;
	int i;
	for(i=0;i<8;i++)
	{
		if(mask&data)
		{
			setbit(DATA);
		}
		else
		{
			resetbit(DATA);
		}
		mask=mask>>1;
		resetbit(CLK);
		setbit(CLK);
		Delay(delay_major);
		resetbit(CLK);
//		Delay(delay_minor);
	}
}

void InitLcd(int n)
{
	LCD_RESET_LOW;
	Delay(20000);
	LCD_RESET_HIGH;
	Delay(20000);
	WriteSpiCommand(SLEEPOUT);
	//WriteSpiCommand(INVON);
	WriteSpiCommand(COLMOD);
	WriteSpiData(0x03);
	WriteSpiCommand(MADCTL);
	WriteSpiData(0xC8);
	WriteSpiCommand(SETCON);
	WriteSpiData(0x30);
	Delay(20000);
	WriteSpiCommand(DISPON);

    if(n==1)
    {
    	mode=0;
		WHITE= 0x000;
		BLACK= 0xFFF;
		RED= 0xFF0;
		GREEN= 0xF0F;
		BLUE= 0x0FF;
		CYAN= 0x00F;
		MAGENTA =0x0F0;
		YELLOW= 0xF00;
    }
    else
    {
    	mode=1;
    	WHITE= 0xFFF;
		BLACK= 0x000;
		RED= 0x00F;
		GREEN= 0x0F0;
		BLUE= 0xF00;
		CYAN= 0xFF0;
		MAGENTA =0xF0F;
		YELLOW= 0x0FF;
    }
}

void LCDClearScreen(void) 
{

	long i;
	WriteSpiCommand(DISPOFF);
	WriteSpiCommand(PASET);
	WriteSpiData(0);
	WriteSpiData(131);
	WriteSpiCommand(CASET);
	WriteSpiData(0);
	WriteSpiData(131);
	WriteSpiCommand(RAMWR);
	for (i = 0; i < ((131 * 131) / 2); i++)
	{
		WriteSpiData((BGCOLOR >> 4) & 0xFF);
		WriteSpiData(((BGCOLOR & 0xF) << 4) | ((BGCOLOR >> 8) & 0xF));
		WriteSpiData(BGCOLOR & 0xFF);
	}
	WriteSpiCommand(DISPON);
}

void LCDSetXY(int x, int y) 
{
	// Row address set (command 0x2B)
	WriteSpiCommand(PASET);
	WriteSpiData(x);
	WriteSpiData(x);
	// Column address set (command 0x2A)
	WriteSpiCommand(CASET);
	WriteSpiData(y);
	WriteSpiData(y);
}

void LCDSetPixel(int x, int y, int color)
{
	LCDSetXY(x, y);
	WriteSpiCommand(RAMWR);
	WriteSpiData((unsigned char)((color >> 4) & 0xFFFF));
	WriteSpiData((unsigned char)(((color & 0x0F) << 4) | 0x00));
	WriteSpiCommand(NOP);
}

void LCDSetLine(int x0, int y0, int x1, int y1, int color) 
{
	int dy = y1 - y0;
	int dx = x1 - x0;
	int stepx, stepy;
	if (dy < 0) 
	{ 
		dy = -dy; stepy = -1; 
	} 
	else 
	{ 
		stepy = 1; 
	}
	if (dx < 0) 
	{ 
		dx = -dx; stepx = -1; 
	} 
	else 
	{ 
		stepx = 1; 
	}
	dy <<= 1;
	// dy is now 2*dy
	dx <<= 1;
	// dx is now 2*dx
	LCDSetPixel(x0, y0, color);
	if (dx > dy) 
	{
		int fraction = dy - (dx >> 1);
		while (x0 != x1) 
		{
			if (fraction >= 0) 
			{
				y0 += stepy;
				fraction -= dx;
			}
			x0 += stepx;
			fraction += dy;
			LCDSetPixel(x0, y0, color);
		}
	} 
	else 
	{
		int fraction = dx - (dy >> 1);
		while (y0 != y1) 
		{
			if (fraction >= 0) 
			{
				x0 += stepx;
				fraction -= dy;
			}
			y0 += stepy;
			fraction += dx;
			LCDSetPixel(x0, y0, color);
		}
	}
	// same as 2*dy - dx
	// same as fraction -= 2*dx
	// same as fraction -= 2*dy
}


void LCDSetRect(int x0, int y0, int x1, int y1, unsigned char fill, int color) 
{
	int temp=x0;
	x0=y0;
	y0=temp;
	temp=x1;
	x1=y1;
	y1=temp;
	int xmin, xmax, ymin, ymax;
	int i;
	// check if the rectangle is to be filled
	if (fill == FILL) 
	{
		// best way to create a filled rectangle is to define a drawing box
		// and loop two pixels at a time
		// calculate the min and max for x and y directions
		xmin = (x0 <= x1) ? x0 : x1;
		xmax = (x0 > x1) ? x0 : x1;
		ymin = (y0 <= y1) ? y0 : y1;
		ymax = (y0 > y1) ? y0 : y1;
		// specify the controller drawing box according to those limits
		// Row address set (command 0x2B)
		WriteSpiCommand(PASET);
		WriteSpiData(xmin);
		WriteSpiData(xmax);
		// Column address set (command 0x2A)
		WriteSpiCommand(CASET);
		WriteSpiData(ymin);
		WriteSpiData(ymax);
		// WRITE MEMORY
		WriteSpiCommand(RAMWR);
		// loop on total number of pixels / 2
		for (i = 0; i < ((((xmax - xmin + 1) * (ymax - ymin + 1)) / 2) + 1); i++) 
		{
			// use the color value to output three data bytes covering two pixels
			WriteSpiData((color >> 4) & 0xFF);
			WriteSpiData(((color & 0xF) << 4) | ((color >> 8) & 0xF));
			WriteSpiData(color & 0xFF);
		}
	}
	else 
	{
		LCDSetLine(x0,y0, x1,y0, color);
		LCDSetLine(x0,y1, x1,y1, color);
		LCDSetLine(x0,y0, x0,y1, color);
		LCDSetLine(x1,y0, x1,y1, color);
	}
}



void LCDWriteBmp3x(char*image,int x,int y)//Column major
{
	long i,j,k,row,col,rowd,cold;
	// loop counter
	// Memory access controler (command 0x36)
	//WriteSpiCommand(MADCTL);
	//WriteSpiData(0x48);
	// no mirror Y (temporary to satisfy Olimex bmptoarray utility)
	// Display OFF
	//WriteSpiCommand(DISPOFF);
	// Column address set (command 0x2A)
	WriteSpiCommand(CASET);
	WriteSpiData(x);
	WriteSpiData(x+84-1);
	// Page address set (command 0x2B)
	WriteSpiCommand(PASET);
	WriteSpiData(y);
	WriteSpiData(y+84-1);
	// WRITE MEMORY
	WriteSpiCommand(RAMWR);
	char ch1,ch2,ch3;
	char data1,data2;
	for (i = 0; i < 7056; i+=2)
	{
		rowd=84-1-i/84;
		cold=i%84;
		row=rowd;
		col=(84-1)-cold;
		j=((int)(col/3))*28+(row/3);
		rowd=84-1-(i+1)/84;
		cold=(i+1)%84;
		row=rowd;
		col=(84-1)-cold;
		k=((int)(col/3))*28+(row/3);
		if(mode==1)
		{
			data1=255-image[j];
			data2=255-image[k];
		}
		else
		{
			data1=image[j];
			data2=image[k];
		}
		ch1=((data1&0xF0)|((data1&0xF0)>>4));
		ch2=((data1&0xF0)|((data2&0xF0)>>4));
		ch3=((data2&0xF0)|((data2&0xF0)>>4));
		WriteSpiData(ch1);
		WriteSpiData(ch2);
		WriteSpiData(ch3);
	}
	// Memory access controler (command 0x36)
	WriteSpiCommand(MADCTL);
	WriteSpiData(0xC8);
	// restore to (mirror x and y, reverse rgb)
	// Display On
	//WriteSpiCommand(DISPON);
}

void LCDWriteBmp(char*image,int x,int y,int xsize,int ysize) //Row major
{
	long i,j,k;
	char ch1,ch2,ch3;
	WriteSpiCommand(CASET);
	WriteSpiData(x);
	WriteSpiData(x+xsize-1);
	WriteSpiCommand(PASET);
	WriteSpiData(y);
	WriteSpiData(y+ysize-1);
	WriteSpiCommand(RAMWR);
	unsigned char data1,data2;
	for(i=0;i<xsize*ysize;i+=2)
	{
		j=xsize*ysize-1-i;
		k=xsize*ysize-1-i-1;
		if(mode==0)
		{
			data1=255-image[j];
			data2=255-image[k];
		}
		else
		{
			data1=image[j];
			data2=image[k];
		}
		ch1=((data1&0xF0)|((data1&0xF0)>>4));
		ch2=((data1&0xF0)|((data2&0xF0)>>4));
		ch3=((data2&0xF0)|((data2&0xF0)>>4));
		WriteSpiData(ch1);
		WriteSpiData(ch2);
		WriteSpiData(ch3);
	}
}

void delay(int n)
{
	int i;
	for(i=0;i<n;i++);
}

void displayinit()
{

    WriteSpiCommand(DISPOFF);


	LCDSetRect(0,0,131,9,FILL,GREEN); //Bottom line
	LCDSetRect(0,0,21,110,FILL,GREEN); //Right line
	LCDSetRect(107,0,131,110,FILL,GREEN); //Left line
	LCDSetRect(0,109,131,95,FILL,GREEN); //Top line
	LCDWriteBmp(deselogo,50,110,30,20);
    LCDSetRect(21,9,106,94,NOFILL,RED);//Image border
    LCDSetRect(1,109,130,130,NOFILL,RED);//Logo border 1
    LCDSetRect(2,110,129,129,NOFILL,RED);//Logo border 2

    //Logo modifier (3x2 lines)
    LCDSetLine(120,20,120,40,RED);
    LCDSetLine(122,20,122,40,RED);
    LCDSetLine(118,20,118,40,RED);
    LCDSetLine(120,90,120,110,RED);
    LCDSetLine(122,90,122,110,RED);
    LCDSetLine(118,90,118,110,RED);
    WriteSpiCommand(DISPON);
}
