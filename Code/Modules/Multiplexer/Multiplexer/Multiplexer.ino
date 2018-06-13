int enablePin = 35;
int multiplexerA0 = 39;
int multiplexerA1 = 41;
int multiplexerA2 = 43;



void initMultiplexer()
{
  pinMode(enablePin, OUTPUT);
  pinMode(multiplexerA0, OUTPUT);
  pinMode(multiplexerA1, OUTPUT);
  pinMode(multiplexerA2, OUTPUT);

  digitalWrite(enablePin, HIGH);
  Serial.println("Multiplexer Initialized");
}


/*              setChannel
   ----------------------------------------
   Funtion that selects which channel of
   the multiplexer will be conected to
   the output.
*/
void setChannel(byte channel)
{                        
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
    Serial.println("Error. Wrong channel");
  }
}

void setup() {
  initMultiplexer();
  Serial.begin(9600);
}

void loop() {
  Serial.println("5");
  setChannel(5);
  delay(5000);
  Serial.println("6");
  setChannel(6);
  delay(5000);
  Serial.println("7");
  setChannel(7);
  delay(5000);
  Serial.println("8");
  setChannel(8);
  delay(5000);
  Serial.println("3");
  setChannel(3);
  delay(5000);
  Serial.println("4");
  setChannel(3);
  delay(5000);

  
}
