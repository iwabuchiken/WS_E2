/*
 * http://deviceplus.jp/hobby/entry021/
 */
//const int chipSelect = 10;

#include <SPI.h>
#include <SD.h>

//         0111111001111110       
char* msg_1 = "38 2#2 steps.3";


// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

File myFile;

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
const int chipSelect = 4;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // opening message
  Serial.println(msg_1);

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
   * open & close a file
   * ref https://github.com/adafruit/SD/blob/master/utility/SdFile.cpp
   * search https://www.google.co.jp/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=arduino+sdfile
   */
//  uint8_t res = SdFile.open(root, "test-2.txt", O_APPEND);
  uint8_t res = root.open(root, "test-2.txt", O_APPEND);

  Serial.print("opening the file => ");
  
  if (res == 1) {

    Serial.println("success");

    // close the file
//    uint8_t res = SdFile.close();
    uint8_t res = root.close();

    Serial.print("closing the file => ");
    Serial.println(res);
    
  } else if (res == 0) {

    Serial.println("failed");
    
  } else {

    Serial.println("unknown result");
    
  }
   
  
}//void setup()

void loop()
{

}

