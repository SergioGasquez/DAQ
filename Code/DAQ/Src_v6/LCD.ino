#ifdef LCD
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
#endif //LCD
