// LCD5110_Graph_Demo 
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// This program is a demo of most of the functions
// in the library.
//
// This program requires a Nokia 5110 LCD module.
//
// It is assumed that the LCD module is connected to
// the following pins using a levelshifter to get the
// correct voltage to the module.
//      SCK  or CLK- Pin 7 arduino
//      MOSI or DIN - Pin 6 arduino
//      DC   - Pin 5 arduino
//      RST  - Pin 3 arduino
//      CS or CE  - Pin 2 arduino It was 4,but changed it for the SD Shield.
//      VCC - 3.3 volt arduino
//      BL - 5 volt arduino
//      GND- ground of arduino
// 
#include<LCD5110_Graph.h>

LCD5110 myGLCD(7,6,5,3,2); // myGLCD(CLK,DIN,DC,RST,CE)

extern uint8_t SmallFont[];
extern unsigned char TinyFont[];
int autonomousMode;

void setup()
{
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  randomSeed(analogRead(7));
  autonomousMode=1;
}


void updateModeLCD()
{
  if (autonomousMode==1)
  {
    myGLCD.clrScr();
    myGLCD.drawLine(0,9,84,9);
    myGLCD.setFont(TinyFont);
    myGLCD.print("Autonomous Mode",12,2);
    myGLCD.update();
  }
  else
  {
    myGLCD.clrScr();
    myGLCD.drawLine(0,8,84,8);
    myGLCD.setFont(TinyFont);
    myGLCD.print("USB Mode",25,2);
    myGLCD.update();
  }
}

void updateLCD(int dayRTC,int monthRTC,int yearRTC,int hoursRTC,int minutesRTC,int secondsRTC,int ADCVal,float voltage)
{
  myGLCD.clrScr();
  updateModeLCD();
  myGLCD.setFont(SmallFont);
  // DATE
  myGLCD.print("Date:",0,12);
  myGLCD.printNumI(dayRTC,30,12);
  myGLCD.print("/",43,12);
  myGLCD.printNumI(monthRTC,49,12);
  myGLCD.print("/",62,12);
  myGLCD.printNumI(yearRTC,68,12);
  // TIME
  myGLCD.print("Time:",0,21);
  myGLCD.printNumI(hoursRTC,30,21);
  myGLCD.print(":",43,21);
  myGLCD.printNumI(minutesRTC,49,21);
  myGLCD.print(":",62,21);
  myGLCD.printNumI(secondsRTC,68,21);
  // ADC Value
  myGLCD.print("ADCValue:",0,30);
  myGLCD.printNumI(ADCVal,57,30);
  myGLCD.print("Voltage:",0,39);
  myGLCD.printNumF(voltage,4,47,39);
  
  myGLCD.update();  
  
}



void loop()
{
  int dayRTC;
  int monthRTC;
  int yearRTC;
  int hoursRTC;
  int minutesRTC;
  int secondsRTC;
  int ADCVal;
  float voltage;

  dayRTC= 24;
  monthRTC=21;
  yearRTC=18;
  hoursRTC=13;
  minutesRTC=14;
  secondsRTC=14;
  ADCVal=9;
  voltage=0.002;
  
  updateLCD(dayRTC,monthRTC,yearRTC,hoursRTC,minutesRTC,secondsRTC,ADCVal,voltage);
  delay (2000);
  dayRTC= 2;
  monthRTC=1;
  yearRTC=18;
  hoursRTC=1;
  minutesRTC=1;
  secondsRTC=4;
  ADCVal=2092;
  voltage=4.982;

  
  updateLCD(dayRTC,monthRTC,yearRTC,hoursRTC,minutesRTC,secondsRTC,ADCVal,voltage);
  delay (2000);


}

