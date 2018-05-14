// LCD5110_Graph
#include<LCD5110_Graph.h>

LCD5110 myGLCD(7, 6, 5, 3, 4); // myGLCD(CLK,DIN,DC,RST,CE)

// Declaracíon de los tipos de letra
extern uint8_t SmallFont[];
extern unsigned char TinyFont[];


void updateLCD()
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
  myGLCD.printNumI(valADC_A0, 53, 30);
  myGLCD.print("Voltage:", 0, 39);
  myGLCD.printNumF(voltage, 4, 47, 39);

  myGLCD.update();

}

void loop()
{

  
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

