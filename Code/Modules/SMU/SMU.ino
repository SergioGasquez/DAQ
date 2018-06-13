/**************************************************************************/
/*!
    @file     trianglewave.pde
    @author   Adafruit Industries
    @license  BSD (see license.txt)

    This example will generate a triangle wave with the MCP4725 DAC.

    This is an example sketch for the Adafruit MCP4725 breakout board
    ----> http://www.adafruit.com/products/935

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!
*/
/**************************************************************************/
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <Adafruit_ADS1015.h>

Adafruit_MCP4725 dac;
/*DAC*/
Adafruit_ADS1115 ads(0x48);
float Voltage = 0.0;
int multiplexer2Pin = 31;


int  dacVal;

void setup(void) {
  Serial.begin(9600);

  dac.begin(0x62); // Default address for MCP4725A1

  ads.begin();    // Initalice the adc

  pinMode(multiplexer2Pin, OUTPUT);
  digitalWrite(multiplexer2Pin, LOW);
  dacVal = 1500;
  dac.setVoltage(dacVal, false);
}


float readADC(int channel)
{
  float aux = 0;
  int i = 0;
  for (i = 0; i <= 99; i++)
  {
    aux += ads.readADC_SingleEnded(channel);
  }
  aux = aux / 100;
  return aux;
}

void loop(void) {
  uint32_t counter;
  float valADC_A0;
  float voltage;
  counter = 0;
  //  for (counter = 0; counter < 9; counter++)  // Ramp       [-15,0] V
  //  {
  //    dacVal = counter * 205;
  //    Serial.print(" \tDAC: "); Serial.print(dacVal);
  //    dac.setVoltage(dacVal, false);
  //    delay(500);
  //    valADC_A0 = readADC(0);
  //    Serial.print(" \t ");Serial.println(valADC_A0);
  //  }
  valADC_A0 = readADC(0);
  Serial.println(valADC_A0);
  delay(1000);


  //dacVal = 1200;
  //  for (counter = 0; counter < 16; counter++)  // Ramp       [-5,0] V
  //  {
  //    Serial.print(counter);
  //    dacVal += 45;
  //    Serial.print(" \tDAC: "); Serial.print(dacVal);
  //    dac.setVoltage(dacVal, false);             // We set the voltage at the counter valuex
  //    delay(500);
  //    valADC_A0 = readADC(0);
  //    voltage = valADC_A0 * 0.1875 / 1000;
  //    Serial.print("\t voltage: "); Serial.println(voltage);
  //
  //  }
}
