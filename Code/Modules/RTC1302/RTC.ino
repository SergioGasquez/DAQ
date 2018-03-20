#include <MyRealTimeClock.h>

MyRealTimeClock myRTC(31, 33, 35); // Assign Digital Pins    CLK-->10 DAT-->11 RST-->12



void setup() {
Serial.begin(9600);
// myRTC.setDS1302Time(00, 34, 12, 27 , 27, 02, 2018); // Sets time at Second 00 Minute 34 Hour 12 Day 27 Day 27 Month 02 Year 2018
}

int getTime()
{  
  Serial.print("Current Date / Time: "); 
  Serial.print(myRTC.dayofmonth); // Element 1
  Serial.print("/"); 
  Serial.print(myRTC.month); // Element 2
  Serial.print("/");
  Serial.print(myRTC.year); // Element 3
  Serial.print(" ");
  Serial.print(myRTC.hours); // Element 4
  Serial.print(":");
  Serial.print(myRTC.minutes); // Element 5
  Serial.print(":");
  Serial.println(myRTC.seconds); // Element 6
}


void loop() {

// Allow the update of variables for time / accessing the individual element. 
myRTC.updateTime();
getTime();
delay(5000);


}
