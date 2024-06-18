#include "NuMicro.h"

#define RS PC14
#define RW PB14
#define E  PB15
#define TA 0
#define TB 500

void delay(uint32_t n){
	uint32_t i;
	for(i=0;i<n;i++){}
}

void lcd_cmd(char c){
	RS=0; RW=0;
	PA->DOUT=c;
	E=1; delay(TA);
	E=0; delay(TB);
}

void lcd_put(char c){
	RS=1; RW=0;
	PA->DOUT=c;
	E=1; delay(TA);
	E=0; delay(TB);
}

void lcd_print(uint8_t pos, char *p){
	lcd_cmd(0x80 | pos);
	while(*p){
		lcd_put(*p++);
	}
}

void lcd_init(void){
	GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PB, BIT14+BIT15, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PA, BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7, GPIO_MODE_OUTPUT);
	GPIO_ENABLE_DOUT_MASK(PA, 0xFF00);
	//--- STEP 1
	delay(1000000);// MCU等LCD初始化完成 找臨界值+buffer
	//--- STEP 2
	lcd_cmd(0x38);
	//--- STEP 3
	lcd_cmd(0x0E);
	//--- STEP 4
	lcd_cmd(0x06);
	//--- STEP 4.5
	lcd_cmd(0x80);
	lcd_print(0x00, "                ");
	lcd_print(0x40, "                ");
}


int main(void){
	

	lcd_init();
	lcd_print(0x00, "  LCD1602 DEMO  ");

	while(1){
	}
}
