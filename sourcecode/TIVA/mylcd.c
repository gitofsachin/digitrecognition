/*
	16x2 lcd display main.c code - no additional header required
	Last 4 characters in both the rows not getting displayed
	Pin connection to TIVA
		Pins ordered left to right when pins are on top of the display
		GND,VBUS,PA5,PA2,PA3,PA4,PB0:PB7,VBUS/V3P3,GND
*/
#ifndef STRING_H
	#include "string.h"
#endif

#ifndef STDBOOL_H
#include "stdbool.h"
#endif

#ifndef SYSCTL_H
#include "/home/sachin/tivaware/driverlib/sysctl.h"
#endif

#ifndef TM4C123GH6PM_H
#include "/home/sachin/tivaware/inc/tm4c123gh6pm.h"
#endif

#ifndef GPIO_H
#include "/home/sachin/tivaware/driverlib/gpio.h"
#endif

#ifndef HW_MEMMAP_H
#include "/home/sachin/tivaware/inc/hw_memmap.h"
#endif


#include "mylcd.h"
unsigned char string1[]="DIGIT";
unsigned char string2[]="RECOGNIZED";


void mylcddelay(int n)
{
	int i;
	for(i=0;i<n;i++);
}

void digitlcdinitgpio()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); //Control signals
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); //Data signals
	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5); // RS,RW,E,CONTRAST GND
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
}

void digitlcdcommand(unsigned char command)
{
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_2,0x00);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_3,0x00);
	GPIOPinWrite(GPIO_PORTB_BASE,0xFF,command);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_4,0xFF);
	mylcddelay(10);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_4,0x00);
	mylcddelay(5000);
}

void digitlcddata(unsigned char data)
{
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_2,0xFF);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_3,0x00);
	GPIOPinWrite(GPIO_PORTB_BASE,0xFF,data);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_4,0xFF);
	mylcddelay(10);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_4,0x00);
	mylcddelay(5000);
}

void digitlcdinit()
{
	digitlcdinitgpio();
	digitlcdcommand(0x38);
	digitlcdcommand(0x38);
	digitlcdcommand(0x38);
	digitlcdcommand(0x38);
	digitlcdcommand(0x0E);
	digitlcdcommand(0x06);
	digitlcdcommand(0x01);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_5,0x00);
}

void startdigitlcd(void)
{
	digitlcdinit();
	int i;
	digitlcdcommand(0x84);
		for(i=0;i<5;i++)
			digitlcddata(string1[i]);
	digitlcdcommand(0xC6);
		digitlcddata('0');
	digitlcdcommand(0xCC);
		digitlcddata('0');
}

