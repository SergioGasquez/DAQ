#ifdef MULTIPLEXER

/*              initMultiplexer
 * ----------------------------------------
 * Initializes the ADG408 by definning
 * the selected inputs as outputs
 * and enabling the multiplxer.
 */
void initMultiplexer()
{
  pinMode(enablePin, OUTPUT);
  pinMode(multiplexerA0, OUTPUT);
  pinMode(multiplexerA1, OUTPUT);
  pinMode(multiplexerA2, OUTPUT);

  digitalWrite(enablePin, HIGH);
#if DEBUGGING
  Serial.println("Multiplexer Initialized");
#endif //DEBUGGING
}


/*              setChannel
 * ----------------------------------------
 * Funtion that selects which channel of
 * the multiplexer will be conected to
 * the output.
 */
void setChannel(byte channel)
{
  ResetWTDG();
  if (channel == 1)
  {
    digitalWrite(multiplexerA0, LOW);
    digitalWrite(multiplexerA1, LOW);
    digitalWrite(multiplexerA2, LOW);
  }
  else if (channel == 2)
  {
    digitalWrite(multiplexerA0, HIGH);
    digitalWrite(multiplexerA1, LOW);
    digitalWrite(multiplexerA2, LOW);
  }
  else if (channel == 3)
  {
    digitalWrite(multiplexerA0, LOW);
    digitalWrite(multiplexerA1, HIGH);
    digitalWrite(multiplexerA2, LOW);
  }
  else if (channel == 4)
  {
    digitalWrite(multiplexerA0, HIGH);
    digitalWrite(multiplexerA1, HIGH);
    digitalWrite(multiplexerA2, LOW);
  }
  else if (channel == 5)
  {
    digitalWrite(multiplexerA0, LOW);
    digitalWrite(multiplexerA1, LOW);
    digitalWrite(multiplexerA2, HIGH);
  }
  else if (channel == 6)
  {
    digitalWrite(multiplexerA0, HIGH);
    digitalWrite(multiplexerA1, LOW);
    digitalWrite(multiplexerA2, HIGH);
  }
  else if (channel == 7)
  {
    digitalWrite(multiplexerA0, LOW);
    digitalWrite(multiplexerA1, HIGH);
    digitalWrite(multiplexerA2, HIGH);
  }
  else if (channel == 8)
  {
    digitalWrite(multiplexerA0, HIGH);
    digitalWrite(multiplexerA1, HIGH);
    digitalWrite(multiplexerA2, HIGH);
  }
  else
  {
#if DEBUGGING
    Serial.println("Error. Wrong channel");
#endif //DEBUGGING
  }
}
#endif //MULTIPLEXER
