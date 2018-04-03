#define DEBUGGING true
#include <Wire.h>

// SD
#include <SPI.h>
#include <SD.h>
int pinCS = 53; // Pin 10 on Arduino Uno

// ADC
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48); // ADC 0x48 is the default address

// DAC
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;       // DAC

// RTC
#include "RTClib.h"       // A5 ->SCL A4 ->SDA
RTC_DS3231 rtc;

// LCD
#include<LCD5110_Graph.h>
LCD5110 myGLCD(7, 6, 5, 2, 3); // myGLCD(CLK,DIN,DC,RST,CE)

// Global Voltage
float voltage = 0.0;  // Initialize Voltage

// File for SD
File myFile;                // Declare global file

// Global Variables of date and time
byte dayRTC;
byte monthRTC;
int yearRTC;
byte hoursRTC;
byte minutesRTC;
byte secondsRTC;

// Global Variable for ADC
int ADCVal;

// Fonts and autonomous mode boolean
extern uint8_t SmallFont[];
extern unsigned char TinyFont[];
bool autonomousMode;

void setup()
{
  Serial.begin(9600);
  delay(500);
#ifdef RTC
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  // Si se ha perdido la corriente, fijar fecha y hora
  if (rtc.lostPower()) {
    // Fijar a fecha y hora de compilacion
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
    //rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
  }
#ifdef DEBUGGING
  Serial.println("RTC Initialized");
#endif // DEBUGGING
#endif // RTC

  initSD();

  dac.begin(0x62); // Default address for MCP4725A1
  delay(500);


  ads.begin();    // Initalice the adc
  delay(500);

  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  randomSeed(analogRead(7));
  autonomousMode = 1;
  delay(100);
}



void loop()
{
  uint32_t counter;
  uint32_t dacVal;
  for (counter = 0; counter < 40; counter++)  // Ramp
  {
    dacVal = counter * 100;
    dac.setVoltage(dacVal, false);             // We set the voltage at the counter value

    ADCVal = ads.readADC_SingleEnded(0); // We read from the adc and normalize the voltage
    voltage = (ADCVal * 0.1875) / 1000;

    getTime();

    updateLCD(dayRTC, monthRTC, yearRTC % 100, hoursRTC, minutesRTC, secondsRTC, ADCVal, voltage);
    saveToSD(dayRTC, monthRTC, yearRTC % 100, hoursRTC, minutesRTC, secondsRTC, ADCVal, voltage);
    delay(1000);
  }

}

