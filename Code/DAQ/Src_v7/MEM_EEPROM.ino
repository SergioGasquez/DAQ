#ifdef MEM_EEPROM

#include <EEPROM.h>

#define EEPROM_LENGTH 4096

#define SMU_ADD 1
#define ADC_2_ADD 2
#define ADC_3_ADD 3
#define ARDU_8_ADD 4
#define ARDU_9_ADD 5
#define ARDU_10_ADD 6
#define ARDU_11_ADD 7
#define multi_E5_ADD 8
#define multi_E6_ADD 9
#define multi_E7_ADD 10
#define multi_E8_ADD 11
#define multi_E3_ADD 12
#define multi_E4_ADD 13

void readConfigEEPROM()
{
  smu = EEPROM.read(SMU_ADD);
  ADC_2 = EEPROM.read(ADC_2_ADD);
  ADC_3 = EEPROM.read(ADC_3_ADD);
  ARDU_A8 = EEPROM.read(ARDU_8_ADD);
  ARDU_A9 = EEPROM.read(ARDU_9_ADD);
  ARDU_A10 = EEPROM.read(ARDU_10_ADD);
  ARDU_A11 = EEPROM.read(ARDU_11_ADD);
  multi_E5 = EEPROM.read(multi_E5_ADD);
  multi_E6 = EEPROM.read(multi_E6_ADD);
  multi_E7 = EEPROM.read(multi_E7_ADD);
  multi_E8 = EEPROM.read(multi_E8_ADD);
  multi_E3 = EEPROM.read(multi_E3_ADD);
  multi_E4 = EEPROM.read(multi_E4_ADD);
#if DEBUGGING
  Serial.print("EEPROM leida");
#endif // DEBUGGING 

}


void saveConfigEEPROM()
{
  EEPROM.write(SMU_ADD, smu);
  EEPROM.write(ADC_2_ADD, ADC_2);
  EEPROM.write(ADC_3_ADD, ADC_3);
  EEPROM.write(ARDU_8_ADD, ARDU_A8);
  EEPROM.write(ARDU_9_ADD, ARDU_A9);
  EEPROM.write(ARDU_10_ADD, ARDU_A10);
  EEPROM.write(ARDU_11_ADD, ARDU_A11);
  EEPROM.write(multi_E5_ADD, multi_E5);
  EEPROM.write(multi_E6_ADD, multi_E6);
  EEPROM.write(multi_E7_ADD, multi_E7);
  EEPROM.write(multi_E8_ADD, multi_E8);
  EEPROM.write(multi_E3_ADD, multi_E3);
  EEPROM.write(multi_E4_ADD, multi_E4);
#if DEBUGGING
  Serial.print("La configuracion ha sido guardada en la EEPROM");
#endif // DEBUGGING
}


#endif // MEM_EEPROM
