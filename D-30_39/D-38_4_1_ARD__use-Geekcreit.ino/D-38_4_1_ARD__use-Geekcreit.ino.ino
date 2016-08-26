/*
 * ref http://happy-arduino.blogspot.jp/2012/08/blog-post_9.html
 * 
 * 2016/08/25 17:32:41
 * 
 */
 
// Toggle LED on pin 13 each second
#include <MsTimer2.h>
//#include <LiquidCrystal.h>

#include <SPI.h>
#include <SD.h>

char* id = "38 s-4#1 steps.1";
char* msg = "Welcome";

Sd2Card card;
SdVolume volume;
SdFile root;

File myFile;

char* fname = "20160826.txt";

//LiquidCrystal lcd(7,8,9,10,11,12,13);
//
//int LED_OUT = 0;
//int LED_OUT_2 = 1;
////int LED_OUT = 13;

int INTERVAL = 1000;
//int INTERVAL = 100;

int count = 3600;
//int count = 0;

int sensorValue = 0;

char line_2[30];
char clocl_label[10];

/*
 * pins
 */
int sensorPin = A0;   // analog pin 0

const int chipSelect = 4;

void timer_intr() {

  // analog input
  sensorValue = analogRead(sensorPin);    //アナログ0番ピンからの入力値を取得
  
  // disp: time
  count += 1;

  // convert: count to clock label
  conv_Count_2_ClockLabel(clocl_label, count);

  Serial.println(clocl_label);
  
  sprintf(line_2, "[%07ld] %s => %03d (%05d)", 
        millis(), "count", count, sensorValue);
//  sprintf(line_2, "[%07ld] %s => %03d", millis(), "count", count);
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

    /*
     * sdcard
     */
    _setup_SDCard();
    
}//void setup()

void _setup_SDCard() {

    // ref http://stackoverflow.com/questions/17503094/arduinio-sd-on-ethernet-shield-not-working-at-all answered Feb 28 at 21:32
//  SD.begin();
  SD.begin(chipSelect);

  Serial.print("\nInitializing SD card...");

  // SSピン（Unoは10番、Megaは53番）は使わない場合でも出力にする必要があります。
  // そうしないと、SPIがスレーブモードに移行し、SDライブラリが動作しなくなります。
  pinMode(SS, OUTPUT);

  // ref http://embedjournal.com/arduino-sd-card-initialization-failed/
//  digitalWrite(10,HIGH);
  digitalWrite(SS,HIGH);

  pinMode(chipSelect,OUTPUT);

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  
}//_setup_SDCard()

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

void conv_Count_2_ClockLabel(char* label, int count) {

  int min = count / 60;
  
  int sec = count % 60;

  int hour = 0;
  /*
   * minutes => more than 60
   */
  if (min >= 60) {
    
    hour = min / 60;
    
    min = min - hour * 60;
    
  }
  
  sprintf(label, "%02d:%02d:%02d", hour, min, sec);
//  sprintf(label, "%d:%02d", min, sec);
  
}




