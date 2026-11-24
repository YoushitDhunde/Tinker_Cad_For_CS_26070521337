// TMP36 Temperature Sensor Code
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from A0 (0 to 1023)
  int sensorValue = analogRead(sensorPin);

  // Convert the reading to voltage (for 5V Arduino)
  float voltage = sensorValue * (5.0 / 1024.0);

  // Convert voltage to temperature in Celsius (TMP36 has a 0.5V offset)
  float temperatureC = (voltage - 0.5) * 100.0;

  // Convert Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Print results to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C  |  ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  delay(1000); // Wait 1 second between readings
}
