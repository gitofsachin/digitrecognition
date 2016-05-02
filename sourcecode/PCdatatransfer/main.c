#include <termios.h>
#include <stdio.h>

#include <sys/select.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

static struct termios old, new;

void initTermios(int echo) 
{
  tcgetattr(0, &old);
  new = old;
  new.c_lflag &= ~ICANON;
  new.c_lflag &= echo ? ECHO : ~ECHO;
  tcsetattr(0, TCSANOW, &new);
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char mygetch(void) 
{
  return getch_(0);
}

void drawmenu()
{
	printf("*************************************************************\n\r");
	printf("*************    DIGIT RECOGNITION USING CNN  ***************\n\r");
	printf("*************************************************************\n\r");
	printf("\n\r");
	printf("\t\tPress m to load MNIST image\n\r");
	printf("\t\tPress s to load sample.jpeg\n\r");
	printf("\t\tPress q to quit\n\r");
	printf("\n\r");
	printf("*************************************************************\n\r");
}

void inttostr(char* str,int n)
{
	int i=0,j;
	while(n)
	{
		str[i++]=n%10+'0';
		n=n/10;
	}
	str[i]='\0';
	j=0;
	char ch;
	while(j<=i/2&&i>0)
	{
		ch=str[j];
		str[j]=str[i-1-j];
		str[i-1-j]=ch;
		j++;
	}
}

int main(int argc, char*argv)
{
	system("clear");
	char ch='\n';
	char command[]="octave --silent sendimage.o ";
	char argument[6];
	char totalcommand[35];
	int n;
	drawmenu();
	srand(time(NULL));
	while(ch!='q')
	{
		ch=mygetch();
		n=rand()%10000;
		inttostr(argument,n);
		strcpy(totalcommand,command);
		strcat(totalcommand,argument);
		if(ch=='s')
			system("octave --silent sendimage.o 0");
		else if(ch=='m')
			system(totalcommand);
	}
	return 0;
}
