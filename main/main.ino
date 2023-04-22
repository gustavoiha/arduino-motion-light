// Pin connected to the motion sensor
const int motionSensorPin = 6;

// Pin connected to the LED light
const int ledPin = 3;

// Variable to store the timestamp of last motion detection
unsigned long lastMotionTime = 0;

// Duration in milliseconds for keeping the light on
const unsigned long lightOnDuration = 30000; // 30 seconds

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set motion sensor pin as INPUT
  pinMode(motionSensorPin, INPUT);
  
  // Set LED pin as OUTPUT
  pinMode(ledPin, OUTPUT);
  
  // Wait for serial monitor to open
  while (!Serial);
  
  // Print a message to indicate the program is running
  Serial.println("Motion Sensor Lights");
}

void loop() {
  // Read motion sensor value
  int motionValue = digitalRead(motionSensorPin);
  
  // If motion is detected
  if (motionValue == HIGH) {
    // Update the last motion time to current time
    lastMotionTime = millis();
    
    // Turn on the LED
    digitalWrite(ledPin, HIGH);

    // Print a message to indicate light was turned on
    Serial.println("Lights on!");
  }
  
  // Check if the duration since last motion detection has elapsed
  if (millis() - lastMotionTime >= lightOnDuration) {
    // Turn off the LED
    digitalWrite(ledPin, LOW);

    // Print a message to indicate light was turned off
    Serial.println("Lights off!");
  }
  
  // Delay for a short time to avoid multiple detections
  delay(500);
}
