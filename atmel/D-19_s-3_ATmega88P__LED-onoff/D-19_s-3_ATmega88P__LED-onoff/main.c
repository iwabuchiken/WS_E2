/*
 * D-19_s-3_ATmega88P__LED-onoff.c
 *
 * Created: 2015/12/27 8:52:29
 * Author : kbuchi
 */ 

//#define F_CPU 8000000UL


#include <avr/io.h>

int main(void) {

	DDRB =0b11111111;

	PORTB=0b00000001;

}