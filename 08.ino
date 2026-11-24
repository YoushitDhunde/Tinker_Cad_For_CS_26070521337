// Pin definitions matching your circuit
const int sensorPin = A0;   // Soil moisture sensor signal pin
const int greenLedPin = 2;  // Green LED (Wet)
const int yellowLedPin = 3; // Yellow LED (Moderate)
const int redLedPin = 4;    // Red LED (Dry)
const int motorPin = 13;    // NPN transistor base controlling the DC motor/pump

// Moisture thresholds (Tinkercad sensor ranges from 0 to ~876)
const int dryThreshold = 300;
const int wetThreshold = 600;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(sensorPin);
  
  // Print sensor reading to Serial Monitor for calibration
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue < dryThreshold) {
    // Soil is dry: turn on Red LED and activate pump/motor
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(motorPin, HIGH);
  } 
  else if (moistureValue < wetThreshold) {
    // Soil moisture is moderate: turn on Yellow LED, pump off
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(motorPin, LOW);
  } 
  else {
    // Soil is wet: turn on Green LED, pump off
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(motorPin, LOW);
  }

  delay(500); // Wait half a second before next reading
}
