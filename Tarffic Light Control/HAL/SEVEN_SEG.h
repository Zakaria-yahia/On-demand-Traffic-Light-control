/*
 * SEVEN_SEG.c
 *
 * Created: 8/18/2022 8:32:20 PM
 *  Author: Zakaria yahia 
 */ 



#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "..\APP\std_macros.h"

#define INIT_SEVEN_SEG_PINS DDRC |= 0xff;
#define INIT_SEVEN_SEG_En_PINS DDRA |= 0x0f;
#define PORT_DISABLE_ALL_SS PORTA &= 0xf0;
void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t , uint8_t);



#define EN0 SETBIT(PORTA,0); 
#define EN1 SETBIT(PORTA,1); 
#define EN2 SETBIT(PORTA,2); 
#define EN3 SETBIT(PORTA,3);



#define PORT_WRITE PORTC


#endif /* SEVEN_SEG_H_ */