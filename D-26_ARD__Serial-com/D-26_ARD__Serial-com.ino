/*
 * 2016/03/24 13:23:51
 *   
 */
 
// Toggle LED on pin 13 each second
#include <MsTimer2.h>
#include <LiquidCrystal.h>

char* id = "26 s-1#1 s.1";
char* msg = "Welcome";

LiquidCrystal lcd(7,8,9,10,11,12,13);

/*
 * I/O
 */
int LED_OUT    = 5;  // output
int LED_OUT_2 = 6;  // output
int IO_D_2    = 2;  //  D2  => input, interrupt
int IO_D_4    = 4;  //  D4  => output

int IO_D_0    = 0;  //  D0  => serial receive
int IO_D_1    = 1;  //  D1  => serial send

int pin_intr = 2;    // interrupt

int INTERVAL = 1;   // interval for --> timer interrupt

char num_s[4];      // increment value

char line_2[16];    // LCD 2nd line text

//int count = 0;
//char count = 230;
//char count = 110;
//unsigned char count = 240;
int count = 0;      // incremented thru timer interrupt

int total = 0;

volatile boolean sec_1 = LOW;   // flag --> up when 1 sec passed

//ref http://play-arduino.up.seesaa.net/image/dd22_attachinterrupt_rising.txt
//int pin = 4;  // LED out

volatile int state = LOW;     // on/off state of LED --> i/o interrupt

//int swState;

volatile boolean intr = LOW;

/*
 * funcs
 * 
 *    blink()     i/o interupt
 *    flash()     timer interupt
 * 
 */
void flash() {
//  static boolean output = HIGH;

//  // LED on/off
//  if (count % 10 == 0) {
//
//      digitalWrite(LED_OUT, output);
//  
//      output = !output;
//
//  }
//  digitalWrite(LED_OUT, output);
//  
//  output = !output;

  // display
//  count += 10;
  count += 1;
//  count ++;

  // reset count
  if (count > 999) {    // 1 sec passed
    
    count = 0;
    
    // count up: total
    total ++;
    
    // flag
    sec_1 = HIGH;
    
  }
  
}

void setup() {
  
  // serial com
  _setup__SerialCom();
  
  // pin modes
  _setup__PinMode();
//  pinMode(LED_OUT, OUTPUT);
//  
//  pinMode(LED_OUT_2, OUTPUT);

  // timer
  _setup__Timer();
  
//  MsTimer2::set(INTERVAL, flash); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
//  MsTimer2::start();

  // LCD
  _setup__LCD();

//  //
//  pinMode(pin, OUTPUT);
//  pinMode(pin_intr, INPUT);
//  
  
  // i/o interrupt
  attachInterrupt(0, blink, RISING);

}

void _setup__SerialCom() {
  
  //ref http://siva.cc.hirosaki-u.ac.jp/usr/koyama/semi/06p1254a6.pdf
  Serial.begin(9600);
  
  // opening message
  Serial.println("serial --> beginning...");
  
}

void _setup__Timer() {

    MsTimer2::set(INTERVAL, flash); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
    MsTimer2::start();

}

void _setup__PinMode() {

    pinMode(LED_OUT, OUTPUT);
    
    pinMode(LED_OUT_2, OUTPUT);

    //
//    pinMode(pin, OUTPUT);
    pinMode(IO_D_4, OUTPUT);

    pinMode(pin_intr, INPUT);

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
  
  // flags
  intr = HIGH;

}

void loop() {

  //ref sprintf https://liudr.wordpress.com/2012/01/16/sprintf/
  lcd.setCursor(0,1);

//  sprintf(line_2, "%s %04d", "counting ", count);
  if (sec_1 == HIGH) {

    sec_1 = LOW;
    
    sprintf(line_2, "%04d sec passed", total);
    
  }
//  sprintf(line_2, "%s %03d", "counting ", count);
  
  lcd.print(line_2);

  // interrupt
  if (intr == HIGH) {

    // D_2 => being pushed?
//    while (IO_D_2 == HIGH) {
	while (pin_intr == HIGH) {
      
		LED_OUT = HIGH;
//      IO_D_4 = HIGH;
      
    }
    
    intr = LOW;
    
//    digitalWrite(pin, state);
    digitalWrite(IO_D_4, state);
    
  }
  
}
