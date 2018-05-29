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
        Serial.print("Opcion Incorrecta");
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


void checkIfConnected()
{
  Serial.println("Introduzca algo en la consola en los proximos 10 segundos para iniciar la configuracion:");
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
  Serial.print("Autonomous mode? "); Serial.println(autonomousMode);
#endif // DEBUGGING
  delay(1000);
}

void askConfiguration()
{
  Serial.println("-----------Modo Configuración--------------");
  Serial.println("Escriba '1' o '2' para elegir la opción deseada en cada elección:");

  Serial.println("¿Desea usar la SMU o la salida amplificada de +-15V por terminal de tornillo?");
  Serial.print("1)SMU \n2)Salida por terminal de tornillo de la señal de +-15V");
  smu = waitForKey(smu);
  if ( smu == 1)
  {
    strcat(confStr1, "1");
    Serial.println("SMU seleccionado");
    // Salida S1 del multiplexor 2
  }
  if ( smu == 0)
  {
    strcat(confStr1, "0");
    Serial.println("Salida amplificada por terminal de tornillo selecionado");
    // Salida S2 del multiplexor 2
  }
  Serial.println("-------------------------------------------");
  Serial.println("¿Desea usar el canal 1 del ADC?");      // CORESPONDE AL CANAL 3
  Serial.println("1) Si \n2) No");
  ADC_2 = waitForKey(ADC_2);
  if ( ADC_2 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Canal 1 del ADC en uso");
  }
  if ( ADC_2 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("No se usará el Canal 1 del ADC");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 2 del ADC");      // CORESPONDE AL CANAL 4
  Serial.println("1) Si \n2) No");
  ADC_3 = waitForKey(ADC_3);
  if ( ADC_3 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Canal 2 del ADC en uso");
  }
  if ( ADC_3 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("No se usará el Canal 2 del ADC");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 1 del Arduino");      // CORESPONDE AL A8
  Serial.println("1) Si \n2) No");
  ARDU_A8 = waitForKey(ARDU_A8);
  if ( ARDU_A8 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Canal 1 del Arduino en uso");
  }
  if ( ARDU_A8 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("No se usará el Canal 1 del Arduino");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 2 del Arduino");      // CORESPONDE AL A9
  Serial.println("1) Si \n2) No");
  ARDU_A9 = waitForKey(ARDU_A9);
  if ( ARDU_A9 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Canal 2 del Arduino en uso");
  }
  if ( ARDU_A9 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("No se usará el Canal 2 del Arduino");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 3 del Arduino");      // CORESPONDE AL A10
  Serial.println("1) Si \n2) No");
  ARDU_A10 = waitForKey(ARDU_A10);
  if ( ARDU_A10 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Canal 3 del Arduino en uso");
  }
  if ( ARDU_A10 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("No se usará el Canal 3 del Arduino");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 4 del Arduino");      // CORESPONDE AL A11
  Serial.println("1) Si \n2) No");
  ARDU_A11 = waitForKey(ARDU_A11);
  if ( ARDU_A11 == 1)
  {
    strcat(confStr1, "1");
    Serial.println("Canal 4 del Arduino en uso");
  }
  if ( ARDU_A11 == 0)
  {
    strcat(confStr1, "0");
    Serial.println("No se usará el Canal 4 del Arduino");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 1 del Multiplexor");      // CORESPONDE AL 5
  Serial.println("1) Si \n2) No");
  multi_E5 = waitForKey(multi_E5);
  if ( multi_E5 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Canal 1 del multiplexor en uso");
  }
  if ( multi_E5 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("No se usará el canal 1 del multiplexor");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 2 del Multiplexor");      // CORESPONDE AL 6
  Serial.println("1) Si \n2) No");
  multi_E6 = waitForKey(multi_E6);
  if ( multi_E6 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Canal 2 del multiplexor en uso");
  }
  if ( multi_E6 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("No se usará el canal 2 del multiplexor");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 3 del Multiplexor");      // CORESPONDE AL 7
  Serial.println("1) Si \n2) No");
  multi_E7 = waitForKey(multi_E7);
  if ( multi_E7 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Canal 3 del multiplexor en uso");
  }
  if ( multi_E7 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("No se usará el canal 3 del multiplexor");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 4 del Multiplexor");      // CORESPONDE AL 8
  Serial.println("1) Si \n2) No");
  multi_E8 = waitForKey(multi_E8);
  if ( multi_E8 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Canal 4 del multiplexor en uso");
  }
  if ( multi_E8 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("No se usará el canal 4 del multiplexor");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 5 del Multiplexor");      // CORESPONDE AL 3
  Serial.println("1) Si \n2) No");
  multi_E3 = waitForKey(multi_E3);
  if ( multi_E3 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Canal 5 del multiplexor en uso");
  }
  if ( multi_E3 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("No se usará el canal 5 del multiplexor");
  }
  Serial.println("-------------------------------------------");
  Serial.println("Desea usar el canal 6 del Multiplexor");      // CORESPONDE AL 4
  Serial.println("1) Si \n2) No");
  multi_E4 = waitForKey(multi_E4);
  if ( multi_E4 == 1)
  {
    strcat(confStr2, "1");
    Serial.println("Canal 6 del multiplexor en uso");
  }
  if ( multi_E4 == 0)
  {
    strcat(confStr2, "0");
    Serial.println("No se usará el canal 6 del multiplexor");
  }

#if DEBUGGING
  Serial.print("confStr1: "); Serial.println(confStr1);
  Serial.print("confStr2: "); Serial.println(confStr2);
#endif //DEBUGGING
}

void configureSystem()
{
  if (autonomousMode)
  {
    readConfigEEPROM();
    Serial.println("Se ha leido la configuración");
  }
  else
  {
    askConfiguration();
    saveConfigEEPROM();
  }
  if (smu)                                                          // COMPROBAR SI LAS SALIDAS ESTAN CONECTADAS ASI EN LA PCB O AL CONTRARIO
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







