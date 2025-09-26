// Define which pin the Tilt Sensor is connected to on the ESP32-S3
const int tiltPin = 7; // Using GPIO 7

void setup() {
  // Start the Serial Monitor to display the results
  Serial.begin(115200); // ESP32 boards work well with a faster baud rate
  
  // Set the tilt pin as an input with an internal pull-up resistor.
  pinMode(tiltPin, INPUT_PULLUP);
  
  Serial.println("Seeed Studio ESP32-S3 - Tilt Sensor Test");
  Serial.println("---------------------------------------");
}

void loop() {
  // Read the state of the sensor
  int sensorState = digitalRead(tiltPin);

  // When the sensor is tilted, it closes the circuit to GND, pulling the pin LOW.
  // Otherwise, the internal pull-up resistor keeps it HIGH.
  if (sensorState == LOW) {
    Serial.println("Status: Upright.");
  } else {
    Serial.println("Status: Tilted! (Potential Fall)");
  }
  
  // Wait a little bit before the next reading
  delay(200);
}