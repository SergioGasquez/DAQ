#ifdef RTC
void initRTC()
{
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }
 
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Fijar a fecha y hora de compilacion

#if DEBUGGING
  Serial.println("RTC Initialized");
#endif //DEBUGGING


}

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
