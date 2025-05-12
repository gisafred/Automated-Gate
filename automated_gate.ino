#include <Servo.h>
// Pin Definitions
const int trigPin = 2;     // Ultrasonic Trigger (D2)
const int echoPin = 3;     // Ultrasonic Echo (D3)
const int redLed = 4;      // Red LED - Gate Closed (D4)
const int blueLed = 5;     // Blue LED - Gate Open (D5)
const int servoPin = 6;    // Servo Motor (D6 - PWM)
const int buzzerPin = 12;  // Piezo Buzzer (D12)
const int gndPin1 = 7;     // Additional Ground (D7)
const int gndPin2 = 8;     // Additional Ground (D8)
// Variables
Servo gateServo;
long duration;
int distance;
bool gateOpen = false;
unsigned long gateOpenTime = 0;
bool buzzerState = false;
unsigned long lastBuzzerToggle = 0;
const int buzzerInterval = 200;  // 200ms between ticks (adjust for speed)
void setup() {
  // Initialize components
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // Set D7/D8 as software ground pins
  pinMode(gndPin1, OUTPUT); digitalWrite(gndPin1, LOW);
  pinMode(gndPin2, OUTPUT); digitalWrite(gndPin2, LOW);
  // Servo setup
  gateServo.attach(servoPin);
  // Initial state: Gate closed (0°), Red LED ON
  gateServo.write(0);
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  digitalWrite(buzzerPin, LOW);
  Serial.begin(9600);
}
void loop() {
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");
  // Gate logic
  if (distance < 15 && distance > 0 && !gateOpen) {
    // Open gate (80°)
    gateOpen = true;
    gateOpenTime = millis();
    gateServo.write(80);
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
  }
  // Modified buzzer control with longer intervals
  if (gateOpen) {
    if (millis() - lastBuzzerToggle >= buzzerInterval) {
      buzzerState = !buzzerState;
      digitalWrite(buzzerPin, buzzerState ? HIGH : LOW);
      // Use different intervals for ON and OFF states
      lastBuzzerToggle = millis();
      if (buzzerState) {
        delay(800);  // Longer ON duration (800ms)
      } else {
        delay(400);  // Longer OFF duration (400ms)
      }
    }
  }
  // Close gate after 5 seconds
  if (gateOpen && millis() - gateOpenTime >= 5000) {
    gateOpen = false;
    gateServo.write(0);
    digitalWrite(blueLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzerPin, LOW);
  }
  delay(50);  // Small delay to reduce CPU load
}