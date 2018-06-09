/*
           Data Acquisition System
            Sergio Gasquez Arcos


       https://github.com/SergioGasquez/DAQ


*/

//-------------- DEFINES --------------//
#define LCD
#define RTC
#define microSD
#define ADC
#define DAC
#define MULTIPLEXER
#define MULTIPLEXER2
#define MEM_EEPROM
//#define COMGPRS
#define DEBUGGING true

//-------------- TIMERS --------------//
#define WTDG_CYCLES  10
#define COMM_TIME 60     // Time between comms (in seconds)
#define SD_TIME 600     // Time between saves in the SD (in seconds)

#define maxCyclesComm (COMM_TIME/8)
#define maxCyclesSD (SD_TIME/8)



#include <Wire.h>
#include <avr/wdt.h>
#include <avr/sleep.h>


//-------------- SD --------------//
#ifdef microSD
#include <SPI.h>
#include <SD.h>
int pinCS = 53;
#endif //microSD


//-------------- GPRS --------------//
#ifdef COMGPRS
#include <SoftwareSerial.h>
SoftwareSerial SIM900(10, 11); // (RX, TX)
#endif //GPRS


//-------------- WTDG --------------//
volatile int ISRCounterWTDG = 0;


//-------------- ADC --------------//
#ifdef ADC
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48);     // ADC 0x48 is the default address
#endif //ADC

//-------------- DAC --------------//
#ifdef DAC
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;
#endif //DAC

//-------------- RTC --------------//
#ifdef RTC
#include "RTClib.h"             // A5 ->SCL   A4 ->SDA
RTC_DS3231 rtc;
#endif //RTC

//-------------- LCD --------------//
#ifdef LCD
#include<LCD5110_Graph.h>
LCD5110 myGLCD(6, 5, 4, 2, 3);  // myGLCD(CLK,DIN,DC,RST,CE)
#endif //LCD

//-------------- MULTIPLEXER --------------//
#ifdef MULTIPLEXER
int enablePin = 35;
int multiplexerA0 = 39;
int multiplexerA1 = 41;
int multiplexerA2 = 43;
#endif //MULTIPLEXER

#ifdef MULTIPLEXER2
int multiplexer2Pin = 31;
#endif //MULTIPLEXER2


// File for SD
#ifdef microSD
File myFile;                      // Declare global file
String fileNameStr;               // File of the .txt
char fileName[12];

unsigned int sdCycles = 0;
volatile bool flagSD = false;
#endif //microSD

// Global Variables for date and time
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




#ifdef COMGPRS
unsigned int commCycles = 0;
volatile bool commFlag = false;
#endif // COMGPRS

char confStr1[9] = "9";
char confStr2[10] = "9";

// Cofiguration Variables
boolean smu = true;
boolean typeSMU = true;
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

// Channels values
int valSMU = 0;
int valADC_2 = 0;
int valADC_3 = 0;
int valArdu_A8 = 0;
int valArdu_A9 = 0;
int valArdu_A10 = 0;
int valArdu_A11 = 0;
int valMulti_E5 = 0;
int valMulti_E6 = 0;
int valMulti_E7 = 0;
int valMulti_E8 = 0;
int valMulti_E3 = 0;
int valMulti_E4 = 0;
int dacVal = 0;



//-------------- FUNCTIONS --------------//
void(* ResetSW) (void) = 0;


/*        Watchdog Interrup Function
   ----------------------------------------
   Each time watcdog interrupt is triggered
   (and it will be triggered each 8 secs)
   this function will run.

   We increment in 1 all the counters and if
   any counter has reach his max, it activates
   the flag.

*/

ISR (WDT_vect)
{
  ISRCounterWTDG++;
#if DEBUGGING
  //Serial.print("WTDG: ");Serial.println(ISRCounterWTDG);
#endif //DEBUGGING
  if (ISRCounterWTDG >= WTDG_CYCLES)
  {
    delay(50);
    ISRCounterWTDG = 0;
#if DEBUGGING
    Serial.println("Reset due to WTDG");
#endif //DEBUGGING
    delay(1000);
    ResetSW();
  }
#ifdef COMGPRS
  commCycles++;
  if (commCycles >= maxCyclesComm)
  {
    commFlag = true;
    commCycles = 0;
#if DEBUGGING
    //Serial.println("commFlag");
#endif //DEBUGGING  
  }
#if DEBUGGING
  //Serial.print("commCycles: "); Serial.println(commCycles);
#endif //DEBUGGING  
#endif //COMGPRS

#ifdef microSD
  sdCycles++;
#if DEBUGGING
  //Serial.print("sdCycles: "); Serial.println(sdCycles);
#endif //DEBUGGING
  if (sdCycles >= maxCyclesSD)
  {
    flagSD = true;
    sdCycles = 0;
#if DEBUGGING
    //Serial.print("flagSD: "); Serial.println(flagSD);
#endif //DEBUGGING  
  }
#endif //microSD
}// Final ISR

/*                Flash
   ----------------------------------------
   It makes the builtin flash in order
   to debug without a Serial Monitor
*/

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


#ifdef DAC
  dac.begin(0x62);        // Default address for MCP4725A1
  delay(500);
#endif //DAC

#ifdef ADC
  ads.begin();
  delay(500);
#endif //ADC

#ifdef LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  randomSeed(analogRead(7));
  delay(100);
  updateTaskLCD(0);
#endif //LCD

#ifdef COMGPRS
  initSIM900();
  delay(1000);
#endif //COMGPRS
  setWatchdog();

#ifdef MEM_EEPROM
  checkIfConnected();
  configureSystem();
#endif // MEM_EEPROM

#ifdef microSD
  initSD();
#endif //microSD


#ifdef MULTIPLEXER
  initMultiplexer();
#endif // MULTIPLEXER
  flash();
#ifdef COMGPRS
  if (strlen(confStr1) > 2)
  {
    sendConfig();
  }
#endif //COMGPRS
}

void loop()
{
  if (!typeSMU)
  {
    ResetWTDG();
    cpuSleep();
#ifdef COMGPRS
    if (commFlag)
    {
      updateTaskLCD(1);
      ResetWTDG();
      commFlag = false;
#if DEBUGGING
      Serial.println("Data will be sent...");
#endif DEBUGGING
#ifdef LCD
      updateTaskLCD(3);
#endif // LCD
      measureChannels();
      delay(1000);
#ifdef LCD
      updateTaskLCD(1);
#endif // LCD
      sendData();
#ifdef LCD
      updateConfigLCD();
#endif // LCD
    }
#endif // COMGPRS

#ifdef microSD
    if (flagSD)
    {
      ResetWTDG();
      flagSD = false;
#if DEBUGGING
      Serial.println("Data will be saved in the SD Card");
#endif //DEBUGGING
#ifdef LCD
      updateTaskLCD(3);
#endif // LCD
      measureChannels();
      delay(2000);
      updateTaskLCD(2);
      getTime();
      saveToSD();
      delay(2000);
#ifdef LCD
      updateConfigLCD();
#endif// LCD;
    }
#endif //microSD
  }
  else
  {
    Serial.println("Voltage Sweep");
    int counter;
    for (counter = 0; counter < 20; counter++)
    {
#if DEBUGGING
      Serial.print("dacVal: "); Serial.println(dacVal);
#endif //DEBUGGIN
      dacVal = counter * 100;
      dac.setVoltage(dacVal, false);
      getTime();
#ifdef LCD
      updateTaskLCD(3);
#endif// LCD;
      measureChannels();
#ifdef LCD
      updateTaskLCD(1);
#endif// LCD;
#ifdef COMGPRS
      sendData();
#endif // COMGPRS
#ifdef LCD
      updateTaskLCD(2);
#endif// LCD;
      saveToSD();
      // HABRIA QUE ENVIAR EL VOLTAJE TAMBIEN?
    }
  }


}


