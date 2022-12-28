/*
 * Tarffic Light Control.c
 *
 * Created: 08/10/2022 09:54:40 م
 * Author : Zakaria yahia 
 */ 

#include "std_macros.h"
#include "../MCAL/TIMER0.h"
#include "../HAL/SEVEN_SEG.h"

void Pedestrian_Mode_Event(void);
void Normal_Mode_Event(void);
static void ctc_isr(void);
uint8_t Status,Seconds=10;
uint8_t Green=ON,Red=OFF;
uint8_t pedestrian_int =0;
int main(void)
{
	
    timer0_ctc_isr = ctc_isr;
    TIMER0_CTC_init(OC_Value);
	EXTERNAL_INTERRUPT_init();
    SEVEN_SEG_init();
	
	
	
	DDRB=0xff;
	
    while (1) 
    {
		if(Status!=Pedestrian_Mode)
		{
			
			Normal_Mode_Event();
				
		}
		else
		{
			
			Pedestrian_Mode_Event();
		}
		
		
    }
}


void Pedestrian_Mode_Event(void)
{
	uint8_t flag=0;
	
	if (READBIT(PORTB,Cars_Red_Led)==ON)
	{
		SETBIT(PORTB,Pedestrian_Green_Led);
		SETBIT(PORTB,Cars_Red_Led);
	}
	
	while (Seconds<=5 && flag==0)
	{
		SETBIT(PORTB,Pedestrian_Red_Led);
		
		TOGBIT(PORTB,Cars_Yellow_Led);
		TOGBIT(PORTB,Pedestrian_Yellow_Led);
		_delay_us(300);
		if (Seconds==0){ Seconds=10; }
	}
	
	
	if (Seconds > 5)
	{
		PORTB = 12;
		flag=1;
	}
	while (Seconds<=5 && flag==1)
	{
		CLRBIT(PORTB,Cars_Red_Led);
		
		TOGBIT(PORTB,Cars_Yellow_Led);
		TOGBIT(PORTB,Pedestrian_Yellow_Led);
		SETBIT(PORTB,Pedestrian_Green_Led);
		_delay_us(300);
		
		if(Seconds==0){
			PORTB=OFF;
			pedestrian_int=1;
			flag=0;
			Seconds=10;
			Red=OFF;
			Green=ON;
			Status = Normal_Mode;
		}
		
	}
	
	
}


void Normal_Mode_Event(void)
{
	if ((Green ==ON) && (Seconds>5))
	{
		PORTB = Green_Led;
		while(pedestrian_int!=0 && Seconds>5){ SETBIT(PORTB,Pedestrian_Red_Led); }
	}
	else if ((Seconds <= 5))
	{
		PORTB ^= Yellow_Led;
		_delay_us(300);
		pedestrian_int=0;
		PORTB=OFF;
		if (Green==ON)
		{
			Red=ON;
			Green=OFF;
		}
		else{
			Red=OFF;
			Green=ON;
		}
		
	}
	else if (Red==ON && Seconds>5){ PORTB = Red_Led; }
}

static void ctc_isr(void){
	
	static uint8_t count = 0;
	
		count++;
		if(count == 125)   // for 1 Second
		{   
			
			if (Seconds==0) {Seconds=11; }
			Seconds--;
			count =0;
			
		}
		SEVEN_SEG_write(0,Seconds/10);
		SEVEN_SEG_write(1,Seconds%10);
		if(Status == Pedestrian_Mode)
		{
			
			SEVEN_SEG_write(2,Seconds/10);
			SEVEN_SEG_write(3,Seconds%10);
			
		}
}


ISR(INT1_vect){
	
	if (Status!=Pedestrian_Mode)
	{
		if (READBIT(PORTB,Cars_Red_Led)==ON)
		{
			
			Seconds=10;
			Status=Pedestrian_Mode;
		}
		else if (READBIT(PORTB,Cars_Green_Led)==ON || Seconds<=5)
		{
			
			
			Seconds=5;
			PORTB=OFF;
			Status=Pedestrian_Mode;
		}
	}
	
	
}

