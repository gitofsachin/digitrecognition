/*
*******************************************************************

Digit Recognition using Neural Networks on TIVA microcontroller

				Department of Electronic Systems
			Indian Institute of Science, Bangalore

					Author	- Sachin S, Sajna Remi Clere

			Done as part of Mini Project for Embedded Systems
				Guide: Prof Haresh Dagale, DESE, IISc

*******************************************************************
*/


#include "userinterrupt.h"
#include "mylcd.h"

char deselogo[600];

int startpredict;

int main()
{
	uartintinit();
	SW2intinit();
	displaymasterinit();
	startdigitlcd();
    while(1)
    {
	}
}
