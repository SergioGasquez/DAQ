#ifdef COMGPRS
void ShowSerialData()
{
  while (SIM900.available() != 0)
  {
    Serial.write(char (SIM900.read()));
  }
}
void initSIM900()
{
  SIM900.begin(19200);
  delay(2000);
  SIM900.println("AT");
  delay(2500);
  ShowSerialData();
  delay(2500);
  SIM900.println("AT+CIPMODE=0");
  delay(2500);
  ShowSerialData();
  delay(2500);
  SIM900.println("AT+CIPMUX=0");
  delay(2500);
  ShowSerialData();
  delay(2500);
  SIM900.println("AT+CGATT=1");
  delay(2500);
  ShowSerialData();
  delay(2500);
  SIM900.println("AT+CREG?");
  delay(2500);
  ShowSerialData();
  delay(2500);
  SIM900.println("AT+CGATT?");
  delay(2500);
  ShowSerialData();
  delay(2500);
  SIM900.println("AT+CSTT=\"internettph\",\"\",\"\"");
  delay(2500);
  ShowSerialData();
  delay(5000);
  SIM900.println("AT+CIICR");
  delay(5000);
  ShowSerialData();
  delay(5000);
  SIM900.println("AT+CIFSR"); 
  delay(5000);
  ShowSerialData();
  delay(5000);
}


void sendConfig()
{
  char strFrame1[1024];
  char auxStr [1024];
  strcpy(strFrame1, "GET https://api.thingspeak.com/update?api_key=N3H188LNH80SFR5P");
  strcat(strFrame1, "&field1=");
  strcat(strFrame1, confStr1);
  strcat(strFrame1, "&field2=");
  strcat(strFrame1, confStr2);
  strcat(strFrame1, "\r\n\x1A");
  Serial.println(strFrame1);

  SIM900.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
  delay(5500);
  ShowSerialData();
  delay(5500);
  SIM900.println("AT+CIPSEND");
  delay(3000);
  ShowSerialData();
  delay(3000);
  SIM900.print(strFrame1);
  delay(5000);
  ShowSerialData();
  delay(5000);
  SIM900.println("AT+CIPSHUT");
  delay(5000);
  ShowSerialData();
  delay(5000);
}


void sendData()
{
  ResetWTDG();
  char strFrame1[1024];
  char strFrame2[1024];
  char auxStr [1024];
  strcpy(strFrame1, "GET https://api.thingspeak.com/update?api_key=N3H188LNH80SFR5P");  // Channel 1
  if (smu)
  {
    strcat(strFrame1, "&field3=");
    strcat(strFrame1, itoa(valSMU, auxStr, 10));
  }
  if (ADC_2)
  {
    strcat(strFrame1, "&field4=");
    strcat(strFrame1, itoa(valADC_2, auxStr, 10));
  }
  if (ADC_3)
  {
    strcat(strFrame1, "&field5=");
    strcat(strFrame1, itoa(valADC_3, auxStr, 10));
  }
  if (ARDU_A8)
  {
    strcat(strFrame1, "&field6=");
    strcat(strFrame1, itoa(valArdu_A8, auxStr, 10));
  }
  if (ARDU_A9)
  {
    strcat(strFrame1, "&field7=");
    strcat(strFrame1, itoa(valArdu_A9, auxStr, 10));
  }
  if (ARDU_A10)
  {
    strcat(strFrame1, "&field8=");
    strcat(strFrame1, itoa(valArdu_A10, auxStr, 10));
  }
  strcat(strFrame1, "\r\n\x1A");
  strcpy(strFrame2, "GET https://api.thingspeak.com/update?api_key=PRNZCJJ6AVI21P5W");  // Channel 2
  if (ARDU_A11)
  {
    strcat(strFrame2, "&field1=");
    strcat(strFrame2, itoa(valArdu_A11, auxStr, 10));
  }
  if (multi_E5)
  {
    strcat(strFrame2, "&field2=");
    strcat(strFrame2, itoa(valMulti_E5, auxStr, 10));
  }
  if (multi_E6)
  {
    strcat(strFrame2, "&field3=");
    strcat(strFrame2, itoa(valMulti_E6, auxStr, 10));
  }
  if (multi_E7)
  {
    strcat(strFrame2, "&field4=");
    strcat(strFrame2, itoa(valMulti_E7, auxStr, 10));
  }
  if (multi_E8)
  {
    strcat(strFrame2, "&field5=");
    strcat(strFrame2, itoa(valMulti_E8, auxStr, 10));
  }
  if (multi_E3)
  {
    strcat(strFrame2, "&field6=");
    strcat(strFrame2, itoa(valMulti_E3, auxStr, 10));
  }
  if (multi_E4)
  {
    strcat(strFrame2, "&field7=");
    strcat(strFrame2, itoa(valMulti_E4, auxStr, 10));
  }
  strcat(strFrame2, "\r\n\x1A");

  Serial.print("strFrame1: "); Serial.println(strFrame1);
  Serial.print("strFrame2: "); Serial.println(strFrame2);

  ResetWTDG();
  // FRAME 1
  SIM900.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
  delay(5500);
  ShowSerialData();
  delay(5500);
  SIM900.println("AT+CIPSEND");
  delay(3000);
  ShowSerialData();
  delay(3000);
  SIM900.print(strFrame1);
  delay(3000);
  ShowSerialData();
  delay(5000);
  SIM900.println("AT+CIPSHUT");
  delay(5000);
  ShowSerialData();
  delay(5000);
  // FRAME 2
  ResetWTDG();
  SIM900.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
  delay(5500);
  SIM900.println("AT+CIPSEND");
  delay(3000);
  ShowSerialData();
  delay(3000);
  SIM900.print(strFrame2);
  delay(5000);
  ShowSerialData();
  delay(5000);
  SIM900.println("AT+CIPSHUT");
  delay(5000);
  ShowSerialData();
  delay(5000);
}

#endif //COMGPRS
