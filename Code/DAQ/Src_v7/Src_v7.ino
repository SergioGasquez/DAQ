// DEFINES //

#define LCD
#define RTC
#define microSD
#define ADC
#define DAC
#define MULTIPLEXER
#define MULTIPLEXER2            // DESARROLAR FUNCION
#define MEM_EEPROM
#define DEBUGGING true

#ifdef ADC
#define ADC_A0
//#define ADC_A1
//#define ADC_A2
//#define ADC_A3
#endif // ADC



#include <Wire.h>

// SD
#ifdef microSD
#include <SPI.h>
#include <SD.h>
int pinCS = 53; // Pin 10 on Arduino Uno
#endif //microSD


// ADC
#ifdef ADC
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48); // ADC 0x48 is the default address
byte onADC_A0 = 0;
byte onADC_A1 = 0;
byte onADC_A2 = 0;
byte onADC_A3 = 0;
byte channelsOn;
#endif //ADC

// DAC
#ifdef DAC
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;       // DAC
#endif //DAC

// RTC
#ifdef RTC
#include "RTClib.h"       // A5 ->SCL A4 ->SDA
RTC_DS3231 rtc;
#endif //RTC

// LCD
#ifdef LCD
#include<LCD5110_Graph.h>
LCD5110 myGLCD(6, 5, 4, 2, 3); // myGLCD(CLK,DIN,DC,RST,CE)
#endif //LCD

// MULTIPLEXER
#ifdef MULTIPLEXER
int enablePin = 37;
int multiplexerA0 = 39;
int multiplexerA1 = 41;
int multiplexerA2 = 43;
#endif //MULTIPLEXER

// Global Voltage
float voltage = 0.0;  // Initialize Voltage

// File for SD
#ifdef microSD
File myFile;                // Declare global file
String fileNameStr;            // File of the .txt
char fileName[12];
#endif //microSD

// Global Variables of date and time
#ifdef RTC
byte dayRTC;
byte monthRTC;
int yearRTC;
byte hoursRTC;
byte minutesRTC;
byte secondsRTC;
#endif //RTC

// Fonts and autonomous mode boolean
#ifdef LCD
extern uint8_t SmallFont[];
extern unsigned char TinyFont[];
bool autonomousMode = true;
#endif //LCD

// VALIABLES CONFIG
boolean smu = true;
boolean ADC_2 = true;
boolean ADC_3 = true;
boolean ARDU_A8 = true;
boolean ARDU_A9 = true;
boolean ARDU_A10 = true;
boolean ARDU_A11 = true;
boolean multi_E5 = true;
boolean multi_E6 = true;
boolean multi_E7 = true;
boolean multi_E8 = true;
boolean multi_E3 = true;
boolean multi_E4 = true;

void flash()
{
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}

void setup()
{
  Serial.begin(9600);
  delay(500);
#ifdef RTC
  initRTC();
#endif //RTC
#ifdef microSD
  initSD();
#endif //microSD

#ifdef DAC
  dac.begin(0x62); // Default address for MCP4725A1
  delay(500);
#endif //DAC

#ifdef ADC
  ads.begin();    // Initalice the adc
  delay(500);
#endif //ADC

#ifdef MEM_EEPROM
  checkIfConnected();
  configureSystem();
#endif // MEM_EEPROM


#ifdef LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  randomSeed(analogRead(7));
  updateModeLCD();
  delay(100);
#endif //LCD

#ifdef MULTIPLEXER
  initMultiplexer();
  setChannel(1);
#endif // MULTIPLEXER

#ifdef ADC_A0
  onADC_A0 = 1;
#endif //ADC_A0
#ifdef ADC_A1
  onADC_A1 = 2;
#endif //ADC_A1
#ifdef ADC_A2
  onADC_A2 = 4;
#endif //ADC_A2
#ifdef ADC_A3
  onADC_A3 = 8;
#endif //ADC_A3
  channelsOn = onADC_A0 + onADC_A1 + onADC_A2 + onADC_A3;
#if DEBUGGING
  Serial.print("Channels on: "); Serial.println(channelsOn);
#endif //DEBUGGING

  flash();
}

void loop()
{
  //  uint32_t counter;
  //  uint32_t dacVal;
  //  float volt;
  //  for (counter = 0; counter < 10; counter++)  // Ramp
  //  {
  //    Serial.print(counter);
  //    dacVal = counter * 205;
  //    Serial.print(" \tDAC: "); Serial.print(dacVal);
  //    dac.setVoltage(dacVal, false);             // We set the voltage at the counter value
  //
  //
  //
  //    valADC_A0 = ads.readADC_SingleEnded(0); // We read from the adc and normalize the voltage
  //    Serial.print("\t valADC_A0: "); Serial.print(valADC_A0);
  //    voltage = (valADC_A0 * 0.1875) / 1000;
  //    Serial.print("\t voltage: "); Serial.println(voltage);
  //
  //    getTime();
  //
  //    updateLCD();
  //    saveToSD();
  //
  //  }

  //  dac.setVoltage(1700, false);
  //  volt=analogRead(A0);
  //    Serial.print("volt");Serial.println(volt);
  //  Serial.print("volt");Serial.println(volt*5/1024);
  //  waitForKey();

}


