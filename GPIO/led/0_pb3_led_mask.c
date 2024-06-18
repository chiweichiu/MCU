typedef volatile struct{
	unsigned int MODE;
	unsigned int DINOFF;
	unsigned int DOUT;
	unsigned int DATMSK;
	unsigned int PIN;
	unsigned int DBEN;
	unsigned int INTTYPE;
	unsigned int INTEN;
	unsigned int INTSRC;
	unsigned int SMTEN;
	unsigned int SLEWCTL;
	unsigned int PUSEL;
} TPGPIO;

#define GPIOB    ((TPGPIO *)0x40004040)

int main(void){
	
	//DOUT : defalt value is 0xf
	GPIOB->MODE = (1<<0);
	GPIOB->MODE = (1<<2);
	
	GPIOB->MODE = (2<<6);	
	GPIOB->MODE |= 0x04;
	
	
	GPIOB->MODE |=  (1<<6);
	
	GPIOB->MODE &= ~(3<<6);
	GPIOB->MODE |=  (1<<6);

	while(1){
	}
}
