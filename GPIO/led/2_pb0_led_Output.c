#include "NuMicro.h"

int main(void){
	
	GPIO_SetMode(PB, BIT0, GPIO_MODE_OUTPUT);

	while(1){
		int i;
		PB0=1;		for(i=0;i<1000000; i++){}
		PB0=0;		for(i=0;i<1000000; i++){}
	}
}
