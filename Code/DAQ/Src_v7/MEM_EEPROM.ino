#ifdef MEM_EEPROM

#include <EEPROM.h>
#define ADDRESS_KEY_EEPROM 0
#define KEY_WORD_EEPROM  42

#define EEPROM_LENGTH 4096

void resetEEPROM() 
{
  delay(1000);
  int address = 0;
  int initVal = 0;
  EEPROM.write( ADDRESS_KEY_EEPROM, KEY_WORD_EEPROM );

  for (address; address <  EEPROM_LENGTH; address++)
  {
    if (address != ADDRESS_KEY_EEPROM )
    {
      EEPROM.write(address, initVal);
    }
  }


  // LEER TODOS LOS DATOS DE LA EPROM


#if DEBUGGING
  Serial.println("EEPROM Reseteada");
#endif
}



void initEEPROM(){
  
    int lengthEEPROM = EEPROM.length();
    int key = EEPROM.read(ADDRESS_KEY_EEPROM);
  #if DEBUGGING
    Serial.print("El tamano de la EEPROM es: ");
    Serial.println(lengthEEPROM);
  #endif // DEBUGGING  
  
    Serial.print("Lectura: "); Serial.println(key);
    Serial.print("KEY_WORD_EEPROM: "); Serial.println(KEY_WORD_EEPROM);
    if (key != KEY_WORD_EEPROM)
    {
      #if DEBUGGING
          Serial.println("La EEPROM no ha sido inicializada ");
      #endif // DEBUGGING
      resetEEPROM();
      delay(1000);
  
    }
    else{
      #if DEBUGGING
          Serial.print("La EEPROM ya ha sido inicializada en otra ocasion\n");
      #endif // DEBUGGING 
        /// LEER CONFIGURACION
    }
  }



// HACER FUNCION PARA GUARDA LA CONFIGURACION








#endif // MEM_EEPROM
