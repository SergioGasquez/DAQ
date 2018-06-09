
/*                 waitForKey
   ----------------------------------------
   Function that waits for the user to
   introduce either a '1' or a '2' in
   the Serial Monitor.Otherwise
   it will show an error.

   Inputs:
    - variable(boolean): variable where the result will be stored.

   Outputs:
    - variable(boolean): final of the boolean after reading what the user
    introduced.
*/
boolean waitForKey(boolean variable)
{
  long tiempo = millis();
  int ByteReceived;
  char aux;
  Serial.flush();
  while (char( ByteReceived) != '1' && char(ByteReceived) != '2')
  {
    if (Serial.available() > 0)
    {
      ByteReceived = Serial.read();
      aux = char(ByteReceived);
      if (aux == '1') // Single Quote! This is a character.
      {
        variable = true;
      }

      if (aux == '2')
      {
        variable = false;
      }
      else if ( aux != '1' && millis() - tiempo > 1000)
      {
        Serial.print("Incorrect option");
        tiempo = millis();
      }

      Serial.println();    // End the line
      while (Serial.available() > 0)
      {
        byte dummyread = Serial.read();
      }
    }

  }
  return variable;
}

/*                 checkIfConnected
   ----------------------------------------
   Defines in which mode the system will be operating
   by reading the Serial Monitor for 10 secs.
*/
void checkIfConnected()
{
  Serial.println("Send something in the next 10 seconds in order to start the configuration.");
  Serial.println("Otherwise, the previus configuration will be loaded from the EEPROM.");
  long timeNow = millis();
  while (millis() - timeNow < 10000)
  {

    if (!Serial.available())
    {
      autonomousMode = true;
    }
    else
    {
      autonomousMode = false;
      break;
    }
  }
#if DEBUGGING
  Serial.print("Autonomous mode: "); Serial.println(autonomousMode);
#endif // DEBUGGING
  delay(1000);
}


/*                 askConfiguration
   ----------------------------------------
   Ask for the user to write a new configuration
   of the channels. The configuration is guided
   by messages.
*/
void askConfiguration()
{
  Serial.println("-----------Configuration--------------");
  Serial.println("Write '1' or '2' to choose the desired option :");

  Serial.println("Do you want to use the SMU or the screwdriver terminal output?");
  Serial.print("1)SMU \n2)Scredriver terminal output");
  smu = waitForKey(smu);
  if ( smu == 1)
  {
    strcat(confStr1, "1");
    Serial.println("You have choosen: SMU");
    Serial.println("-------------------------------------------");

    // S1 of the multiplexer2
    Serial.println("In the SMU. Do you want to do a voltage sweep (form -15V to 0V) or track it over time?");
    Serial.print("1)Voltage sweep \n2)Track");
    typeSMU = waitForKey(typeSMU);
    if ( typeSMU == 1)
    {
      Serial.println("You have choosen: Voltage sweep");
    }
    if ( typeSMU == 0)
    {
      Serial.println("You have choosen: Track over time");
    }
    Serial.println("-------------------------------------------");
  }
  if ( smu == 0)
  {
    strcat(confStr1, "0");
    Serial.println("You have choosen: Scredriver terminal output");
    Serial.println("-------------------------------------------");

    // S2 of the multiplexer2  }
  }
  Serial.println("Do you want to use the channel 1 of the ADC?");      // ADC_2
  Serial.println("1) Yes \n2) No");
  ADC_2 = waitForKey(ADC_2);
  if ( ADC_2 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Channel 1 of the ADC will be on");
  }
  if ( ADC_2 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("Channel 1 of the ADC will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 2 of the ADC?");      // ADC_3
  Serial.println("1) Yes \n2) No");
  ADC_3 = waitForKey(ADC_3);
  if ( ADC_3 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Channel 2 of the ADC will be on");
  }
  if ( ADC_3 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("Channel 2 of the ADC will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 1 of the Arduino?");      // A5
  Serial.println("1) Yes \n2) No");
  ARDU_A8 = waitForKey(ARDU_A8);
  if ( ARDU_A8 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Channel 1 of the Arduino will be on");
  }
  if ( ARDU_A8 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("Channel 1 of the Arduino will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 1 of the Arduino?");      // A6
  Serial.println("1) Yes \n2) No");
  ARDU_A9 = waitForKey(ARDU_A9);
  if ( ARDU_A9 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Channel 2 of the Arduino will be on");
  }
  if ( ARDU_A9 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("Channel 2 of the Arduino will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 3 of the Arduino?");      // A7
  Serial.println("1) Yes \n2) No");
  ARDU_A10 = waitForKey(ARDU_A10);
  if ( ARDU_A10 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Channel 3 of the Arduino will be on");
  }
  if ( ARDU_A10 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("Channel 3 of the Arduino will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 4 of the Arduino?");      // A8
  Serial.println("1) Yes \n2) No");
  ARDU_A11 = waitForKey(ARDU_A11);
  if ( ARDU_A11 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Channel 3 of the Arduino will be on");
  }
  if ( ARDU_A11 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("Channel 3 of the Arduino will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 1 of the +-15 Input?");      // A3
  Serial.println("1) Yes \n2) No");
  multi_E5 = waitForKey(multi_E5);
  if ( multi_E5 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Channel 1 of the +-15 Input will be on");
  }
  if ( multi_E5 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("Channel 1 of the +-15 Input will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 2 of the +-15 Input?");      //  A4
  Serial.println("1) Yes \n2) No");
  multi_E6 = waitForKey(multi_E6);
  if ( multi_E6 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Channel 2 of the +-15 Input will be on");
  }
  if ( multi_E6 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("Channel 2 of the +-15 Input will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 3 of the +-15 Input?");      // CORESPONDE AL A8
  Serial.println("1) Yes \n2) No");
  multi_E7 = waitForKey(multi_E7);
  if ( multi_E7 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Channel 3 of the +-15 Input will be on");
  }
  if ( multi_E7 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("Channel 3 of the +-15 Input will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 4 of the +-15 Input?");      // CORESPONDE AL A8
  Serial.println("1) Yes \n2) No");
  multi_E8 = waitForKey(multi_E8);
  if ( multi_E8 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Channel 4 of the +-15 Input will be on");
  }
  if ( multi_E8 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("Channel 4 of the +-15 Input will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 5 of the +-15 Input?");      // CORESPONDE AL A8
  Serial.println("1) Yes \n2) No");
  multi_E3 = waitForKey(multi_E3);
  if ( multi_E3 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Channel 5 of the +-15 Input will be on");
  }
  if ( multi_E3 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("Channel 5 of the +-15 Input will be off");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Do you want to use the channel 6 of the +-15 Input?");      // CORESPONDE AL A8
  Serial.println("1) Yes \n2) No");
  multi_E4 = waitForKey(multi_E4);
  if ( multi_E4 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Channel 6 of the +-15 Input will be on");
  }
  if ( multi_E4 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("Channel 6 of the +-15 Input will be off");
  }

#if DEBUGGING
  Serial.print("confStr1: "); Serial.println(confStr1);
  Serial.print("confStr2: "); Serial.println(confStr2);
#endif //DEBUGGING
}

/*                 configureSystem
   ----------------------------------------
   Configures the system by using the
   previous functions.
*/
void configureSystem()
{
  if (autonomousMode)
  {
    readConfigEEPROM();
  }
  else
  {
    askConfiguration();
    saveConfigEEPROM();
  }
  updateConfigLCD();
  if (smu)
  {
    pinMode(multiplexer2Pin, OUTPUT);
    digitalWrite(multiplexer2Pin, LOW);
  }
  else
  {
    pinMode(multiplexer2Pin, OUTPUT);
    digitalWrite(multiplexer2Pin, HIGH);
  }
}







