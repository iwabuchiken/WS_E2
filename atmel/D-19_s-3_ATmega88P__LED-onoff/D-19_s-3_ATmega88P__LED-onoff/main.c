/*
 * D-19_s-3_ATmega88P__LED-onoff.c
 *
 * Created: 2015/12/27 8:52:29
 * Author : kbuchi
 */ 

#include <avr/io.h>


int main(void)
{
         uint16_t i;
         DDRD = 1 << DDD0;        // �|�[�gD0���o�͂ɐݒ�
         PORTD |= 0x01;             // �|�[�gD0��1���o��(LED�_��)
         while(1)
         {
	         for ( i = 0; i < 26500; i++);        // 500ms���x���ԑ҂�
	         PORTD = ~PORTD & 0x01;      // �|�[�gD0�̏o�͂𔽓]
         }
		 
}

