#include <Wire.h>
#include "SPI/SPI.h"
#include "SD/SD.h"
#include <Adafruit_MCP4725.h>
#include <Adafruit_ADS1015.h>

Adafruit_MCP4725 dac;       // DAC
Adafruit_ADS1115 ads(0x48); // ADC 0x48 is the default address
float Voltage = 0.0;        // Initialize Voltage
File myFile;                // Declare global file



void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  dac.begin(0x62); // Default address for MCP4725A1
  ads.begin();    // Initalice the adc
  Serial.println("Generating a ramp wave");

  // LOOP

  uint32_t counter;
  uint32_t dacVal;
  int adc0;  // we read from the ADC, we have a sixteen bit integer as a result
  counter = 0;
  for (counter = 0; counter < 40; counter++)  // Ramp
  {
    dacVal = counter * 100;
    dac.setVoltage(dacVal, false);             // We set the voltage at the counter value

    adc0 = ads.readADC_SingleEnded(0); // We read from the adc and normalize the voltage
    Voltage = (adc0 * 0.1875) / 1000;


    //Serial.print("triyting to reach test.txt...");
    myFile = SD.open("test.txt", FILE_WRITE);
    if (myFile) {
      //Serial.print("Writing to test.txt...");
      myFile.print("\n Counter:");
      myFile.print(dacVal);
      myFile.print("\t ADC: ");
      myFile.print(adc0);
      myFile.print("\t Voltage: ");
      myFile.print(Voltage, 7);
      myFile.print("\n");
      myFile.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }

    delay(10);
  }
  Serial.print("\n         ");
  Serial.print("\n         ");
  Serial.print("\n         ");
  Serial.print("\n         ");



  myFile = SD.open("test.txt");
  while (myFile.available()) {
    Serial.write(myFile.read());
  }
  //close the file:
  myFile.close();

}

void loop() {

}
