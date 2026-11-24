int potPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(potPin); // Read potentiometer (0 to 1023)
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);               // Delay based on dial position
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
