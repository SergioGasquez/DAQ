#include <Wire.h>
#include "RTClib.h"

// RTC_DS1307 rtc;
RTC_DS3231 rtc;


int dayRTC;
int monthRTC;
int yearRTC;
int hoursRTC;
int minutesRTC;
int secondsRTC;


void initRTC()
{
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }
  
  // Si se ha perdido la corriente, fijar fecha y hora
  //if (rtc.lostPower()) {
    // Fijar a fecha y hora de compilacion
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
    // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
  //}
}
  
void setup() {
  Serial.begin(9600);
  delay(1000);
  initRTC();
}

void printDate(DateTime date)
{
  Serial.print(date.year(), DEC);
  Serial.print('/');
  Serial.print(date.month(), DEC);
  Serial.print('/');
  Serial.print(date.day(), DEC);
  Serial.print('\t');
  Serial.print(date.hour(), DEC);
  Serial.print(':');
  Serial.print(date.minute(), DEC);
  Serial.print(':');
  Serial.print(date.second(), DEC);
  Serial.println();



  
}

void loop() {

  // Obtener fecha actual y mostrar por Serial
  DateTime now = rtc.now();
  
  dayRTC = now.day();
  monthRTC = now.month();
  yearRTC = now.year();
  hoursRTC = now.hour();
  minutesRTC = now.minute();
  secondsRTC = now.second();
 // printDate(now);


      Serial.print("\n Date:");
    Serial.print(dayRTC);
    Serial.print("/");
    Serial.print(monthRTC);
    Serial.print("/");
    Serial.print(yearRTC);
    Serial.print("\t Time:");
    Serial.print(hoursRTC);
    Serial.print(":");
    Serial.print(minutesRTC);
    Serial.print(":");
    Serial.print(secondsRTC);
  delay(3000);
}
