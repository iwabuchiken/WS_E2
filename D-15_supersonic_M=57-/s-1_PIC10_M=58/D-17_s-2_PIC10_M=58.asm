list		p=10f200
#include	<p10f200.inc>

__CONFIG	_CP_OFF & _WDT_OFF & _MCLRE_OFF & _IntRC_OSC

CNT1	EQU		0x10
CNT2	EQU		0x11
CNT3	EQU		0x12

		ORG		0x00
		
		movwf	OSCCAL
		bcf		OSCCAL,FOSC4
		
		;GPIO 0
		movlw	b'11111110'	;GPIO 0 => output
		TRIS	GPIO

main_loop

		bsf		GPIO,0
		;call	DLY_1S
		CALL	DLY_Xms
		
		bcf		GPIO,0
		call	DLY_1S
		
		goto	main_loop
		
;=========================== DLY_1S
;{
DLY_1S;	1 sec

		;movlw	d'10'
		movlw	d'5'
		movwf	CNT3
		
DLY_100

		movlw	d'100'
		movwf	CNT1
		
DLP1

		movlw	d'200'
		movwf	CNT2
		
DLP2

		nop
		nop
		
		decfsz	CNT2,f
		goto	DLP2
		
		decfsz	CNT1,f
		goto	DLP1
		
		decfsz	CNT3,f
		goto	DLY_100
		
		retlw	0
		
;}

;=========================== DLY_Xms
;{
DLY_Xms
		MOVLW	d'64'	; 64 mill seconds
		MOVWF	CNT1
	
	
;}

;=========================== DLY_1ms
;{
DLY_1ms	;	1 mill seconds

		MOVLW	d'200'
		MOVWF	CNT2
		
DLY_5us	;	5 micro seconds

		NOP
		NOP
		DECFSZ	CNT2,f
		
		GOTO	DLY_5us
		
		DECFSZ	CNT1,f
		
		GOTO	DLY_1ms

;}
		
;=========================== END

		END