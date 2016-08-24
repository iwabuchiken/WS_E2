/*
 * http://qiita.com/ohisama@github/items/4a73d133b7abff298e1e
 */
//const int chipSelect = 10;

#include <SPI.h>
#include <SD.h>

//         0111111001111110       
char* msg_1 = "38 2#2 steps.2";


// set up variables using the SD utility library functions:
//Sd2Card card;
//SdVolume volume;
//SdFile root;

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

  /*
   * SD => begin
   */
  Serial.print("Initializing SD card...");
  if (!SD.begin(4))
  {
      Serial.println("initialization failed!");
      return;
  }
  Serial.println("initialization done.");

  /* 
   *  write file
   */
    myFile = SD.open("test.txt", FILE_WRITE);
    if (myFile)
    {
        Serial.print("Writing to test.txt...");
        myFile.println("testing 1, 2, 3.");

//        myFile.println(millis());
        
        myFile.close();
        Serial.println("done.");
        
    }
    else
    {
        Serial.println("error opening test.txt");
    }
  
}//void setup()

void loop()
{

}

