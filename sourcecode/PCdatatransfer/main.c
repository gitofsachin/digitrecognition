#include<stdio.h>

void drawmenu();

int main(int argc, char*argv)
{
	drawmenu();
	char ch;
	ch=getchar();
	if(ch=='1')
		system("octave --silent sendimage.o 0");
	else
		system("octave --silent sendimage.o 11");
	return 0;
}

void drawmenu()
{
	
}
