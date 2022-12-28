/*
 * EXTERNAL_INTERRUPT.c
 *
 * Created: 08/10/2022 11:09:43 م
 *  Author: Zakaria yahia
 */ 
#include "EXTERNAL_INTERRUPT.h"

void EXTERNAL_INTERRUPT_init(void)
{
	CLRBIT(DDRD,3); 
	SETBIT(PORTD,3); // pull up
	
	SETBIT(MCUCR,3); // falling edge
	SETBIT(MCUCR,2); 
	
	SETBIT(GICR,7);
	
	SETBIT(SREG,7); //Enable global int
	
}