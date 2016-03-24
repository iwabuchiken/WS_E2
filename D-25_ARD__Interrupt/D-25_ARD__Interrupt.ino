/*
 * 2016/03/24 13:23:51
 *   
 */
 
// Toggle LED on pin 13 each second
#include <MsTimer2.h>
#include <LiquidCrystal.h>

char* id = "25 s-1#2 s.2";
char* msg = "Welcome";

LiquidCrystal lcd(7,8,9,10,11,12,13);

/*
 * I/O
 */
int LED_OUT = 0;
int LED_OUT_2 = 1;

//int INTERVAL = 1000;
int INTERVAL = 100;


int INTERVAL_2 = 1500;

char num_s[4];

char line_2[16];

//int count = 0;
//char count = 230;
//char count = 110;
unsigned char count = 240;

static boolean output = HIGH;

//ref http://play-arduino.up.seesaa.net/image/dd22_attachinterrupt_rising.txt
int pin = 4;  // LED out
volatile int state = LOW;
int swState;

/*
 * funcs
 * 
 */
void flash() {
//  static boolean output = HIGH;

  // LED on/off
  if (count % 10 == 0) {

      digitalWrite(LED_OUT, output);
  
      output = !output;

  }
//  digitalWrite(LED_OUT, output);
//  
//  output = !output;

  // display
  count ++;
  
}

void setup() {
  pinMode(LED_OUT, OUTPUT);
  
  pinMode(LED_OUT_2, OUTPUT);

  MsTimer2::set(INTERVAL, flash); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
  MsTimer2::start();

  // LCD
  _setup__LCD();

  //
  pinMode(pin, OUTPUT);
  attachInterrupt(0, blink, RISING);

}

void _setup__LCD() {
  
  lcd.begin(16, 2);//16x2桁
  
  delay(100);
  lcd.clear();
   
//  lcd.print("D-24 s-1#1.3-1");
  lcd.print(id);
  lcd.setCursor(0,1);
//  lcd.print("welcome");
  lcd.print(msg);

  
}

void blink()
{
  
  state = !state;

}

void loop() {

  //ref sprintf https://liudr.wordpress.com/2012/01/16/sprintf/
  lcd.setCursor(0,1);

  sprintf(line_2, "%s %03d", "counting ", count);
  
  lcd.print(line_2);

  // interrupt
  digitalWrite(pin, state);
  
}




