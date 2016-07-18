/*
 * http://deviceplus.jp/hobby/entry021/
 */
#include <SPI.h>

#include <SD.h>

Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = 10;

//         0111111001111110       
char* msg_1 = "36 1#1/1        ";

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
  ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print("\nInitializing SD card...");
  pinMode(10, OUTPUT); // change this to 53 on a mega
  
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card is inserted?");
    Serial.println("* Is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
    
  } else {
    
    Serial.println("Wiring is correct and a card is present.");
    
  }
  
}//setup()

void loop()
{
  
  exec();
  
}

void exec() {  

}//void exec()



