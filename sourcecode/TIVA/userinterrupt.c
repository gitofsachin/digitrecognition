#include "userinterrupt.h"
#include "nokialcd.h"

const int sizex=28;
const int sizey=28;

extern int startpredict;

void initdeselogo()
{
	deselogo[0]=0xff;
	deselogo[1]=0xff;
	deselogo[2]=0xff;
	deselogo[3]=0xff;
	deselogo[4]=0xff;
	deselogo[5]=0xff;
	deselogo[6]=0xff;
	deselogo[7]=0xff;
	deselogo[8]=0xff;
	deselogo[9]=0xff;
	deselogo[10]=0xff;
	deselogo[11]=0xff;
	deselogo[12]=0xff;
	deselogo[13]=0xff;
	deselogo[14]=0xff;
	deselogo[15]=0xff;
	deselogo[16]=0xff;
	deselogo[17]=0xff;
	deselogo[18]=0xff;
	deselogo[19]=0xff;
	deselogo[20]=0xff;
	deselogo[21]=0xff;
	deselogo[22]=0xfe;
	deselogo[23]=0xfe;
	deselogo[24]=0xff;
	deselogo[25]=0xff;
	deselogo[26]=0xff;
	deselogo[27]=0xff;
	deselogo[28]=0xff;
	deselogo[29]=0xff;
	deselogo[30]=0xfe;
	deselogo[31]=0xfe;
	deselogo[32]=0xfe;
	deselogo[33]=0xfe;
	deselogo[34]=0xfe;
	deselogo[35]=0xfe;
	deselogo[36]=0xfe;
	deselogo[37]=0xfe;
	deselogo[38]=0xfe;
	deselogo[39]=0xfe;
	deselogo[40]=0xfe;
	deselogo[41]=0xfe;
	deselogo[42]=0xfe;
	deselogo[43]=0xfe;
	deselogo[44]=0xfe;
	deselogo[45]=0xfe;
	deselogo[46]=0xfe;
	deselogo[47]=0xfe;
	deselogo[48]=0xfe;
	deselogo[49]=0xfe;
	deselogo[50]=0xfe;
	deselogo[51]=0xfe;
	deselogo[52]=0xfe;
	deselogo[53]=0xfe;
	deselogo[54]=0xfe;
	deselogo[55]=0xfe;
	deselogo[56]=0xfe;
	deselogo[57]=0xfe;
	deselogo[58]=0xfe;
	deselogo[59]=0xfe;
	deselogo[60]=0xfc;
	deselogo[61]=0xfb;
	deselogo[62]=0xfb;
	deselogo[63]=0xf9;
	deselogo[64]=0xf9;
	deselogo[65]=0xfb;
	deselogo[66]=0xfc;
	deselogo[67]=0xfc;
	deselogo[68]=0xf9;
	deselogo[69]=0xf9;
	deselogo[70]=0xf9;
	deselogo[71]=0xf9;
	deselogo[72]=0xf9;
	deselogo[73]=0xfb;
	deselogo[74]=0xfc;
	deselogo[75]=0xfc;
	deselogo[76]=0xfb;
	deselogo[77]=0xf9;
	deselogo[78]=0xf9;
	deselogo[79]=0xf9;
	deselogo[80]=0xf9;
	deselogo[81]=0xfb;
	deselogo[82]=0xfc;
	deselogo[83]=0xfc;
	deselogo[84]=0xfb;
	deselogo[85]=0xf9;
	deselogo[86]=0xf9;
	deselogo[87]=0xfb;
	deselogo[88]=0xfb;
	deselogo[89]=0xfb;
	deselogo[90]=0xfb;
	deselogo[91]=0x9;
	deselogo[92]=0x7;
	deselogo[93]=0x7;
	deselogo[94]=0x7;
	deselogo[95]=0x7;
	deselogo[96]=0x9;
	deselogo[97]=0xf9;
	deselogo[98]=0x7;
	deselogo[99]=0x5;
	deselogo[100]=0x7;
	deselogo[101]=0x7;
	deselogo[102]=0x7;
	deselogo[103]=0x7;
	deselogo[104]=0xf9;
	deselogo[105]=0x9;
	deselogo[106]=0x8;
	deselogo[107]=0x7;
	deselogo[108]=0x7;
	deselogo[109]=0x7;
	deselogo[110]=0x7;
	deselogo[111]=0x8;
	deselogo[112]=0xf9;
	deselogo[113]=0x9;
	deselogo[114]=0x8;
	deselogo[115]=0x7;
	deselogo[116]=0x7;
	deselogo[117]=0x7;
	deselogo[118]=0x9;
	deselogo[119]=0xf9;
	deselogo[120]=0xf9;
	deselogo[121]=0x7;
	deselogo[122]=0x4;
	deselogo[123]=0x2;
	deselogo[124]=0x2;
	deselogo[125]=0x4;
	deselogo[126]=0x8;
	deselogo[127]=0xf8;
	deselogo[128]=0x4;
	deselogo[129]=0x2;
	deselogo[130]=0x2;
	deselogo[131]=0x2;
	deselogo[132]=0x2;
	deselogo[133]=0x4;
	deselogo[134]=0xf8;
	deselogo[135]=0x9;
	deselogo[136]=0x4;
	deselogo[137]=0x2;
	deselogo[138]=0x2;
	deselogo[139]=0x2;
	deselogo[140]=0x2;
	deselogo[141]=0x4;
	deselogo[142]=0xf8;
	deselogo[143]=0x8;
	deselogo[144]=0x4;
	deselogo[145]=0x2;
	deselogo[146]=0x2;
	deselogo[147]=0x4;
	deselogo[148]=0x7;
	deselogo[149]=0xf8;
	deselogo[150]=0xf9;
	deselogo[151]=0x7;
	deselogo[152]=0x4;
	deselogo[153]=0x2;
	deselogo[154]=0x1;
	deselogo[155]=0x4;
	deselogo[156]=0x7;
	deselogo[157]=0xf7;
	deselogo[158]=0x3;
	deselogo[159]=0x1;
	deselogo[160]=0x3;
	deselogo[161]=0x2;
	deselogo[162]=0x2;
	deselogo[163]=0x4;
	deselogo[164]=0xf7;
	deselogo[165]=0x7;
	deselogo[166]=0x4;
	deselogo[167]=0x2;
	deselogo[168]=0x2;
	deselogo[169]=0x2;
	deselogo[170]=0x2;
	deselogo[171]=0x4;
	deselogo[172]=0xf8;
	deselogo[173]=0x8;
	deselogo[174]=0x4;
	deselogo[175]=0x2;
	deselogo[176]=0x2;
	deselogo[177]=0x4;
	deselogo[178]=0x7;
	deselogo[179]=0xf8;
	deselogo[180]=0xfb;
	deselogo[181]=0x9;
	deselogo[182]=0x7;
	deselogo[183]=0x5;
	deselogo[184]=0x4;
	deselogo[185]=0x4;
	deselogo[186]=0x7;
	deselogo[187]=0xf8;
	deselogo[188]=0x6;
	deselogo[189]=0x7;
	deselogo[190]=0x7;
	deselogo[191]=0x6;
	deselogo[192]=0x7;
	deselogo[193]=0x7;
	deselogo[194]=0xf8;
	deselogo[195]=0x7;
	deselogo[196]=0x4;
	deselogo[197]=0x4;
	deselogo[198]=0x5;
	deselogo[199]=0x7;
	deselogo[200]=0x7;
	deselogo[201]=0x8;
	deselogo[202]=0xf9;
	deselogo[203]=0x9;
	deselogo[204]=0x8;
	deselogo[205]=0x7;
	deselogo[206]=0x7;
	deselogo[207]=0x7;
	deselogo[208]=0x9;
	deselogo[209]=0xf9;
	deselogo[210]=0xfc;
	deselogo[211]=0xfc;
	deselogo[212]=0xfb;
	deselogo[213]=0xf8;
	deselogo[214]=0xf7;
	deselogo[215]=0x5;
	deselogo[216]=0x7;
	deselogo[217]=0xf8;
	deselogo[218]=0xf7;
	deselogo[219]=0xf7;
	deselogo[220]=0xf7;
	deselogo[221]=0xf7;
	deselogo[222]=0xf7;
	deselogo[223]=0xf7;
	deselogo[224]=0xf8;
	deselogo[225]=0x7;
	deselogo[226]=0x5;
	deselogo[227]=0xf4;
	deselogo[228]=0xf5;
	deselogo[229]=0xf7;
	deselogo[230]=0xf7;
	deselogo[231]=0xf8;
	deselogo[232]=0xf9;
	deselogo[233]=0xf9;
	deselogo[234]=0xf7;
	deselogo[235]=0xf7;
	deselogo[236]=0xf7;
	deselogo[237]=0xf7;
	deselogo[238]=0xf9;
	deselogo[239]=0xfb;
	deselogo[240]=0xff;
	deselogo[241]=0xff;
	deselogo[242]=0xfe;
	deselogo[243]=0xfc;
	deselogo[244]=0xf8;
	deselogo[245]=0x7;
	deselogo[246]=0x8;
	deselogo[247]=0xf7;
	deselogo[248]=0x4;
	deselogo[249]=0x2;
	deselogo[250]=0x2;
	deselogo[251]=0x2;
	deselogo[252]=0x2;
	deselogo[253]=0x4;
	deselogo[254]=0xf7;
	deselogo[255]=0x7;
	deselogo[256]=0x4;
	deselogo[257]=0x2;
	deselogo[258]=0x2;
	deselogo[259]=0x3;
	deselogo[260]=0x2;
	deselogo[261]=0x4;
	deselogo[262]=0xf8;
	deselogo[263]=0x8;
	deselogo[264]=0x4;
	deselogo[265]=0x2;
	deselogo[266]=0x2;
	deselogo[267]=0x5;
	deselogo[268]=0x8;
	deselogo[269]=0xf9;
	deselogo[270]=0xff;
	deselogo[271]=0xff;
	deselogo[272]=0xff;
	deselogo[273]=0xfe;
	deselogo[274]=0xf9;
	deselogo[275]=0x8;
	deselogo[276]=0x8;
	deselogo[277]=0xf7;
	deselogo[278]=0x2;
	deselogo[279]=0x1;
	deselogo[280]=0x2;
	deselogo[281]=0x1;
	deselogo[282]=0x1;
	deselogo[283]=0x2;
	deselogo[284]=0xf7;
	deselogo[285]=0x7;
	deselogo[286]=0x4;
	deselogo[287]=0x2;
	deselogo[288]=0x1;
	deselogo[289]=0x0;
	deselogo[290]=0x1;
	deselogo[291]=0x2;
	deselogo[292]=0xf7;
	deselogo[293]=0x7;
	deselogo[294]=0x2;
	deselogo[295]=0x0;
	deselogo[296]=0x1;
	deselogo[297]=0x2;
	deselogo[298]=0x7;
	deselogo[299]=0xf9;
	deselogo[300]=0xff;
	deselogo[301]=0xff;
	deselogo[302]=0xff;
	deselogo[303]=0xfe;
	deselogo[304]=0xf9;
	deselogo[305]=0x8;
	deselogo[306]=0x8;
	deselogo[307]=0xf7;
	deselogo[308]=0x2;
	deselogo[309]=0x0;
	deselogo[310]=0x1;
	deselogo[311]=0x1;
	deselogo[312]=0x1;
	deselogo[313]=0x2;
	deselogo[314]=0xf7;
	deselogo[315]=0x7;
	deselogo[316]=0x2;
	deselogo[317]=0x1;
	deselogo[318]=0x1;
	deselogo[319]=0x1;
	deselogo[320]=0x2;
	deselogo[321]=0x4;
	deselogo[322]=0xf7;
	deselogo[323]=0x7;
	deselogo[324]=0x2;
	deselogo[325]=0x1;
	deselogo[326]=0x0;
	deselogo[327]=0x2;
	deselogo[328]=0x7;
	deselogo[329]=0xf8;
	deselogo[330]=0xfe;
	deselogo[331]=0xfe;
	deselogo[332]=0xfe;
	deselogo[333]=0xfc;
	deselogo[334]=0xf8;
	deselogo[335]=0x7;
	deselogo[336]=0x8;
	deselogo[337]=0xf7;
	deselogo[338]=0x4;
	deselogo[339]=0x2;
	deselogo[340]=0x2;
	deselogo[341]=0x1;
	deselogo[342]=0x2;
	deselogo[343]=0x4;
	deselogo[344]=0xf8;
	deselogo[345]=0x8;
	deselogo[346]=0x4;
	deselogo[347]=0x2;
	deselogo[348]=0x2;
	deselogo[349]=0x2;
	deselogo[350]=0x2;
	deselogo[351]=0x4;
	deselogo[352]=0xf8;
	deselogo[353]=0x8;
	deselogo[354]=0x4;
	deselogo[355]=0x2;
	deselogo[356]=0x2;
	deselogo[357]=0x4;
	deselogo[358]=0x6;
	deselogo[359]=0xf8;
	deselogo[360]=0xfc;
	deselogo[361]=0xfb;
	deselogo[362]=0xfb;
	deselogo[363]=0xf8;
	deselogo[364]=0xf7;
	deselogo[365]=0x5;
	deselogo[366]=0x7;
	deselogo[367]=0xf8;
	deselogo[368]=0xf8;
	deselogo[369]=0xf7;
	deselogo[370]=0xf7;
	deselogo[371]=0xf7;
	deselogo[372]=0xf7;
	deselogo[373]=0xf8;
	deselogo[374]=0xf8;
	deselogo[375]=0xf9;
	deselogo[376]=0xf8;
	deselogo[377]=0xf7;
	deselogo[378]=0xf7;
	deselogo[379]=0xf5;
	deselogo[380]=0x2;
	deselogo[381]=0x4;
	deselogo[382]=0xf9;
	deselogo[383]=0xf9;
	deselogo[384]=0xf8;
	deselogo[385]=0xf5;
	deselogo[386]=0xf5;
	deselogo[387]=0xf6;
	deselogo[388]=0xf9;
	deselogo[389]=0xf9;
	deselogo[390]=0xfb;
	deselogo[391]=0x9;
	deselogo[392]=0x7;
	deselogo[393]=0x5;
	deselogo[394]=0x4;
	deselogo[395]=0x5;
	deselogo[396]=0x7;
	deselogo[397]=0xf8;
	deselogo[398]=0x8;
	deselogo[399]=0x7;
	deselogo[400]=0x7;
	deselogo[401]=0x7;
	deselogo[402]=0x7;
	deselogo[403]=0x8;
	deselogo[404]=0xfb;
	deselogo[405]=0xb;
	deselogo[406]=0x9;
	deselogo[407]=0x7;
	deselogo[408]=0x7;
	deselogo[409]=0x5;
	deselogo[410]=0x2;
	deselogo[411]=0x4;
	deselogo[412]=0xf8;
	deselogo[413]=0x9;
	deselogo[414]=0x8;
	deselogo[415]=0x7;
	deselogo[416]=0x5;
	deselogo[417]=0x7;
	deselogo[418]=0x9;
	deselogo[419]=0xf9;
	deselogo[420]=0xf9;
	deselogo[421]=0x7;
	deselogo[422]=0x4;
	deselogo[423]=0x2;
	deselogo[424]=0x2;
	deselogo[425]=0x4;
	deselogo[426]=0x7;
	deselogo[427]=0xf8;
	deselogo[428]=0x5;
	deselogo[429]=0x2;
	deselogo[430]=0x2;
	deselogo[431]=0x2;
	deselogo[432]=0x2;
	deselogo[433]=0x5;
	deselogo[434]=0xf8;
	deselogo[435]=0x8;
	deselogo[436]=0x5;
	deselogo[437]=0x1;
	deselogo[438]=0x2;
	deselogo[439]=0x2;
	deselogo[440]=0x1;
	deselogo[441]=0x2;
	deselogo[442]=0xf7;
	deselogo[443]=0x8;
	deselogo[444]=0x4;
	deselogo[445]=0x2;
	deselogo[446]=0x2;
	deselogo[447]=0x4;
	deselogo[448]=0x7;
	deselogo[449]=0xf8;
	deselogo[450]=0xf8;
	deselogo[451]=0x7;
	deselogo[452]=0x4;
	deselogo[453]=0x2;
	deselogo[454]=0x2;
	deselogo[455]=0x4;
	deselogo[456]=0x9;
	deselogo[457]=0xf8;
	deselogo[458]=0x5;
	deselogo[459]=0x2;
	deselogo[460]=0x2;
	deselogo[461]=0x2;
	deselogo[462]=0x2;
	deselogo[463]=0x5;
	deselogo[464]=0xf8;
	deselogo[465]=0x8;
	deselogo[466]=0x5;
	deselogo[467]=0x2;
	deselogo[468]=0x2;
	deselogo[469]=0x1;
	deselogo[470]=0x2;
	deselogo[471]=0x4;
	deselogo[472]=0xf8;
	deselogo[473]=0x8;
	deselogo[474]=0x4;
	deselogo[475]=0x2;
	deselogo[476]=0x2;
	deselogo[477]=0x4;
	deselogo[478]=0x7;
	deselogo[479]=0xf8;
	deselogo[480]=0xf9;
	deselogo[481]=0x8;
	deselogo[482]=0x7;
	deselogo[483]=0x7;
	deselogo[484]=0x7;
	deselogo[485]=0x8;
	deselogo[486]=0xb;
	deselogo[487]=0xfb;
	deselogo[488]=0x9;
	deselogo[489]=0x6;
	deselogo[490]=0x7;
	deselogo[491]=0x7;
	deselogo[492]=0x7;
	deselogo[493]=0x7;
	deselogo[494]=0xf9;
	deselogo[495]=0x9;
	deselogo[496]=0x9;
	deselogo[497]=0x6;
	deselogo[498]=0x7;
	deselogo[499]=0x7;
	deselogo[500]=0x7;
	deselogo[501]=0x8;
	deselogo[502]=0xf9;
	deselogo[503]=0x9;
	deselogo[504]=0x8;
	deselogo[505]=0x7;
	deselogo[506]=0x7;
	deselogo[507]=0x8;
	deselogo[508]=0x8;
	deselogo[509]=0xf9;
	deselogo[510]=0xfb;
	deselogo[511]=0xfb;
	deselogo[512]=0xf9;
	deselogo[513]=0xf9;
	deselogo[514]=0xf9;
	deselogo[515]=0xfb;
	deselogo[516]=0xfe;
	deselogo[517]=0xfc;
	deselogo[518]=0xfb;
	deselogo[519]=0xf9;
	deselogo[520]=0xf9;
	deselogo[521]=0xf9;
	deselogo[522]=0xf9;
	deselogo[523]=0xfb;
	deselogo[524]=0xfb;
	deselogo[525]=0xfb;
	deselogo[526]=0xfb;
	deselogo[527]=0xf9;
	deselogo[528]=0xf9;
	deselogo[529]=0xf9;
	deselogo[530]=0xf9;
	deselogo[531]=0xfb;
	deselogo[532]=0xfc;
	deselogo[533]=0xfc;
	deselogo[534]=0xfb;
	deselogo[535]=0xf9;
	deselogo[536]=0xf9;
	deselogo[537]=0xf9;
	deselogo[538]=0xfb;
	deselogo[539]=0xfb;
	deselogo[540]=0xfe;
	deselogo[541]=0xfe;
	deselogo[542]=0xfe;
	deselogo[543]=0xfe;
	deselogo[544]=0xfe;
	deselogo[545]=0xfe;
	deselogo[546]=0xff;
	deselogo[547]=0xfe;
	deselogo[548]=0xfc;
	deselogo[549]=0xfc;
	deselogo[550]=0xfe;
	deselogo[551]=0xfe;
	deselogo[552]=0xfe;
	deselogo[553]=0xfe;
	deselogo[554]=0xfe;
	deselogo[555]=0xfe;
	deselogo[556]=0xfe;
	deselogo[557]=0xfe;
	deselogo[558]=0xfe;
	deselogo[559]=0xfe;
	deselogo[560]=0xfc;
	deselogo[561]=0xfc;
	deselogo[562]=0xfe;
	deselogo[563]=0xfe;
	deselogo[564]=0xfe;
	deselogo[565]=0xfe;
	deselogo[566]=0xfe;
	deselogo[567]=0xfe;
	deselogo[568]=0xfe;
	deselogo[569]=0xfe;
	deselogo[570]=0xff;
	deselogo[571]=0xff;
	deselogo[572]=0xff;
	deselogo[573]=0xff;
	deselogo[574]=0xff;
	deselogo[575]=0xff;
	deselogo[576]=0xff;
	deselogo[577]=0xff;
	deselogo[578]=0xfe;
	deselogo[579]=0xfe;
	deselogo[580]=0xff;
	deselogo[581]=0xff;
	deselogo[582]=0xff;
	deselogo[583]=0xff;
	deselogo[584]=0xff;
	deselogo[585]=0xff;
	deselogo[586]=0xff;
	deselogo[587]=0xff;
	deselogo[588]=0xff;
	deselogo[589]=0xff;
	deselogo[590]=0xfe;
	deselogo[591]=0xfe;
	deselogo[592]=0xff;
	deselogo[593]=0xff;
	deselogo[594]=0xff;
	deselogo[595]=0xff;
	deselogo[596]=0xff;
	deselogo[597]=0xfe;
	deselogo[598]=0xff;
	deselogo[599]=0xff;
}

void onButtonDown(void)
{
    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4)
    {
        GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);  // Clear interrupt flag
        togglerled();
    }
}

void SW2intinit()
{
	// Pin F4 setup
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);        // Enable port F
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);  // Init PF4 as input
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4,
        GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);  // Enable weak pullup resistor for PF4

    // Interrupt setup
    GPIOIntDisable(GPIO_PORTF_BASE, GPIO_PIN_4);        // Disable interrupt for PF4 (in case it was enabled)
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);      // Clear pending interrupts for PF4
    GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown);     // Register our handler function for port F
    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4,
        GPIO_FALLING_EDGE);             // Configure PF4 for falling edge trigger
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4);
}

void uartintinit(void)
{
    // Set the clocking to run directly from the crystal.
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);

    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Enable the GPIO pins for the LED (PF2).
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    // Enable the peripherals used by this example.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Enable processor interrupts.
    IntMasterEnable();

    // Set GPIO A0 and A1 as UART pins.
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Configure the UART for 115,200, 8-N-1 operation.
    UARTConfigSetExpClk(UART0_BASE, ROM_SysCtlClockGet(), 115200,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));

    // Enable the UART interrupt.
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
}

void UARTIntHandler(void)
{
	static int n=0;
	static int command=0;
    uint32_t ui32Status;
	char ch;
    // Get the interrrupt status.
    ui32Status = UARTIntStatus(UART0_BASE, true);
    // Clear the asserted interrupts.
    UARTIntClear(UART0_BASE, ui32Status);
    // Loop while there are characters in the receive FIFO.
    while(UARTCharsAvail(UART0_BASE))
    {
        // Read the next character from the UART
	    ch = UARTCharGet(UART0_BASE);
		switch(command)
		{
			case 0: if(n==0)
					{
						if(ch=='s')
						{
							command=1;
							toggleled();
						}
						else if(ch=='r')
						{
							command=2;
							n=0;
							while(n<sizex*sizey)
							{
								ch=image[n++];
								UARTCharPut(UART0_BASE,ch);
							}
							command=0;
							n=0;
						}
						else
						{
							command=0;
						}
					}
					else
					{
						//neverhere
					}
					break;

			case 1:	image[n++]=ch;
					if(n==sizex*sizey)
					{
						command=0;
						n=0;
						LCDWriteBmp3x(image,22,10);
						startpredict=1;
					}
					break;

			case 2:	//neverhere
					break;
		}
    }
}

void displaymasterinit()
{
	startpredict=0;
	initdeselogo();
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_4,0xFF);
    GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5,0xFF);
    InitLcd(0);
    LCDClearScreen();
    displayinit();
}

void toggleled()
{
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2, ~GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2));
}

void togglerled()
{
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, ~GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_1));
}
