/*
 * AVR INTERRUPT.cpp
 *
 * Created: 6/23/2017 1:53:59 PM
 * Author : Anh Khoa
 */ 

#include <avr/io.h>
#define F_CPU 8000000
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0xff;
	PORTA = 0x00;
	PORTA |= (1 << 1);
	
	DDRD = 0x00;
	
	GICR |= (1 << INT0) | (1 << INT1); // Enable INT0 & INT1
	MCUCR |= (1 << ISC01) | (1 << ISC11);
	
	sei();
    while (1) 
    {
    }
}

ISR(INT0_vect)
{
	PORTA ^= (1 << 0);
}

ISR(INT1_vect)
{
	PORTA ^= ((1 << 1) | (1 << 2));
}