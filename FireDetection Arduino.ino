#include <Servo.h>

// Pin connections
const int flameSensorPin = A0;   // Flame sensor analog pin
const int relayPin = 4;          // Relay control pin
const int servoPin = 8;          // Servo control pin

// Threshold for flame detection
const int flameThreshold = 500;

// Servo motor object
Servo myServo;

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(90);  // Set servo to initial position
  Serial.begin(9600);
}

void loop() {
  int flameValue = analogRead(flameSensorPin);

  // Uncomment the following line to see the flame sensor reading in the serial monitor
  // Serial.println(flameValue);

  if (flameValue < flameThreshold) {
    // Fire detected
    digitalWrite(relayPin, HIGH);  // Turn on water pump (activate relay)
    Serial.println("Fire detected! Water pump turned on.");
    myServo.write(40);  // Move servo to 120 degrees
    delay(4000);
  }
  
    digitalWrite(relayPin, LOW);   // Turn off water pump (deactivate relay)
    Serial.println("No fire detected. Water pump turned off.");
    myServo.write(90);   // Move servo to 90 degrees (initial position)

  delay(1000); // Adjust the delay according to your requirements
}
