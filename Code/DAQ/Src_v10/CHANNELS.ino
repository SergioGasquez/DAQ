float readADC(int channel)
{
  ResetWTDG();
  float aux = 0;
  int i = 0;
  for (i = 0; i <= 99; i++)
  {
    aux += ads.readADC_SingleEnded(channel);
  }
  aux = aux / 100;
  return aux;
}

float readAnalog(int channel)
{
  ResetWTDG();
  float aux = 0;
  int i = 0;
  for (i = 0; i <= 99; i++)
  {
    aux += analogRead(channel);
  }
  aux = aux / 100;
  return aux;
}



void measureChannels()
{
  ResetWTDG();
  if (smu)
  {
    valSMU = readADC(0);
  }
  if (ADC_2)
  {
    valADC_2 = readADC(2);
  }
  if (ADC_3)
  {
    valADC_3 = readADC(3);
  }
  if (ARDU_A8)
  {
    valArdu_A8 = readAnalog(8);
  }
  if (ARDU_A9)
  {
    valArdu_A9 = readAnalog(9);
  }
  if (ARDU_A10)
  {
    valArdu_A10 = readAnalog(10);
  }
  if (ARDU_A11)
  {
    valArdu_A11 = readAnalog(11);
  }
  if (multi_E5)
  {
    setChannel(5);
    delay(100);
    valMulti_E5 = readADC(1);
  }
  if (multi_E6)
  {
    setChannel(6);
    delay(100);
    valMulti_E6 = readADC(1);
  }
  if (multi_E7)
  {
    setChannel(7);
    delay(100);
    valMulti_E7 = readADC(1);
  }
  if (multi_E8)
  {
    setChannel(8);
    delay(100);
    valMulti_E8 = readADC(1);
    Serial.print("valMulti_E8"); Serial.println(valMulti_E8);
  }
  if (multi_E3)
  {
    setChannel(3);
    delay(100);
    valMulti_E3 = readADC(1);
    Serial.print("valMulti_E3"); Serial.println(valMulti_E3);
  }
  if (multi_E4)
  {
    setChannel(4);
    delay(100);
    valMulti_E4 = readADC(1);
    Serial.print("valMulti_E4"); Serial.println(valMulti_E4);
  }
}



//  if (smu)
//  {
//
//  }
//  if (ADC_2)
//  {
//  }
//  if (ADC_3)
//  {
//  }
//  if (ARDU_A8)
//  {
//  }
//  if (ARDU_A9)
//  {
//  }
//  if (ARDU_A10)
//  {
//  }
//  if (ARDU_A11)
//  {
//  }
//  if (multi_E5)
//  {
//  }
//  if (multi_E6)
//  {
//  }
//  if (multi_E7)
//  {
//  }
//  if (multi_E8)
//  {
//  }
//  if (multi_E3)
//  {
//  }
//  if (multi_E4)
//  {
//  }

