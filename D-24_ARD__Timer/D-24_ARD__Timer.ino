/*
 * ref http://happy-arduino.blogspot.jp/2012/08/blog-post_9.html
 * 
 * 2016/03/22 15:24:40
 * 
 */
 
// Toggle LED on pin 13 each second
#include <MsTimer2.h>
#include <LiquidCrystal.h>

char* id = "24 s-1#1.3-3";
char* msg = "Welcome";

LiquidCrystal lcd(7,8,9,10,11,12,13);

int LED_OUT = 0;
int LED_OUT_2 = 1;
//int LED_OUT = 13;

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


void flash() {
//  static boolean output = HIGH;

  digitalWrite(LED_OUT, output);
  
  output = !output;

  // display
  count ++;
  
//  lcd.setCursor(0,1);
////  lcd.print("counting... " + itoa(count, num_s, 10));
//
//  sprintf(line_2, "%s %02d", "counting...", count);
//  
////  lcd.print(line_2);
//  lcd.print("counting...");

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

//  // OUT_2
//  MsTimer2::set(INTERVAL_2, flash_2); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
//  MsTimer2::start();

  // LCD
  _setup__LCD();
  
  
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

void loop() {

  // LCD
//  lcd.clear();

  lcd.setCursor(0,1);
//  sprintf(line_2, "%s %02d", "counting...", count);
  sprintf(line_2, "%s %03d", "counting ", count);
  
  lcd.print(line_2);
  
//  if (count % 5 == 0) {
//
//      lcd.setCursor(0,1);
//    //  lcd.print("counting... " + itoa(count, num_s, 10));
//    
//      sprintf(line_2, "%s %02d", "counting...", count);
//      
//      lcd.print(line_2);
////      lcd.print("counting...");
//
//  }
  
}


