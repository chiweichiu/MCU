#include "NuMicro.h"

void delay(uint32_t n){
	volatile uint32_t i;
	for(i=0;i<n;i++){}
}

int main(void){
	GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT14+BIT15, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PA, BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7, GPIO_MODE_OUTPUT);
	GPIO_ENABLE_DOUT_MASK(PA, 0xFF00);
	//---
	#define RS PC14
	#define RW PB14
	#define E  PB15
	#define TA 0
	#define TB 500
	//E=0;
	delay(1000000);
	
	RS=0; RW=0;	PA->DOUT=0x38;
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=0; RW=0;	PA->DOUT=0x0E;
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=0; RW=0;	PA->DOUT=0x06;
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=0; RW=0;	PA->DOUT=0x80;
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=1; RW=0;	PA->DOUT='H';
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=1; RW=0;	PA->DOUT='E';
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=1; RW=0;	PA->DOUT='L';
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=1; RW=0;	PA->DOUT='L';
	E=1; delay(TA);
	E=0; delay(TB);
	
	RS=1; RW=0;	PA->DOUT='O';
	E=1; delay(TA);
	E=0; delay(TB);

	while(1){
	}
}
