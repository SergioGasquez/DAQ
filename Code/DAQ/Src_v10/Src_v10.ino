// DEFINES //

#define LCD
#define RTC
#define microSD
#define ADC
#define DAC
#define MULTIPLEXER
#define MULTIPLEXER2            // DESARROLAR FUNCION
#define MEM_EEPROM
#define COMGPRS
#define DEBUGGING true



#define CICLOS_WTDG  10
#define TIEMPO_COMUNICACIONES 60//900     // (Segundos) COMUNICAR CADA 15 mins
#define TIEMPO_SD 600//900     // (Segundos) COMUNICAR CADA 15 mins

#define maxciclosComunicaciones (TIEMPO_COMUNICACIONES/8)     // Ciclos ante de enviar los datos por sigfox. Se calcula con el Tiempo en segundos definido previamente
#define maxciclosSD (TIEMPO_SD/8)     // Ciclos ante de enviar los datos por sigfox. Se calcula con el Tiempo en segundos definido previamente



#include <Wire.h>
#include <avr/wdt.h>

// SD
#ifdef microSD
#include <SPI.h>
#include <SD.h>
int pinCS = 53; // Pin 10 on Arduino Uno
#endif //microSD


#ifdef COMGPRS
#include <SoftwareSerial.h>
SoftwareSerial SIM900(10, 11); // (RX, TX)
#endif //GPRS


// WTDG
volatile int ISRCounterWTDG = 0;


// ADC
#ifdef ADC
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48); // ADC 0x48 is the default address
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
int enablePin = 35;
int multiplexerA0 = 39;
int multiplexerA1 = 41;
int multiplexerA2 = 43;
#endif //MULTIPLEXER

#ifdef MULTIPLEXER2
int multiplexer2Pin = 31;
#endif //MULTIPLEXER2

// Global Voltage
float voltage = 0.0;  // Initialize Voltage

// File for SD
#ifdef microSD
File myFile;                // Declare global file
String fileNameStr;            // File of the .txt
char fileName[12];

unsigned int ciclosSD = 0;
volatile bool flagSD = false;
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




#ifdef COMGPRS
unsigned int ciclosComunicaciones = 0;
volatile bool flagComunicaciones = false;
#endif // COMGPRS

char confStr1[9] = "9";
char confStr2[10] = "9";

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
// VARIABLES PARA ALMACENAR VALORES
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



// Funciones externas
void(* ResetSW) (void) = 0;


ISR (WDT_vect)
{
  ISRCounterWTDG++;
#if DEBUGGING
  //Serial.print("WTDG: ");Serial.println(ISRCounterWTDG);
#endif //DEBUGGING
  if (ISRCounterWTDG >= CICLOS_WTDG)
  {
    delay(50);
    ISRCounterWTDG = 0;
#if DEBUGGING
    Serial.println("Reset por WD");
#endif //DEBUGGING
    delay(1000);
    ResetSW();
  }

#ifdef COMGPRS
  ciclosComunicaciones++;
  if (ciclosComunicaciones >= maxciclosComunicaciones)
  {
    flagComunicaciones = true;
    ciclosComunicaciones = 0;
#if DEBUGGING
    //Serial.println("flagComunicaciones");
#endif //DEBUGGING  
  }
#if DEBUGGING
  //Serial.print("ciclosComunicaciones: "); Serial.println(ciclosComunicaciones);
#endif //DEBUGGING  
#endif //COMGPRS

#ifdef microSD
  ciclosSD++;
  //Serial.print("ciclosSD: "); Serial.println(ciclosSD);
  if (ciclosSD >= maxciclosSD)
  {
    flagSD = true;
    ciclosSD = 0;
#if DEBUGGING
    //Serial.print("flagSD: "); Serial.println(flagSD);
#endif //DEBUGGING  
  }
#endif //microSD


}// Final ISR


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
  dac.begin(0x62); // Default address for MCP4725A1
  delay(500);
#endif //DAC

#ifdef ADC
  ads.begin();    // Initalice the adc
  delay(500);
#endif //ADC

#ifdef LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  randomSeed(analogRead(7));
  updateModeLCD();
  delay(100);
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
  ResetWTDG();
#ifdef COMGPRS
  if (flagComunicaciones)
  {
    updateTaskLCD(1);
    ResetWTDG();
    flagComunicaciones = false;
#if DEBUGGING
    Serial.println("Se envian los datos");
#endif DEBUGGING
#ifdef LCD
    updateTaskLCD(3);
#endif
    measureChannels();
    delay(1000);
#ifdef LCD
    updateTaskLCD(1);
#endif
    sendData();
#ifdef LCD
    updateConfigLCD();
#endif
  }
#endif // COMGPRS

#ifdef microSD
  if (flagSD)
  {
    ResetWTDG();
    flagSD = false;
#if DEBUGGING
    Serial.println("Se guardan los datos");
#endif DEBUGGING
#ifdef LCD
    updateTaskLCD(3);
#endif
    measureChannels();
    delay(2000);
    updateTaskLCD(2);
    getTime();
    saveToSD();
    delay(2000);
#ifdef LCD
    updateConfigLCD();
#endif();
  }
#endif //microSD

}


