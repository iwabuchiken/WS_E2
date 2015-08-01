/*
* File:   D-11-1_PIC16F84A_retry.c
 * Author: iwabuchik
 *
 * Created on
 */

#ifndef XC_H
#define XC_H
#include <xc.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include "pic.h"

#define _XTAL_FREQ 20000000

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config CP = OFF


///////////////////////

// protos

///////////////////////

///////////////////////

// vars

///////////////////////

///////////////////////

// funcs

///////////////////////
void main(void) {

	///////////////////////

	// setups

	///////////////////////
	/****************
	 * OPTION_REG
	 ****************/
	OPTION_REGbits.nRBPU = 0;

	/****************
	 * TRIS
	 ****************/
	TRISB = 0b00000000;		// all output
	TRISA = 0x00000000;		// RA => all output

	/****************
	 * PORT
	 ****************/
	PORTA = 0b00000000;		// initial => no output
	PORTB = 0x00;
//	TRISB = 0x00;	// RB3:output
//
//	PORTB = 0x00;

	///////////////////////////////
	//
	// setup: PORTB
	//
	 ///////////////////////////////

	///////////////////////////////
	//
	// while
	//
	 ///////////////////////////////
	while(1) {

		PORTBbits.RB0 = 0;
		PORTBbits.RB1 = 1;

//		PORTB = 0x01;

		__delay_ms(100);

//		PORTB = 0x02;
//		PORTB = 0x10;

		PORTBbits.RB0 = 1;
		PORTBbits.RB1 = 0;

		__delay_ms(100);

	}//while(1)

	return;

}
