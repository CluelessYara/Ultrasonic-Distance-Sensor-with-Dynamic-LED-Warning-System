// Pin definitions
const int trigPin = 6;    // Trig pin for the sensor
const int echoPin = 5;    // Echo pin for the sensor

const int ledGreen = 10;  // Green LED pin
const int ledYellow = 9;  // Yellow LED pin
const int ledRed = 8;     // Red LED pin

const int potPin = A0;    // Potentiometer pin to control distance

// Variable definitions
long duration;
int distance;
int threshold;  // Threshold value from the potentiometer

void setup() {
  // Setup input and output pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);

  pinMode(potPin, INPUT);

  // Start serial communication for monitoring values
  Serial.begin(9600);
}

void loop() {
  // Send Trig pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculate duration of pulse returning to the sensor
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance based on duration
  distance = duration * 0.034 / 2;

  // Read potentiometer value (to adjust distance threshold)
  threshold = analogRead(potPin) / 4;  // Convert value to a range of 0-255

  // Print values for monitoring
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Threshold: ");
  Serial.print(threshold);
  Serial.print("\n");

  // Turn on LEDs based on distance
  if (distance < threshold / 3) {
    // If the distance is less than one third of the threshold, turn on the red LED
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
  } else if (distance < (2 * threshold / 3)) {
    // If the distance is less than two-thirds of the threshold, turn on the yellow LED
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
  } else {
    // If the distance is greater than the threshold, turn on the green LED
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
  }

  // Wait before repeating
  delay(200);
}
