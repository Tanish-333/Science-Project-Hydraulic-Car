/*
 * ============================================================
 *  HYDRAULIC CAR - SCIENCE PROJECT
 *  2-Wheel Car with Single L298N Module
 * ============================================================
 *
 *  Setup:
 *    - 1 DC motor on the LEFT wheel (L298N OUT1/OUT2)
 *    - 1 DC motor on the RIGHT wheel (L298N OUT3/OUT4)
 *    - Arduino UNO R3 powered from PC USB
 *    - L298N module powered from PC USB
 *
 *  WIRING (Arduino UNO R3 -> L298N):
 *  ============================================================
 *    Arduino pin 3  -> L298N IN2  (controls direction/speed for LEFT motor)
 *    Arduino pin 4  -> L298N IN3  (controls direction/speed for RIGHT motor)
 *    Arduino pin 5  -> L298N IN4  (controls direction/speed for RIGHT motor)
 *    Arduino GND    -> L298N GND
 *
 *  L298N to Motors:
 *  ============================================================
 *    L298N OUT1/OUT2 -> LEFT motor
 *    L298N OUT3/OUT4 -> RIGHT motor
 *    L298N +12V      -> PC USB (limited power)
 *    L298N GND       -> Arduino GND + PC USB GND
 *
 * ============================================================
 */

// ----- Motor Control Pins -----
const int LEFT_CONTROL = 3;    // L298N IN2 (LEFT motor)
const int RIGHT_DIR = 4;       // L298N IN3 (RIGHT motor direction)
const int RIGHT_SPEED = 5;     // L298N IN4 (RIGHT motor speed)

// Speed (0-255)
// USB power is limited (~500mA), using moderate speed
const int SPEED = 150;

void setup() {
  // Set motor pins as outputs
  pinMode(LEFT_CONTROL, OUTPUT);
  pinMode(RIGHT_DIR, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("================================================");
  Serial.println("HYDRAULIC CAR - 2 WHEEL TEST");
  Serial.println("Power: PC USB");
  Serial.println("LEFT Motor:  Pin 3 (IN2)");
  Serial.println("RIGHT Motor: Pin 4 (IN3), Pin 5 (IN4)");
  Serial.println("================================================");
  Serial.println("Car driving FORWARD...");
}

void loop() {
  // Both motors drive forward
  moveForward();
  delay(100);
}

// Drive both wheels forward
void moveForward() {
  // LEFT motor forward
  digitalWrite(LEFT_CONTROL, HIGH);
  
  // RIGHT motor forward
  digitalWrite(RIGHT_DIR, HIGH);
  analogWrite(RIGHT_SPEED, SPEED);
}

// Stop both motors
void stopCar() {
  digitalWrite(LEFT_CONTROL, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  analogWrite(RIGHT_SPEED, 0);
}
