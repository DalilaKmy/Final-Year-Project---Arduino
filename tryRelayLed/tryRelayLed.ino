int RelayPin = 7;

void setup() {
  // Set RelayPin as an output pin
  pinMode(RelayPin, OUTPUT);
}

void loop() {
  
  // Let's turn off the relay...
  digitalWrite(RelayPin, HIGH);
  Serial.println("Relay Off");
  delay(2000);
  
  // Let's turn on the relay...
  digitalWrite(RelayPin, LOW);
  Serial.println("Relay On");
  delay(7000);
}
