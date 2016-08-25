/*
 * ref http://happy-arduino.blogspot.jp/2012/08/blog-post_9.html
 * 
 * 2016/08/25 17:32:41
 * 
 */
 
// Toggle LED on pin 13 each second
#include <MsTimer2.h>
//#include <LiquidCrystal.h>

char* id = "38 s-3#1 steps.3";
char* msg = "Welcome";

//LiquidCrystal lcd(7,8,9,10,11,12,13);
//
//int LED_OUT = 0;
//int LED_OUT_2 = 1;
////int LED_OUT = 13;

int INTERVAL = 1000;
//int INTERVAL = 100;

int count = 0;

//int INTERVAL_2 = 1500;
//
//char num_s[4];
//
char line_2[30];

void timer_intr() {

  // disp: time
  count += 1;

  sprintf(line_2, "[%07ld] %s => %03d", millis(), "count", count);
//  sprintf(line_2, "[%06ld] %s => %03d", millis(), "count", count);
//  sprintf(line_2, "[%d] %s => %03d", millis(), "count", count);
//  sprintf(line_2, "%s => %03d", "count", count);
  
  Serial.println(line_2);

}

void setup() {

  /*
   * setup: serial
   */
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }

    /*
     * opening message
     */
    Serial.print(msg);
    Serial.print(": ");
    Serial.println(id);
    
    Serial.println("");
    
    
    /*
     * timer
     */
    _setup_Timer2();
//  MsTimer2::set(INTERVAL, timer_intr); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
//  MsTimer2::start();

}//void setup()

void _setup_Timer2() {

    MsTimer2::set(INTERVAL, timer_intr); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
    MsTimer2::start();

}//_setup_Timer2()

void loop() {

//  //ref sprintf https://liudr.wordpress.com/2012/01/16/sprintf/
//  lcd.setCursor(0,1);
////  sprintf(line_2, "%s %02d", "counting...", count);
//  sprintf(line_2, "%s %03d", "counting ", count);
//  
//  lcd.print(line_2);
  
}







