void initSD()
{
  pinMode(pinCS, OUTPUT);
  //  Serial.print("Initializing SD card...");
  //  if (!SD.begin(4)) {
  //    Serial.println("initialization failed!");
  //    return;
  //  }
  //  Serial.println("initialization done.");
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }

  myFile = SD.open("test.txt", FILE_WRITE);     //HACER QUE CREE UN ARCHIVO VON LA HORA DE INIZIALIZACION

}

void saveToSD(int dayRTC, int monthRTC, int yearRTC, int hoursRTC, int minutesRTC, int secondsRTC, int ADCVal, float voltage)
{
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    //Serial.print("Writing to test.txt...");
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
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  delay(10);
}

void readSD()
{
  myFile = SD.open("test.txt");
  while (myFile.available()) {
    Serial.write(myFile.read());
  }
  //close the file:
  myFile.close();
}

