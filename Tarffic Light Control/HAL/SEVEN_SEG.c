/*
 * SEVEN_SEG.c
 *
 * Created: 8/18/2022 8:32:20 PM
 *  Author: Zakaria yahia 
 */ 
#include "SEVEN_SEG.h"

const uint8_t num[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS;
	INIT_SEVEN_SEG_En_PINS;
	PORT_DISABLE_ALL_SS ;
}
void SEVEN_SEG_write(uint8_t en,uint8_t data_in){ 
	 PORT_DISABLE_ALL_SS; 
	 switch(en){
		 case 0:
		 EN0;break;
		 case 1:
		 EN1;break;
		 case 2:
		 EN2;break;
		 case 3:
		 EN3;break;
		 
		
	 }
	 
	 PORT_WRITE = ~ num[data_in];
	 _delay_us(500);
	
	 
	
	
	
	
}

