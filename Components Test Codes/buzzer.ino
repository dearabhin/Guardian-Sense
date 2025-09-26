// Define which pin the Active Buzzer is connected to
const int buzzerPin = 5; // Using GPIO 5

void setup() {
  // Start the Serial Monitor for status messages
  Serial.begin(115200); 
  
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  
  Serial.println("ESP32-S3 - Active Buzzer Test");
  Serial.println("-----------------------------");
}

void loop() {
  // Turn the buzzer on
  Serial.println("Buzzer ON");
  digitalWrite(buzzerPin, HIGH); 
  delay(5000); // Keep it on for half a second

  // Turn the buzzer off
  Serial.println("Buzzer OFF");
  digitalWrite(buzzerPin, LOW);  
  delay(5000); // Keep it off for half a second
}