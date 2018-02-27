#include <Wire.h>

// SD
#include <SPI.h>
#include <SD.h>

// ADC
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48); // ADC 0x48 is the default address

// DAC
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;       // DAC

// RTC
#include <MyRealTimeClock.h>
MyRealTimeClock myRTC(31, 33, 35); // Assign Digital Pins    CLK-->31 DAT-->33 RST-->35

// LCD
#include <LCD5110_Graph.h>
LCD5110 myGLCD(7, 6, 5, 3, 2); // myGLCD(CLK,DIN,DC,RST,CE)

// Global Voltage
float voltage = 0.0;        // Initialize Voltage

// File for SD
File myFile;                // Declare global file

// Global Variables of date and time
int dayRTC;
int monthRTC;
int yearRTC;
int hoursRTC;
int minutesRTC;
int secondsRTC;

// Global Variable for ADC
int ADCVal;

// Fonts and autonomous mode boolean
extern uint8_t SmallFont[];
extern unsigned char TinyFont[];
int autonomousMode;


void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  initalizeSD();
  // myRTC.setDS1302Time(00, 34, 12, 27 , 27, 02, 2018); // Sets time at Second 00 Minute 34 Hour 12 Day 27 Day 27 Month 02 Year 2018

  dac.begin(0x62); // Default address for MCP4725A1
  ads.begin();    // Initalice the adc

  // LCD Init
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  randomSeed(analogRead(7));
  autonomousMode = 0; // By default we are in USB Mode

}
void initalizeSD()
{
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void saveToSD(int dayRTC, int monthRTC, int yearRTC, int hoursRTC, int minutesRTC, int secondsRTC, int ADCVal, float voltage)
{
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    //Serial.print("Writing to test.txt...");
    myFile.print("\n Date:");
    myFile.print(dayRTC);
    myFile.print("/");
    myFile.print(monthRTC);
    myFile.print("/");
    myFile.print(yearRTC);
    myFile.print("\t Time:");
    myFile.print(hoursRTC);
    myFile.print(":");
    myFile.print(minutesRTC);
    myFile.print(":");
    myFile.print(secondsRTC);

    myFile.print("\t ADC: ");
    myFile.print(ADCVal);
    myFile.print("\t Voltage: ");
    myFile.print(voltage, 7);
    myFile.print("\n");
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  delay(10);
}

void readSD()
{
  myFile = SD.open("test.txt");
  while (myFile.available()) {
    Serial.write(myFile.read());
  }
  //close the file:
  myFile.close();
}
void updateModeLCD()
{
  if (autonomousMode == 1)
  {
    myGLCD.clrScr();
    myGLCD.drawLine(0, 9, 84, 9);
    myGLCD.setFont(TinyFont);
    myGLCD.print("Autonomous Mode", 12, 2);
    myGLCD.update();
  }
  else
  {
    myGLCD.clrScr();
    myGLCD.drawLine(0, 8, 84, 8);
    myGLCD.setFont(TinyFont);
    myGLCD.print("USB Mode", 25, 2);
    myGLCD.update();
  }
}

void getTime()
{
  myRTC.updateTime();

  dayRTC = myRTC.dayofmonth;
  monthRTC = myRTC.month;
  yearRTC = myRTC.year;
  hoursRTC = myRTC.hours;
  minutesRTC = myRTC.minutes;
  secondsRTC = myRTC.seconds;
}

void updateLCD(int dayRTC, int monthRTC, int yearRTC, int hoursRTC, int minutesRTC, int secondsRTC, int ADCVal, float voltage)
{
  myGLCD.clrScr();
  updateModeLCD();
  myGLCD.setFont(SmallFont);
  // DATE
  myGLCD.print("Date:", 0, 12);
  myGLCD.printNumI(dayRTC, 30, 12);
  myGLCD.print("/", 43, 12);
  myGLCD.printNumI(monthRTC, 49, 12);
  myGLCD.print("/", 62, 12);
  myGLCD.printNumI(yearRTC, 68, 12);
  // TIME
  myGLCD.print("Time:", 0, 21);
  myGLCD.printNumI(hoursRTC, 30, 21);
  myGLCD.print(":", 43, 21);
  myGLCD.printNumI(minutesRTC, 49, 21);
  myGLCD.print(":", 62, 21);
  myGLCD.printNumI(secondsRTC, 68, 21);
  // ADC Value
  myGLCD.print("ADCValue:", 0, 30);
  myGLCD.printNumI(ADCVal, 53, 30);
  myGLCD.print("Voltage:", 0, 39);
  myGLCD.printNumF(voltage, 4, 47, 39);

  myGLCD.update();

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

  readSD();

}
