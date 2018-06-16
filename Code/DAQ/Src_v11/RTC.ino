#ifdef RTC

/*              initRTC
 * ----------------------------------------
 * Initializes the DS3231 and sets the 
 * date and time as the date and time
 * in which the program was built and
 * uploaded to the Arduino
 */
void initRTC()
{
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }
 
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Sets the RTC hour to the date and time in which the program was built and uploaded to the Arduino

#if DEBUGGING
  Serial.println("RTC Initialized");
#endif //DEBUGGING


}


/*              getTime
 * ----------------------------------------
 * Obtains from the RTC the date and time
 * and stores it in the global variables
 * created for this purpose.
 */
void getTime()
{
  ResetWTDG();
  DateTime now = rtc.now();

  dayRTC = now.day();
  monthRTC = now.month();
  yearRTC = now.year();
  hoursRTC = now.hour();
  minutesRTC = now.minute();
  secondsRTC = now.second();
}

#endif //RTC
