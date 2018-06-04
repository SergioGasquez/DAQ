#ifdef LCD


/*              updateModeLCD
 * ----------------------------------------
 * Updates the top of the LCD display
 * showing the mode of the system
 * either is USB Mode when connected t
 * to a PC or Autonomous Mode when
 * connected to a battery.
 */
void updateModeLCD()
{
  ResetWTDG();
  if (autonomousMode == true)
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

/*              updateTaskLCD
 * ----------------------------------------
 * Updates  the LCD display in order to 
 * show the task that the system is running
 * at any time.
 */
void updateTaskLCD(int task)
{
  myGLCD.clrScr();
  updateModeLCD();
  myGLCD.setFont(SmallFont);
  if (task == 0)
  {
    myGLCD.print("Initializating", 0, 15);
    myGLCD.print("    modules", 0, 25);
    myGLCD.print("     ...", 0, 35);
  }
  if (task == 1)
  {
    myGLCD.print("    Sending", 0, 15);
    myGLCD.print("     data", 0, 25);
    myGLCD.print("      ...", 0, 35);
  }
  if (task == 2)
  {
    myGLCD.print("    Saving", 0, 15);
    myGLCD.print("     data", 0, 25);
    myGLCD.print("    in SD", 0, 35);
  }
  if (task == 3)
  {
    myGLCD.print("  Measuring", 0, 15);
    myGLCD.print("   channels", 0, 25);
    myGLCD.print("     ...", 0, 35);
  }
  myGLCD.update();
}

/*              updateConfigLCD
 * ----------------------------------------
 * Updates  the LCD display in order to 
 * show the channels that are active.
 */
void updateConfigLCD()
{
  ResetWTDG();
  myGLCD.clrScr();
  updateModeLCD();
  myGLCD.setFont(SmallFont);
  // SMU
  if (smu)
  {
    myGLCD.print("     SMU", 0, 12);
  }
  else
  {
    myGLCD.print("ScrewTerminal", 0, 12);
  }
  // ADC
  myGLCD.print("ADC Chs: ", 0, 21);
  if (ADC_2) myGLCD.print("1", 50, 21);
  if (ADC_3) myGLCD.print(" | 2", 57, 21);
  // ARDU
  myGLCD.print("ArduChs: ", 0, 30);
  if ( ARDU_A8) myGLCD.print("1", 48, 30);
  if ( ARDU_A9) myGLCD.print("2", 56, 30);
  if ( ARDU_A10) myGLCD.print("3", 64, 30);
  if ( ARDU_A11) myGLCD.print("4", 72, 30);
  // Multi
  myGLCD.print("+-15Chs:", 0, 39);
  if ( multi_E5) myGLCD.print("1", 46, 39);
  if ( multi_E6) myGLCD.print("2", 52, 39);
  if ( multi_E7) myGLCD.print("3", 58, 39);
  if ( multi_E8) myGLCD.print("4", 64, 39);
  if ( multi_E3) myGLCD.print("5", 70, 39);
  if ( multi_E4) myGLCD.print("6", 76, 39);
  myGLCD.update();
}
#endif //LCD
