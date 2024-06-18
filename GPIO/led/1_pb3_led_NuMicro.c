#include "NuMicro.h"

int main(void){
	
	PB->MODE = (1<<0);
	PB->MODE = (1<<2);
	
	PB->MODE &= ~(3<<6);
	PB->MODE |=  (1<<6);

	while(1){
	}
}
