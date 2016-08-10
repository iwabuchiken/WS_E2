/*
 * http://deviceplus.jp/hobby/entry021/
 */
//const int chipSelect = 10;

#include <SPI.h>
#include <SD.h>

//         0111111001111110       
char* msg_1 = "36 1#1/1        ";


File myFile;

const int chipSelect = 4;

void setup()
{
  // シリアルポート初期化
  Serial.begin(9600);
  while (!Serial) {
    ; // USBケーブルが接続されるのを待つ。この待ちループは Leonardo のみ必要。
  }

  Serial.print(F("Initializing SD card..."));

  // SSピン（Unoは10番、Megaは53番）は使わない場合でも出力にする必要があります。
  // そうしないと、SPIがスレーブモードに移行し、SDライブラリが動作しなくなります。
  pinMode(SS, OUTPUT);

  // ref http://embedjournal.com/arduino-sd-card-initialization-failed/
//  digitalWrite(10,HIGH);
  digitalWrite(SS,HIGH);
  
  // SDライブラリを初期化
  if (!SD.begin(chipSelect)) {
    Serial.println(F("Card failed, or not present"));
    // 失敗、何もしない
    while(1);
  }
  Serial.println(F("ok."));

//  // 日付と時刻を返す関数を登録
//  SdFile::dateTimeCallback( &dateTime );
}

void loop()
{

}

