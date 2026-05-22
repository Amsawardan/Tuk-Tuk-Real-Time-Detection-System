// Define the GPIO pin where the sensor's OUT pin is connected
const int flameSensorPin = D1; // Change to the GPIO pin you used

void setup() {
  Serial.begin(115200);        // Initialize serial communication
  pinMode(flameSensorPin, INPUT); // Set the sensor pin as input
}

void loop() {
  int sensorValue = digitalRead(flameSensorPin); // Read the sensor output
  
  if (sensorValue == LOW) {
    Serial.println("Flame detected!");
  } else {
    Serial.println("No flame detected.");
  }

  delay(1000); // Wait for 1 second before checking again
}
