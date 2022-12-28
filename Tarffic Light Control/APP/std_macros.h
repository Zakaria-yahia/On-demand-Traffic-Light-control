/*
 * std_macros.h
 *
  *
  * Created: 22/08/2022 01:57:47 Õ
  * Author : Zakaria yahia
  */


#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 16000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms
#include <avr/interrupt.h> // this header is necessary when you deal with interrupt

#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

#define OC_Value              124            // for interrupt 251 every 1s
#define Pedestrian_Mode        1
#define Normal_Mode            0
#define Cars_Green_Led         0
#define Cars_Yellow_Led        1
#define Cars_Red_Led           2
#define Pedestrian_Green_Led   3
#define Pedestrian_Yellow_Led  4
#define Pedestrian_Red_Led     5
#define Green_Led              1
#define Yellow_Led             2
#define Red_Led                4
#define ON                     1
#define OFF                    0

#endif /* STD_MACROS_H_ */