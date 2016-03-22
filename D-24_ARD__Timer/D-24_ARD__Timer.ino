/*
 * ref http://happy-arduino.blogspot.jp/2012/08/blog-post_9.html
 * 
 * 2016/03/22 15:24:40
 * 
 */
 
//#include <MsTimer2.h>

// Toggle LED on pin 13 each second
#include <MsTimer2.h>

int LED_OUT = 0;
//int LED_OUT = 13;

int INTERVAL = 1000;

static boolean output = HIGH;


void flash() {
//  static boolean output = HIGH;

  digitalWrite(LED_OUT, output);
  
  output = !output;
  
}

void setup() {
  pinMode(LED_OUT, OUTPUT);

  MsTimer2::set(INTERVAL, flash); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
  MsTimer2::start();

}

void loop() {

  
}

