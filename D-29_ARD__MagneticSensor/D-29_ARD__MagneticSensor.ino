/*
 * 2016/05/03 14:04:58
 *   
 *   <i/o>
 *   D0,D1      serial com
 *   D2         InfraRed receive
 *   D4,5,6     output
 *   
 *   <description>
 *   - switch on/of      --> begin/end serial com
 *   - timer interrupt    --> count seconds
 *   
 *   <bear in mind>
 *   - D0,1       => used for serial in/out
 *   
 *   <remarks>
 *   - chattering protection for i/o interrupt    => not coded
 *   
 *   <loop>
 *     _loop__Serial()
 *    %04d secs %s
 *    if (intr == HIGH)
 *    _loop__Sensor()
 *    _loop__InfraRed()
 *    
 *    <funcs>
 *    flash()       => timer interrupt
 */
 
// Toggle LED on pin 13 each second
#include <MsTimer2.h>
#include <LiquidCrystal.h>

/*
 *    defines
 */
#define IRPIN       2
//#define DATA_POINT  5

char* id = "29 5#1 s.5.2";
char* msg = "Welcome";

LiquidCrystal lcd(7,8,9,10,11,12,13);

/****************************
 * I/O
 ****************************/
int LED_OUT    = 5;  // output
int LED_OUT_2 = 6;  // output
//int IO_D_2    = 2;  //  D2  => input, interrupt
int IO_D_4    = 4;  //  D4  => output

int IO_D_0    = 0;  //  D0  => serial receive
int IO_D_1    = 1;  //  D1  => serial send

int sensorPin = A0;   // analog pin 0
int sensorValue = 0;

int pin_intr = 2;    // interrupt

int pin_AttachInterrupt = 3;    // attach interrupt

/****************************
 *    vars
 ****************************/
unsigned long t ;
int i , cnt ;
char IRbit[64] ;
     
char str_temp[6];    // dtostrf(temp, 4, 2, str_temp);

float temp;

int INTERVAL = 1;   // interval for --> timer interrupt

char num_s[4];      // increment value

char line_2[16];    // LCD 2nd line text

//int count = 0;
//char count = 230;
//char count = 110;
//unsigned char count = 240;
int count = 0;      // incremented thru timer interrupt

int total = 0;

/*
 *     flags
 */
volatile boolean sec_1 = LOW;   // flag --> up when 1 sec passed
volatile boolean f_intr_2 = LOW;   // flag --> up when 1 sec passed

//ref http://play-arduino.up.seesaa.net/image/dd22_attachinterrupt_rising.txt
//int pin = 4;  // LED out

volatile int state = LOW;     // on/off state of LED --> i/o interrupt

//int swState;

volatile boolean intr = LOW;

char serial_receive_char[1];

//char remocon_values[4][2];
char remocon_values[5][2];

char remocon_values_str[9];

/*****************************
 * funcs
 * 
 *    blink()     i/o interupt    pin 2
 *    intr_2()     i/o interupt   pin 3
 *    flash()     timer interupt
 * 
 ****************************/
void DspData(int num,char *data)
{
     int i , j , x , dt ;
     
      Serial.print(data) ;    // ビットデータで表示
      Serial.write(" ( ") ;
      x = num / 8 ;
      
//      //debug
//      Serial.println("x = ") ;
//      Serial.println(x) ;      //=> 4
//      
//      Serial.println("num = ") ;
//      Serial.println(num) ;   //=> 32
      
      // ビット文字列データから数値に変換する
      for (j=0 ; j < x ; j++) {
           dt = 0 ;
           
           for (i=0 ; i < 8 ; i++) {
                if (*data++ == 0x31) bitSet(dt,i) ;  // 0x31 --> '1' //ref http://web.cs.mun.ca/~michael/c/ascii-table.html
           }
           
           Serial.print(dt,HEX) ; // ＨＥＸ(16進数)で表示
           Serial.write(' ') ;
      
           // sprintf
           sprintf(remocon_values[j], "%02x", dt);
//           sprintf(remocon_values[j], "%x", dt);
           
      }
      
      Serial.println(')') ;     
      
      //debug
      for (j=0 ; j < x ; j++) {
        
        Serial.print("remocon_values: ") ;
        Serial.print(j) ;
        Serial.print(" / ");
        Serial.print(remocon_values[j]);
        
        Serial.print(" ");
        
      }
      
//      Serial.print("data is ...: '") ;
//      Serial.print(data) ;
//      Serial.print("'") ;
      
}//DspData

float modTemp(int analog_val){
  
    float v  = 5;       // vref
//    float tempC = ((v * analog_val) / 1024) * 100;    // conv => celsius
    float tempC = ((v * analog_val) / 1024);    // conv => up to 5

    return tempC;
  
 }

 /*
  * timer interrupt 
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

void _setup__Init_RemoconValues() {
  
  int k = 0;
  
  for (k = 0; k < 4; k ++) {
    
//    remocon_values[k] = " ";
//    sprintf(remocon_values[k], "%s", " ");
    sprintf(remocon_values[k], "%d%d", k,k);
    
  }
  
  // string end
  
  remocon_values[4][0] = '\0';
  
  // debug
  Serial.println("\n_setup__Init_RemoconValues --> done\n");

  sprintf(remocon_values_str, "%s%s%s%s", 
      remocon_values[0], remocon_values[1], 
      remocon_values[2], remocon_values[3]);
  
  remocon_values_str[8] = '\0';
  
  Serial.println("remocon_values_str => ");
  Serial.println(remocon_values_str);
  
}//_setup__Init_RemoconValues()

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
  attachInterrupt(digitalPinToInterrupt(3), intr_2, RISING);  //
//  attachInterrupt(digitalPinToInterrupt(1), intr_2, RISING);  //
  
//  attachInterrupt(digitalPinToInterrupt(0), blink, RISING); //=> w.
//  attachInterrupt(0, blink, RISING);

  // init: remocon_values
  _setup__Init_RemoconValues();
  
}


void _setup__SerialCom() {
  
  //ref http://siva.cc.hirosaki-u.ac.jp/usr/koyama/semi/06p1254a6.pdf
  Serial.begin(9600);
  
  // opening message
  Serial.println(id);
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

    // infra red
    pinMode(IRPIN,INPUT) ;
    
    // attach interrupt
    pinMode(pin_AttachInterrupt, INPUT) ;
    
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

void intr_2() {
  
  Serial.println("intr_2");
  
  // set flag
  f_intr_2 = HIGH;
  
  Serial.println("f_intr_2 => HIGH");
  
}//intr_2

void blink()
{
  
  state = !state;
  
  // flags
  intr = HIGH;

}

void _loop__Serial() {
  
  char chr;
  
  if(Serial.available()>0) {

    Serial.write("Receive --> starting");

    Serial.write('\n');
    
    chr = Serial.read();
    
    while (chr != -1) {

      sprintf(serial_receive_char, "%d", chr);
//      sprintf(serial_receive_char, "%c", chr);
            
      Serial.write(serial_receive_char);
//      Serial.write(chr);
      Serial.write("*");
      
      // new char
      chr = Serial.read();
      
    }
    
    Serial.write('\n');
    
    Serial.write("Receive --> done");
    
    Serial.write('\n');
    
  }//if(Serial.available()>0)
  
}

void _loop__Sensor() {
  
  sensorValue = analogRead(sensorPin);    //アナログ0番ピンからの入力値を取得
  
  temp  = modTemp(sensorValue);     //温度センサーからの入力値を変換
//  float temp  = modTemp(sensorValue);     //温度センサーからの入力値を変換
  
//  Serial.println(temp);                   //結果をシリアルモニタに表示
//  
//  delay(500); 
  
//  Serial.println("sensor => done");
  
}//_loop__Sensor()

void _loop__InfraRed() {

    t = 0 ;
    if (digitalRead(IRPIN) == LOW) {
      
//      Serial.println("DEBUG: IRPIN --> LOW");
      
         // リーダ部のチェックを行う
         t = micros() ;                          // 現在の時刻(us)を得る
         while (digitalRead(IRPIN) == LOW) ;  // HIGH(ON)になるまで待つ
         t = micros() - t ;         // LOW(OFF)の部分をはかる
    }
    // リーダ部有りなら処理する(3.4ms以上のLOWにて判断する)
    if (t >= 3400) {
         i = 0 ;
         while(digitalRead(IRPIN) == HIGH) ;  // ここまでがリーダ部(ON部分)読み飛ばす
         // データ部の読み込み
         while (1) {
              while(digitalRead(IRPIN) == LOW) ;  // OFF部分は読み飛ばす
              t = micros() ;
              cnt = 0 ;
              while(digitalRead(IRPIN) == HIGH) {// LOW(OFF)になるまで待つ
                   delayMicroseconds(10) ;
                   cnt++ ;
                   if (cnt >= 1200) break ;   // 12ms以上HIGHのままなら中断
              }
              t = micros() - t ;
              if (t >= 10000) break ;     // ストップデータ
              if (t >= 1000)  IRbit[i] = (char)0x31 ; // ON部分が長い
              else            IRbit[i] = (char)0x30 ; // ON部分が短い
              i++ ;
         }
         
         // データ有りなら表示を行う
         if (i != 0) {
              IRbit[i] = 0 ;
              DspData(i,IRbit) ;
         }
         
    }
  
}//_loop__InfraRed

void _loop__Interupt_Pin() {

  // flag => HIGH?
  if(f_intr_2 == HIGH) {
  
    Serial.println("intr_2 => detected") ;    // ビットデータで表示
//    Serial.print("\n") ;
//      Serial.write(" ( ") ;
  
    // wait
//    while (digitalRead(pin_intr) == HIGH) {
//      
//      Serial.println("digitalRead(pin_intr) => HIGH");
//      
//    }
    
    
    // reset: flag
    f_intr_2 = LOW;
        
    Serial.println("f_intr_2 => LOW");
    
  }

  //test
  if (digitalRead(pin_AttachInterrupt) == HIGH) {
//    if (digitalRead(pin_intr) == HIGH) {
  
    Serial.println("digitalRead(pin_AttachInterrupt) => HIGH");
//    Serial.println("digitalRead(pin_intr) => HIGH");
  
  }

  
}

void loop() {

    //ref sprintf https://liudr.wordpress.com/2012/01/16/sprintf/
    lcd.setCursor(0,1);

    if (sec_1 == HIGH) {

      sec_1 = LOW;

      //ref http://stackoverflow.com/questions/27651012/arduino-sprintf-float-not-formatting answered Dec 26 '14 at 1:22
      //ref http://www.hobbytronics.co.uk/arduino-float-vars "An example will serve to illustrate the behaviour"
      dtostrf(temp, 6,3, str_temp);
      
      sprintf(line_2, "%04d %c%c%c%c %s", 
          total,
          remocon_values[2][0],
          remocon_values[2][1],
          remocon_values[3][0],
          remocon_values[3][1],
          str_temp);

      // serial
      Serial.println(line_2);

      
    }
    
    lcd.print(line_2);

    // sensor
    _loop__Sensor();

    // infra red
    _loop__InfraRed();
  
    // pin interrupt
    _loop__Interupt_Pin();
    
}//loop()







