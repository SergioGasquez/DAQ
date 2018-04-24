#ifdef microSD
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

  //myFile = SD.open(fileName, FILE_WRITE); // ES NECESARIO?


}

void saveToSD()
{
  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) {
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
#ifdef ADC_A0
    myFile.print(valADC_A0);
    myFile.print(",");
#endif //ADC_A0
#ifdef ADC_A1
    myFile.print(valADC_A1);
    myFile.print(",");
#endif //ADC_A1
#ifdef ADC_A2
    myFile.print(valADC_A2);
    myFile.print(",");
#endif //ADC_A2
#ifdef ADC_A3
    myFile.print(valADC_A3);
    myFile.print(",");
#endif //ADC_A3
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
