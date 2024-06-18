#include "NuMicro.h"

int main(void){
	
	GPIO_SetMode(PB, BIT0, GPIO_MODE_OUTPUT);
	GPIO_SetMode(PA, BIT15, GPIO_MODE_INPUT);

	while(1){
		uint8_t r;
		r =PA15;
		PB0=r;
	}
}
