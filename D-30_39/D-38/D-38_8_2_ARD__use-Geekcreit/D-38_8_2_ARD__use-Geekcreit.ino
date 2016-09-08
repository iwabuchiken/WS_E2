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

char* id = "38 s-9#1 steps.24";
char* msg = "Welcome";

Sd2Card card;
SdVolume volume;
SdFile root;

File myFile;

//char* fname = "20160826.txt";
//char* fname = "20160907.txt";
char* fname = "16090801.txt";
//char* fname = "160907_1.txt";
//char* fname = "160907-1.txt";

//LiquidCrystal lcd(7,8,9,10,11,12,13);
//
//int LED_OUT = 0;
//int LED_OUT_2 = 1;
////int LED_OUT = 13;

int INTERVAL = 1000;
//int INTERVAL = 100;

//int count = 3600;
int count = 0;

int sensorValue = 0;

char line_2[30];
char clocl_label[10];

/*
 * pins
 */
int sensorPin = A0;   // analog pin 0

const int chipSelect = 4;

int interrupt_pin = 2;

/*
 * flags
 */
int flag_PinIntr = 0;        // f1 --> see memo for 'f1'

int flag_PinIntr_Loop = 0;        // f2

//int flag_PinIntr_Occurred = 0;    // f3
//
//int flag_PinIntr_Not_Occurred = 0;  // f4



int flag_Changed = 0;

/*
 * values
 * 
 */
//int chattering_time = 200;

/************************************
 * funcs
 *************************************/
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

  /*
   * write: sdcard
   */
  
  write_SDCard(fname, line_2);
  
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

    /*
     * pin intr
     */
//    _setup_Interrupt();
    
    /*
     * pins
     */
    _setup_Pins();
    
}//void setup()

void _setup_Pins() {
  
  pinMode(interrupt_pin, INPUT);
  
  // message
  Serial.println("setup pins --> done");
  
}//_setup_Pins()

void _setup_Interrupt() {
  
  // attach
  attachInterrupt(
      digitalPinToInterrupt(interrupt_pin), 
      intr_pin, RISING);
  
}//_setup_Interrupt()

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

  /*
   * card type
   */
  Serial.print("\nCard type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
    Serial.println("SD1");
    break;
    case SD_CARD_TYPE_SD2:
    Serial.println("SD2");
    break;
    case SD_CARD_TYPE_SDHC:
    Serial.println("SDHC");
    break;
    default:
    Serial.println("Unknown");
  }//switch (card.type())

  /*
   * init volume
   */
   if (!volume.init(card)) {
      Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
      return;
    } else {

      Serial.println("init volume => done");
      
    }

  /*
   * - volume size
   * - list files
   */
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();
  volumesize = volume.blocksPerCluster(); // clusters are collections of blocks
  volumesize *= volume.clusterCount(); // we'll have a lot of clusters
  volumesize *= 512; // SD card blocks are always 512 bytes
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);
  root.ls(LS_R | LS_DATE | LS_SIZE);

  /*
   * write: opening messages
   */
  myFile = SD.open(fname, FILE_WRITE);
  if (myFile)
  {
    Serial.println("file => opened");
    
      Serial.print("Writing to: ");
      Serial.println(fname);
      
      myFile.println(id);
      myFile.close();
      
      Serial.println("done.");
  }
  else
  {
      Serial.print("error opening: ");
      Serial.println(fname);
      
  }

  
}//_setup_SDCard()

void _setup_Timer2() {

    MsTimer2::set(INTERVAL, timer_intr); // 500ms period　←500ミリ秒おきにflash関数の実行を指定 
    MsTimer2::start();

}//_setup_Timer2()

void loop() {

  /*
   * pin interrupt
   */
//  _loop_PinIntr();
  
//  //ref sprintf https://liudr.wordpress.com/2012/01/16/sprintf/
//  lcd.setCursor(0,1);
////  sprintf(line_2, "%s %02d", "counting...", count);
//  sprintf(line_2, "%s %03d", "counting ", count);
//  
//  lcd.print(line_2);
  
}

void _loop_PinIntr() {
  
  // judge
  if (flag_PinIntr == 1) {
    
    // chattering safety
//    delay(chattering_time);
//    delay(100);
    delay(250);
    
    // message
    Serial.println("flag_PinIntr => 1");
    
    // reset
    flag_PinIntr = 0;

  }
  
}//_loop_PinIntr()

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

void write_SDCard(char* filename, char* line_2) {
  
    /*
     * write: 
     */
    myFile = SD.open(fname, FILE_WRITE);
//    myFile = SD.open(filename, FILE_WRITE);
    
    if (myFile)
    {
      Serial.println("file => opened");
      
//        Serial.print("Writing to test.txt...");
        
        myFile.println(line_2);
        myFile.close();
        
        Serial.println("done.");
    }
    else
    {
        Serial.println("error opening: ");
        Serial.println(filename);
        
    }
  
}//void write_SDCard

void intr_pin() {
  
  // set flag
  if (flag_PinIntr == 0) {
     
    flag_PinIntr = 1;
    
    // message
    Serial.println("pin interrupt => detected");

  } else {
    
    // message
    Serial.println("flag_PinIntr => not 0");
      
  }
  
//  } else {
//    
//    flag_PinIntr = 0;
//    
//  }
  
//  flag_PinIntr = 1;
  
//  Serial.println("pin intr ==> occurred");


}












