/*
 * File:   D-116_v_1_0.c
 * Author: iwabuchik
 *
 * Created on 31/01/2015 08:49:28
 */

#ifndef XC_H
#define XC_H
#include <xc.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#ifndef MAIN_H
#include "main.h"
#endif



///////////////////////

// protos

///////////////////////
void _Setup(void);

void _While(void);

///////////////////////

// vars

///////////////////////

///////////////////////

// funcs

///////////////////////
void main(void) {

    
				//  0123456789012345
//	char msg_1[] = "ddram addressing";
//	char msg_1[] = "display 0x02...";
//	char msg_1[] = "register done";
//	char msg_1[] = "register_Char";

	///////////////////////

	// setups

	///////////////////////
	_Setup();			// init MCU

	///////////////////////
	while(1) {

		_While();

	}//while(1)

	return;
}

void _Setup(void) {

	/****************
	 * OPTION_REG
	 ****************/
	OPTION_REGbits.nRBPU = 0;

	/****************
	 * TRIS
	 ****************/
	TRISA = 0x00000000;		// RA => all output
	TRISB = 0b00000000;		// RB0 => input

	/****************
	 * PORT
	 ****************/
	PORTA = 0b00000000;		// initial => no output, no input
	PORTB = 0x00;

}//_Setup

void
_While(void) {

	PORTB = 0x00;
//	PORTB = 0x01;
	PORTA = 0x01;

	__delay_ms(500);

	PORTB = 0x03;
//	PORTB = 0x02;
	PORTA = 0x02;

	__delay_ms(500);

}//_While
