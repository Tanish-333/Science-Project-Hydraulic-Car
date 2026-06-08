/*
 * ============================================================
 *  HYDRAULIC CAR - SCIENCE PROJECT
 *  2-Wheel Car with Single L298N Module
 * ============================================================
 *
 *  Setup:
 *    - 1 DC motor on the LEFT wheel (L298N OUT1/OUT2)
 *    - 1 DC motor on the RIGHT wheel (L298N OUT3/OUT4)
 *    - Arduino UNO R3 powered from Laptop USB
 *    - L298N module powered from Laptop USB
 *
 *  WIRING (Arduino UNO R3 -> L298N):
 *  ============================================================
 *    Arduino pin 3  -> L298N IN2  (LEFT motor)
 *    Arduino pin 4  -> L298N IN3  (RIGHT motor direction)
 *    Arduino pin 5  -> L298N IN4  (RIGHT motor speed)
 *    Arduino 5V     -> L298N +12V
 *    Arduino GND    -> L298N GND
 *
 *  L298N to Motors:
 *  ============================================================
 *    L298N OUT1/OUT2 -> LEFT motor
 *    L298N OUT3/OUT4 -> RIGHT motor
 *
 * ============================================================
 */

// ----- Motor Control Pins -----
const int LEFT_CONTROL = 3;    // L298N IN2 (LEFT motor)
const int RIGHT_DIR = 4;       // L298N IN3 (RIGHT motor direction)
const int RIGHT_SPEED = 5;     // L298N IN4 (RIGHT motor speed)

// Speed (0-255)
const int SPEED = 180;

void setup() {
  // Set motor pins as outputs
  pinMode(LEFT_CONTROL, OUTPUT);
  pinMode(RIGHT_DIR, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("================================================");
  Serial.println("HYDRAULIC CAR - 2 WHEEL TEST");
  Serial.println("LEFT Motor:  Pin 3 (IN2)");
  Serial.println("RIGHT Motor: Pin 4 (IN3), Pin 5 (IN4)");
  Serial.println("Speed: 180/255");
  Serial.println("================================================");
  Serial.println("Car driving BACKWARD...");
}

void loop() {
  // Both motors drive backward
  moveBackward();
  delay(100);
}

// Drive both wheels backward
void moveBackward() {
  // LEFT motor backward
  digitalWrite(LEFT_CONTROL, LOW);
  
  // RIGHT motor backward
  digitalWrite(RIGHT_DIR, LOW);
  analogWrite(RIGHT_SPEED, SPEED);
}

// Stop both motors
void stopCar() {
  digitalWrite(LEFT_CONTROL, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  analogWrite(RIGHT_SPEED, 0);
}
