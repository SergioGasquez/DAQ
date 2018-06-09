/*                readADC
   ----------------------------------------
   Read an ADC channel 100 times in order to
   average and reduce the error.

   Inputs:
    - channel(int): number of the channel
    of the ADC that we want to read.
   Outputs:
    - aux (float): final read of the channel
    after the averaging is made.
*/

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

/*                readADC
   ----------------------------------------
   Read an Arduino analog channel 100 times
   in order to average and reduce the error.

   Inputs:
    - channel(int): number of the channel
    of the ADC that we want to read.
   Outputs:
    - aux (float): final read of the channel
    after the averaging is made.
*/

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

/*              measureChannels
   ----------------------------------------
   Saves in the global variables made
   for storing the channels values
   the actual value of the channel.

   It only saves active channels of
   the system.
*/



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
    if (!smu)
    {
      float aux;
      Serial.print("Channel 2: "); Serial.println(valADC_2);
      aux = valADC_2 * 0.1875 / 1000 ;
      Serial.print("Channel 2 Vol: "); Serial.println(aux);
      dacVal = aux * 4096 / 5;
      if (dacVal > 4096) dacVal = 4096;
      if (dacVal < 0) dacVal = 0;
      Serial.print("dacVal: "); Serial.println(dacVal);
      dac.setVoltage(dacVal, false);
      delay(3000);
    }
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
  }
  if (multi_E3)
  {
    setChannel(3);
    delay(100);
    valMulti_E3 = readADC(1);
  }
  if (multi_E4)
  {
    setChannel(4);
    delay(100);
    valMulti_E4 = readADC(1);
  }
}




