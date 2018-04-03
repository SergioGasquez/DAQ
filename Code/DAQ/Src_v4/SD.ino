void initSD()
{
  pinMode(pinCS, OUTPUT);

  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
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
  Serial.print("fileName: "); Serial.println(fileName);
  
  myFile = SD.open(fileName, FILE_WRITE); // ES NECESARIO?


}

void saveToSD(int dayRTC, int monthRTC, int yearRTC, int hoursRTC, int minutesRTC, int secondsRTC, int ADCVal, float voltage)
{
  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) {
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
    Serial.println("Error opening the file");
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

