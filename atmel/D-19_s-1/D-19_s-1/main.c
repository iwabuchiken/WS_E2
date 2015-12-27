/*
 * D-19_s-1.c
 *
 * Created: 2015/12/23 14:07:56
 * Author : kbuchi
 */ 
#define	F_CPU	1000000UL	//1MHz

#include <avr/io.h>
#include	<util/delay.h>
//#include "avr/iom328p.h"

int main(void)
{
	int	i;
	unsigned char	x = 0x00;

	DDRB	= 0b00000111;	//LEDが3個
	//PORTA	= 0b00000011;	//スイッチが2個

	for (i = 0; i < 10; i++)
	{
		PORTB = 0b00000111;
		_delay_ms(200);
	
		PORTB = 0b00000000;
		_delay_ms(200);
	}

	while (1)
	{
		//x = PINA;
		x = (~x) & 0b00000011;
		PORTB = x;
	}
}

