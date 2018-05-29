#ifdef MULTIPLEXER
void initMultiplexer()
{
  pinMode(enablePin, OUTPUT);
  pinMode(multiplexerA0, OUTPUT);
  pinMode(multiplexerA1, OUTPUT);
  pinMode(multiplexerA2, OUTPUT);

  digitalWrite(enablePin, HIGH);
}

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
  else      // Default channel is 1
  {
#if DEBUGGING
    Serial.println("Canal especificado incorrecto. Debe de estar entre 1 y 8. Se ha asigando el canal 1 (por defecto)");
#endif //DEBUGGING
    digitalWrite(multiplexerA0, LOW);
    digitalWrite(multiplexerA1, LOW);
    digitalWrite(multiplexerA2, LOW);
  }
}
#endif //MULTIPLEXER
