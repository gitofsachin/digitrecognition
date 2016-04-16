#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include "/home/sachin/tivaware/inc/hw_ints.h"
#include "/home/sachin/tivaware/inc/hw_memmap.h"
#include "/home/sachin/tivaware/driverlib/debug.h"
#include "/home/sachin/tivaware/driverlib/fpu.h"
#include "/home/sachin/tivaware/driverlib/gpio.h"
#include "/home/sachin/tivaware/driverlib/interrupt.h"
#include "/home/sachin/tivaware/driverlib/pin_map.h"
#include "/home/sachin/tivaware/driverlib/rom.h"
#include "/home/sachin/tivaware/driverlib/sysctl.h"
#include "/home/sachin/tivaware/driverlib/uart.h"

void togglerled();
void toggleled();
void onButtonDown(void);
void SW2intinit();
void UARTconfig();
void uartintinit(void);
void myinit();
void displaymasterinit();

extern int startpredict;
char image[1024];
extern char deselogo[600];
