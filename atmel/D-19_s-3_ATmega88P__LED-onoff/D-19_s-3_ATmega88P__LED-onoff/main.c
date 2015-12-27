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
         DDRD = 1 << DDD0;        // ポートD0を出力に設定
         PORTD |= 0x01;             // ポートD0に1を出力(LED点灯)
         while(1)
         {
	         for ( i = 0; i < 26500; i++);        // 500ms程度時間待ち
	         PORTD = ~PORTD & 0x01;      // ポートD0の出力を反転
         }
		 
}

