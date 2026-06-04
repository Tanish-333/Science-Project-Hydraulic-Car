/*
 * ============================================================
 *  HYDRAULIC CAR - SCIENCE PROJECT
 *  2-Wheel Car with 2 DC Motors
 * ============================================================
 *
 *  Setup:
 *    - 1 DC motor on LEFT wheel
 *    - 1 DC motor on RIGHT wheel
 *    - L298N motor driver controls both motors
 *    - Arduino sends the signals, battery powers the motors
 *
 *  WIRING (Arduino UNO  ->  L298N motor driver):
 *  ============================================================
 *    Arduino GND        ->  L298N GND
 *    Arduino pin 5 (PWM) -> L298N ENA  (LEFT motor speed)
 *    Arduino pin 6      ->  L298N IN1  (LEFT motor direction)
 *    Arduino pin 7      ->  L298N IN2  (LEFT motor direction)
 *    Arduino pin 8      ->  L298N IN3  (RIGHT motor direction)
 *    Arduino pin 9      ->  L298N IN4  (RIGHT motor direction)
 *    Arduino pin 10 (PWM)-> L298N ENB  (RIGHT motor speed)
 *
 *  L298N to Motors & Battery:
 *  ============================================================
 *    L298N OUT1 / OUT2  ->  LEFT motor
 *    L298N OUT3 / OUT4  ->  RIGHT motor
 *    L298N +12V         ->  Battery + (6-12V)
 *    L298N GND          ->  Battery - AND Arduino GND (MUST connect!)
 *
 * ============================================================
 */

// Motor pins
const int LEFT_SPEED = 5;    // ENA pin (PWM for speed)
const int LEFT_DIR1 = 6;     // IN1 pin
const int LEFT_DIR2 = 7;     // IN2 pin

const int RIGHT_DIR1 = 8;    // IN3 pin
const int RIGHT_DIR2 = 9;    // IN4 pin
const int RIGHT_SPEED = 10;  // ENB pin (PWM for speed)

// Speed (0-255, where 255 is full speed)
const int SPEED = 200;

void setup() {
  // Set all pins as outputs
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(LEFT_DIR1, OUTPUT);
  pinMode(LEFT_DIR2, OUTPUT);
  pinMode(RIGHT_DIR1, OUTPUT);
  pinMode(RIGHT_DIR2, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);

  stopCar();  // Start with motors stopped
}

void loop() {
  moveForward();   // Go forward
  delay(3000);     // For 3 seconds

  stopCar();       // Stop
  delay(1000);     // Wait 1 second

  moveBackward();  // Go backward
  delay(3000);     // For 3 seconds

  stopCar();       // Stop
  delay(1000);     // Wait 1 second

  turnLeft();      // Turn left
  delay(2000);     // For 2 seconds

  stopCar();       // Stop
  delay(1000);     // Wait 1 second

  turnRight();     // Turn right
  delay(2000);     // For 2 seconds

  stopCar();       // Stop
  delay(1000);     // Wait 1 second
}

// Go forward (both motors forward)
void moveForward() {
  digitalWrite(LEFT_DIR1, HIGH);
  digitalWrite(LEFT_DIR2, LOW);
  analogWrite(LEFT_SPEED, SPEED);

  digitalWrite(RIGHT_DIR1, HIGH);
  digitalWrite(RIGHT_DIR2, LOW);
  analogWrite(RIGHT_SPEED, SPEED);
}

// Go backward (both motors backward)
void moveBackward() {
  digitalWrite(LEFT_DIR1, LOW);
  digitalWrite(LEFT_DIR2, HIGH);
  analogWrite(LEFT_SPEED, SPEED);

  digitalWrite(RIGHT_DIR1, LOW);
  digitalWrite(RIGHT_DIR2, HIGH);
  analogWrite(RIGHT_SPEED, SPEED);
}

// Turn left (left motor slow/backward, right motor forward)
void turnLeft() {
  digitalWrite(LEFT_DIR1, LOW);
  digitalWrite(LEFT_DIR2, HIGH);
  analogWrite(LEFT_SPEED, SPEED / 2);  // Slower

  digitalWrite(RIGHT_DIR1, HIGH);
  digitalWrite(RIGHT_DIR2, LOW);
  analogWrite(RIGHT_SPEED, SPEED);
}

// Turn right (left motor forward, right motor slow/backward)
void turnRight() {
  digitalWrite(LEFT_DIR1, HIGH);
  digitalWrite(LEFT_DIR2, LOW);
  analogWrite(LEFT_SPEED, SPEED);

  digitalWrite(RIGHT_DIR1, LOW);
  digitalWrite(RIGHT_DIR2, HIGH);
  analogWrite(RIGHT_SPEED, SPEED / 2);  // Slower
}

// Stop both motors
void stopCar() {
  digitalWrite(LEFT_DIR1, LOW);
  digitalWrite(LEFT_DIR2, LOW);
  digitalWrite(RIGHT_DIR1, LOW);
  digitalWrite(RIGHT_DIR2, LOW);
  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, 0);
}
