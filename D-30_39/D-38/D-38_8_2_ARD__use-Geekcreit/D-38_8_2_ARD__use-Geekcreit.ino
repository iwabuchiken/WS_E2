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

char* id = "38 s-9#1 steps.27-3";
char* msg = "Welcome";

Sd2Card card;
SdVolume volume;
SdFile root;

File myFile;

char* fname = "16090801.txt";

int INTERVAL = 1000;

int count = 0;

int sensorValue = 0;

char line_2[30];
char clocl_label[10];

/*
 * pins
 */
int sensorPin = A0;   // analog pin 0

const int chipSelect = 4;

byte interrupt_pin = 2;

/*
 * flags
 */
byte flag_PinIntr = 0;        // f1 --> see memo for 'f1'

byte flag_PinIntr_Loop = 0;        // f2

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
//  conv_Count_2_ClockLabel(clocl_label, count);

  Serial.println(clocl_label);
  
  sprintf(line_2, "[%07ld] %s => %03d (%05d)", 
        millis(), "count", count, sensorValue);
//  sprintf(line_2, "[%07ld] %s => %03d", millis(), "count", count);
//  sprintf(line_2, "[%06ld] %s => %03d", millis(), "count", count);
//  sprintf(line_2, "[%d] %s => %03d", millis(), "count", count);
//  sprintf(line_2, "%s => %03d", "count", count);
  
  Serial.println(line_2);

  /*
   * pin state
   */
  int val = digitalRead(interrupt_pin);
  
  //message
   Serial.print("interrupt pin --> ");
   Serial.println(val);
  
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

    /*
     * sdcard
     */
    _setup_SDCard();

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

//void _setup_Interrupt() {
//  
//  // attach
//  attachInterrupt(
//      digitalPinToInterrupt(interrupt_pin), 
//      intr_pin, RISING);
//  
//}//_setup_Interrupt()

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






