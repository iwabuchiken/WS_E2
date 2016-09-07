/*
 * 2016/08/20 13:49:33
 *   
 *   <i/o>
 
*   <description>
 *   
 *   <bear in mind>
 *   
 *   <remarks>
 *   
 */

char* id = "38 s-1#1";
char* msg = "Welcome";

unsigned long mills;

void setup() {

    //ref http://siva.cc.hirosaki-u.ac.jp/usr/koyama/semi/06p1254a6.pdf
  Serial.begin(9600);
  
  // opening message
  Serial.print("serial --> beginning... ");
  Serial.print(id);

  mills = millis();

  Serial.print("time in mills: ");
  Serial.println(mills);


}//void setup()

void loop() {

}

