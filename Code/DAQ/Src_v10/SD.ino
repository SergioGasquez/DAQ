#ifdef microSD

void saveHeaders()
{
  ResetWTDG();
  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile)
  {
    
#ifdef RTC
    myFile.print("Date,Time,");
#endif //RTC
    if (smu) myFile.print("SMU,");
    if (ADC_2) myFile.print("ADC_1,");
    if (ADC_3) myFile.print("ADC_2,");
    if (ARDU_A8) myFile.print("Ardui_1,");
    if (ARDU_A9) myFile.print("Ardui_2,");
    if (ARDU_A10) myFile.print("Ardu_3,");
    if (ARDU_A11) myFile.print("Ardu_4,");
    if (multi_E5) myFile.print("Multi_1,");
    if (multi_E6) myFile.print("Multi_2,");
    if (multi_E7) myFile.print("Multi_3,");
    if (multi_E8) myFile.print("Multi_4,");
    if (multi_E3) myFile.print("Multi_5,");
    if (multi_E4) myFile.print("Multi_6,");
    myFile.print("\n");
    myFile.close();
  }
  else
  {
#if DEBUGGING
    Serial.println("Error opening the file to write headers");
#endif //DEBUGGING
  }
}








void initSD()
{
  pinMode(pinCS, OUTPUT);

  if (SD.begin())
  {
#if DEBUGGING
    Serial.println("SD card is ready to use.");
#endif //DEBUGGING

  } else
  {
#if DEBUGGING
    Serial.println("SD card initialization failed");
#endif //DEBUGGING
    return;
  }

  getTime();
  fileNameStr = dayRTC;
  fileNameStr += "-";
  fileNameStr += monthRTC;
  fileNameStr += "-";
  fileNameStr += yearRTC % 100;
  fileNameStr += ".txt";

  fileNameStr.toCharArray(fileName, sizeof(fileName));
#if DEBUGGING
  Serial.print("fileName: "); Serial.println(fileName);
#endif //DEBUGGING
  saveHeaders();
}




void saveToSD()
{
  ResetWTDG();
  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) {
    //DATA
#ifdef RTC
    myFile.print(dayRTC);
    myFile.print("/");
    myFile.print(monthRTC);
    myFile.print("/");
    myFile.print(yearRTC % 100);
    myFile.print(",");
    myFile.print(hoursRTC);
    myFile.print(":");
    myFile.print(minutesRTC);
    myFile.print(":");
    myFile.print(secondsRTC);
    myFile.print(",");
#endif //RTC
    if (smu)
    {
      myFile.print(valSMU);
      myFile.print(",");
    }
    if (ADC_2)
    {
      myFile.print(valADC_2);
      myFile.print(",");
    }
    if (ADC_3)
    {
      myFile.print(valADC_3);
      myFile.print(",");
    }
    if (ARDU_A8)
    {
      myFile.print(valArdu_A8);
      myFile.print(",");
    }
    if (ARDU_A9)
    {
      myFile.print(valArdu_A9);
      myFile.print(",");
    }
    if (ARDU_A10)
    {
      myFile.print(valArdu_A10);
      myFile.print(",");
    }
    if (ARDU_A11)
    {
      myFile.print(valArdu_A11);
      myFile.print(",");
    }
    if (multi_E5)
    {
      myFile.print(valMulti_E5);
      myFile.print(",");
    }
    if (multi_E6)
    {
      myFile.print(valMulti_E6);
      myFile.print(",");
    }
    if (multi_E7)
    {
      myFile.print(valMulti_E7);
      myFile.print(",");
    }
    if (multi_E8)
    {
      myFile.print(valMulti_E8);
      myFile.print(",");
    }
    if (multi_E3)
    {
      myFile.print(valMulti_E3);
      myFile.print(",");
    }
    if (multi_E4)
    {
      myFile.print(valMulti_E4);
      myFile.print(",");
    }
    myFile.print("\n");
    myFile.close();
  } else {
#if DEBUGGING
    Serial.println("Error opening the file");
#endif //DEBUGGING
  }

  delay(10);
}

void readSD()
{
  myFile = SD.open(fileName);
  while (myFile.available()) {
    Serial.write(myFile.read());
  }
  myFile.close();
}
#endif //microSD
