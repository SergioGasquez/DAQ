#ifdef COMGPRS
void ShowSerialData()
{
  while (SIM900.available() != 0) /* If data is available on serial port */
    Serial.write(char (SIM900.read())); /* Print character received on to the serial monitor */
}

void initSIM900()
{
  SIM900.begin(19200);  /* Define baud rate for software serial communication */
  delay(2000);
  //Serial.println("AT");
  SIM900.println("AT"); /* Check Communication */
  delay(2500);
  ShowSerialData(); /* Print response on the serial monitor */
  delay(2500);
  //Serial.println("AT+CIPMODE=0");
  SIM900.println("AT+CIPMODE=0"); /* Non-Transparent (normal) mode for TCP/IP application */
  delay(2500);
  ShowSerialData();
  delay(2500);
  //Serial.print("AT+CIPMUX=0");
  SIM900.println("AT+CIPMUX=0");  /* Single TCP/IP connection mode */
  delay(2500);
  ShowSerialData();
  delay(2500);
  //Serial.print("AT+CGATT=1\\r\\n");
  SIM900.println("AT+CGATT=1"); /* Attach to GPRS Service */
  delay(2500);
  ShowSerialData();
  delay(2500);
  //Serial.print("AT+CREG?\\r\\n");
  SIM900.println("AT+CREG?"); /* Network registration status */
  delay(2500);
  ShowSerialData();
  delay(2500);
  //Serial.print("AT+CGATT?\\r\\n");
  SIM900.println("AT+CGATT?");  /* Attached to or detached from GPRS service */
  delay(2500);
  ShowSerialData();
  delay(2500);
  //Serial.print("AT+CSTT=\"internettph\",\"\",\"\"\\r\\n");
  SIM900.println("AT+CSTT=\"internettph\",\"\",\"\""); /* Start task and set APN */
  delay(2500);
  ShowSerialData();
  delay(5000);
  //Serial.print("AT+CIICR\\r\\n");
  SIM900.println("AT+CIICR"); /* Bring up wireless connection with GPRS */
  delay(5000);
  ShowSerialData();
  delay(5000);
  //Serial.print("AT+CIFSR\\r\\n");
  SIM900.println("AT+CIFSR"); /* Get local IP address */
  delay(5000);
  ShowSerialData();
  delay(5000);
}

void sendData(long field1_1, long field1_2, int field1_3, int field1_4, int field1_5, int field1_6, int field1_7, int field1_8, int field2_1, int field2_2, int field2_3, int field2_4,int field2_5,int field2_6,int field2_7)
{
  char strFrame1[1024];
  char strFrame2[1024];
  char auxStr [1024];
  strcpy(strFrame1, "GET https://api.thingspeak.com/update?api_key=N3H188LNH80SFR5P");  // Channel 1
  if (field1_1 != NULL)
  {
    strcat(strFrame1, "&field1=");
    strcat(strFrame1, ltoa(field1_1, auxStr, 10));
  }
  if (field1_2 != NULL)
  {
    strcat(strFrame1, "&field2=");
    strcat(strFrame1, ltoa(field1_2, auxStr, 10));
  }

  strcat(strFrame1, "\r\n\x1A");
  Serial.println(strFrame1);


  //Serial.print("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"\\r\\n");
  SIM900.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");  /* Start up TCP connection */
  delay(5500);
  ShowSerialData();
  delay(5500);
  //Serial.print("AT+CIPSEND\\r\\n");
  SIM900.println("AT+CIPSEND"); /* Send data through TCP connection */
  delay(2000);
  ShowSerialData();
  delay(2000);
  //Serial.print("GET https://api.thingspeak.com/update?api_key=N3H188LNH80SFR5P&field1=23\\r\\n");
  SIM900.print(strFrame1);  /* URL for data to be read from */
  delay(5000);
  ShowSerialData();
  delay(5000);
  //Serial.print("AT+CIPSHUT\\r\\n");
  SIM900.println("AT+CIPSHUT"); /* Deactivate GPRS PDP content */
  delay(5000);
  ShowSerialData();
  delay(5000);
}

#endif //COMGPRS
