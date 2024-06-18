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
	RS=0; RW=0;	PA->DOUT=0x38;
	E=0; delay(0);
	E=1; delay(500); //CPU defualt 12M Hz 速度太快需要delay datasheet tells at last 230ns delay
	
	RS=0; RW=0;	PA->DOUT=0x0E;
	E=0; delay(0);
	E=1; delay(500);
	
	RS=0; RW=0;	PA->DOUT=0x06;
	E=0; delay(0);
	E=1; delay(500);
	
	RS=1; RW=0;	PA->DOUT=0x48;
	E=0; delay(0);
	E=1; delay(500);

	while(1){
	}
}
