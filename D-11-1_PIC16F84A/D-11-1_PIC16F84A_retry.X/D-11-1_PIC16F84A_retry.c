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

//#include <stdio.h>
//#include <stdlib.h>

//#include "pic.h"

//#define _XTAL_FREQ 20000000
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif


// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
//#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)

#pragma config PWRTE = ON, MCLRE = ON       // Power-up Timer Enable bit (PWRT enabled)
//#pragma config PWRTE = ON, MCLRE = ON       // Power-up Timer Enable bit (PWRT enabled)
//#pragma config MCLR = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
//#pragma config EXTMCLR = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
//#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)

#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
//#pragma config BODEN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage Programming Enable bit (RB3/PGM pin has PGM function, Low-Voltage Programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
//#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#pragma config DEBUG = OFF         // Flash Program Memory Code Protection bit (Code protection off)

//#pragma config FOSC = HS
//#pragma config WDTE = OFF
//#pragma config PWRTE = ON
//#pragma config CP = OFF


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

		__delay_ms(500);

//		PORTB = 0x02;
//		PORTB = 0x10;

		PORTBbits.RB0 = 1;
		PORTBbits.RB1 = 0;

		__delay_ms(100);

	}//while(1)

	return;

}
