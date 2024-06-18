#include "NuMicro.h"

int main(void){
	//--- mode setting
	GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT14+BIT15, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PA, BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7, GPIO_MODE_OUTPUT);
	GPIO_ENABLE_DOUT_MASK(PA, 0xFF00);
	//--- 2 line display init
	#define RS PC14
	#define RW PB14
	#define E  PB15
	RS=0; RW=0;	PA->DOUT=0x38;
	E=0;
	E=1;
	
	RS=0; RW=0;	PA->DOUT=0x0E;
	E=0;
	E=1;
	
	RS=0; RW=0;	PA->DOUT=0x06;
	E=0;
	E=1;
	//--- show 'H'
	RS=1; RW=0;	PA->DOUT=0x48;
	E=0;
	E=1;

	while(1){
	}
}
