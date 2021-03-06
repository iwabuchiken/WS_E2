// Ｉ２Ｃ接続１６文字ｘ２行ＬＣＤのテスト
// 秋月電子[AQM1602A]（アイコン表示は無しです）
#include <Wire.h>
#include "skI2CLCDlib.h"

// 5x7ドットのキャラクタです、1で表示　0で消去
char heart[7] = {
  0b01010,
  0b11011,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
} ;

skI2CLCDlib LCD(0x3E,16) ;              // ＬＣＤのアドレス、画面カラム数16文字

//contrast
int contrast = 40;

//interval
int interval = 2000;

//         0111111001111110       
char* msg_1 = "30 5#1/4        ";

void setup()
{
     // ＬＣＤモジュールの初期化処理
     // ICON OFF,コントラスト(0-63),VDD=3.3Vで使う
//     LCD.Init(LCD_NOT_ICON,32,LCD_VDD3V) ;
    LCD.Init(LCD_NOT_ICON,contrast,LCD_VDD3V) ;

     LCD.CreateChar(1,heart) ;          // 1番にオリジナルキャラクタを登録する

//     // ０ページ目、１ページ目に書き込む(０ページのみ表示される)
//     LCD.SetCursor(0,0) ;               // 表示位置を１行目１列[00H]に設定
//     LCD.Puts("Hello") ;                // [00H]から書込まれる(表示する)
//     LCD.SetCursor(16,0) ;              // 表示位置を１行目１６列[10H]に設定
//     LCD.Putc(0x01) ;                   // 1番に登録したキャラを書込む(表示しない)
//     LCD.SetCursor(0,1) ;               // 表示位置を２行目１列[40H]に設定
////     LCD.Puts("0111111001111110") ;     // [40H]から書込まれる(表示する)
//     LCD.Puts(msg_1) ;     // [40H]から書込まれる(表示する)
//     
////     LCD.Puts("abcdefghijklmnop") ;     // [50H]から書込まれる(表示しない)
//     LCD.Puts("a c e ghijklmnop") ;     // [50H]から書込まれる(表示しない)
//     delay(5000) ;
//     // １ページ目に切り替えて表示する
//     LCD.PageSet(1) ;                   // 1ページ目の表示切り替え
//     delay(5000) ;
//     // １ページ目を書き換える
//     LCD.PageClear() ;                  // 1ページ目のクリア
//     LCD.PageSetCursor(0,0) ;           // 1ページ目の位置でカーソル指示、[10H]に設定
//     LCD.Puts("Arduino") ;              // 1ページ目[10H]から書込まれる(表示する)
//     delay(5000) ;
//     // ０ページ目に表示を切り替える
//     LCD.PageSet(0) ;                   // 0ページ目の表示切り替え
     
}

void loop()
{
  
  exec();
  
}

void exec() {
  
    // ０ページ目、１ページ目に書き込む(０ページのみ表示される)
    LCD.SetCursor(0,0) ;               // 表示位置を１行目１列[00H]に設定
    LCD.Puts("Hello") ;                // [00H]から書込まれる(表示する)
    LCD.SetCursor(16,0) ;              // 表示位置を１行目１６列[10H]に設定
    LCD.Putc(0x01) ;                   // 1番に登録したキャラを書込む(表示しない)
    LCD.SetCursor(0,1) ;               // 表示位置を２行目１列[40H]に設定
//    LCD.Puts("0111111001111110") ;     // [40H]から書込まれる(表示する)
    LCD.Puts(msg_1) ;     // [40H]から書込まれる(表示する)
    
//    LCD.Puts("abcdefghijklmnop") ;     // [50H]から書込まれる(表示しない)
    LCD.Puts("a c e ghijklmnop") ;     // [50H]から書込まれる(表示しない)
    delay(interval) ;
//    delay(5000) ;
    // １ページ目に切り替えて表示する
    LCD.PageSet(1) ;                   // 1ページ目の表示切り替え
    delay(interval) ;
//    delay(5000) ;
    // １ページ目を書き換える
    LCD.PageClear() ;                  // 1ページ目のクリア
    LCD.PageSetCursor(0,0) ;           // 1ページ目の位置でカーソル指示、[10H]に設定
    LCD.Puts("Arduino") ;              // 1ページ目[10H]から書込まれる(表示する)
    delay(interval) ;
//    delay(5000) ;
    
    LCD.PageClear() ;                  // 1ページ目のクリア
    
    // ０ページ目に表示を切り替える
    LCD.PageSet(0) ;                   // 0ページ目の表示切り替え

}//void exec()


