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
int LED_OUT_2 = 1;
//int LED_OUT = 13;

int INTERVAL = 1000;

int INTERVAL_2 = 1500;

static boolean output = HIGH;


void flash() {
//  static boolean output = HIGH;

  digitalWrite(LED_OUT, output);
  
  output = !output;
  
}

void flash_2() {
//  static boolean output = HIGH;

  digitalWrite(LED_OUT_2, output);
  
  output = !output;
  
}

void setup() {
  pinMode(LED_OUT, OUTPUT);
  
  pinMode(LED_OUT_2, OUTPUT);

  MsTimer2::set(INTERVAL, flash); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
  MsTimer2::start();

  // OUT_2
  MsTimer2::set(INTERVAL_2, flash_2); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
  MsTimer2::start();

  
}

void loop() {

  
}

