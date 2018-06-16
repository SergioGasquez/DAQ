/*                 ResetWTDG
 * ----------------------------------------
 * Resets the watchdog counter.
 */
void ResetWTDG()
{
  noInterrupts();
  ISRCounterWTDG = 0;
  interrupts();

}
/*                 setWatchdog
 * ----------------------------------------
 * Sets the watchdog interrut at 8 secs.
 */
void setWatchdog()
{
  MCUSR = 0;                                          // Allow changes, disable reset
  WDTCSR = bit (WDCE) | bit (WDE);                    // Set interrupt mode and an interval
  WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);      // Set WDIE, and 8 seconds delay
}

/*                 cpuSleep
 * ----------------------------------------
 * Puts the Arduino CPU in to power saving
 * mode by sleeping it as deep as it is
 * possible and disabling the builtin
 * ADC.
 */
void cpuSleep(void) {

#if DEBUGGING
  //Serial.println("Sleeping CPU...");
  delay(50);
#endif // DEBUGGING

  sleep_disable();                                      // Cancel sleep as a precaution


  MCUSR = 0;                                            // Clear various "reset" flags
  WDTCSR = bit (WDCE) | bit (WDE);                      // Allow changes, disable reset
  WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);        // Set WDIE, and 8 seconds delay

  byte adcsra_save = ADCSRA;
  ADCSRA = 0;                                            // Disable ADC

  set_sleep_mode (SLEEP_MODE_PWR_DOWN);                  // Sets sleep mode

  noInterrupts ();
  sleep_enable();

  // turn off brown-out enable in software
  // MCUCR = bit (BODS) | bit (BODSE);
  //MCUCR = bit (BODS);
  interrupts ();                                          // Guarantees next instruction executed
  sleep_cpu ();                                           // Goes to sleep..

  // Wakes up
  ADCSRA = adcsra_save;                                   // Stop power reduction, Adc enable

#if DEBUGGING
  //Serial.println("CPU on...");
#endif // DEBUGGING

  ResetWTDG();

}
