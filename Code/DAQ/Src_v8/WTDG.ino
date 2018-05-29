void ResetWTDG()
{
  noInterrupts();
  ISRCounterWTDG = 0;
  interrupts();

}


void setWatchdog()
{
  MCUSR = 0;                                        // Allow changes, disable reset
  WDTCSR = bit (WDCE) | bit (WDE);                  // Set interrupt mode and an interval
  WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // Set WDIE, and 8 seconds delay
}



