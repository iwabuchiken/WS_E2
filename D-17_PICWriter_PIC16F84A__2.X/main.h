#ifndef MAIN_H
#define MAIN_H
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
//#pragma config BODEN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage Programming Enable bit (RB3/PGM pin has PGM function, Low-Voltage Programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
//#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#pragma config DEBUG = OFF         // Flash Program Memory Code Protection bit (Code protection off)

//// CONFIG2
//#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
//#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode enabled)

//#pragma config FOSC = HS
//#pragma config WDTE = OFF
//#pragma config PWRTE = ON
//#pragma config CP = OFF

///////////////////////

// vars

///////////////////////
//char msg_Project_Name[]  = "D-116 v-1.1#7";
						//  0123456789012345
char msg_Project_Name[]  = "D-116 v-1.2#1";

					// 01234567890123456
//char msg_Initial[]  = "ddram addressing";
char msg_Initial[]  = "char index";


