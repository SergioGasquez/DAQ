#ifdef RTC
void initRTC()
{
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  // Si se ha perdido la corriente, fijar fecha y hora
  if (rtc.lostPower()) {
    // Fijar a fecha y hora de compilacion
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
    //rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
  }
#if DEBUGGING
  Serial.println("RTC Initialized");
#endif //DEBUGGING


}

void getTime()
{
  DateTime now = rtc.now();

  dayRTC = now.day();
  monthRTC = now.month();
  yearRTC = now.year();
  hoursRTC = now.hour();
  minutesRTC = now.minute();
  secondsRTC = now.second();


}

#endif //RTC
