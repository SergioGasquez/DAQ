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

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello!");
  
  dac.begin(0x62); // Default address for MCP4725A1 
  
  ads.begin();    // Initalice the adc
  
  Serial.println("Generating a ramp wave");
}

void loop(void) {
    uint32_t counter;
    int adc0;  // we read from the ADC, we have a sixteen bit integer as a result
    counter=0;
    for (counter = 0; counter < 4095; counter++)  // Ramp
    {
      dac.setVoltage(counter, false);             // We set the voltage at the counter value

      adc0 = ads.readADC_SingleEnded(0); // We read from the adc and normalize the voltage
      Voltage = (adc0 * 0.1875)/1000;

      Serial.print("\n Counter:");
      Serial.print(counter);
      Serial.print("\t ADC: "); 
      Serial.print(adc0);
      Serial.print("\tVoltage: ");
      Serial.print(Voltage, 7);  
  
      delay(10);
    }
}
