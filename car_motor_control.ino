/*
 * ============================================================
 *  HYDRAULIC CAR - SCIENCE PROJECT
 *  3-Wheel Car Motor Control
 * ============================================================
 *
 *  Setup:
 *    - 2 driven wheels at the BACK  (each has its own DC motor)
 *    - 1 free caster wheel at the FRONT (no motor)
 *    - L298N motor driver controls both back motors
 *    - Arduino sends the signals, battery powers the motors
 *
 *  WIRING (Arduino UNO  ->  L298N motor driver):
 *  ------------------------------------------------------------
 *    L298N ENA  ->  Arduino pin 5   (speed for LEFT motor)
 *    L298N IN1  ->  Arduino pin 6   (left motor direction)
 *    L298N IN2  ->  Arduino pin 7   (left motor direction)
 *
 *    L298N IN3  ->  Arduino pin 8   (right motor direction)
 *    L298N IN4  ->  Arduino pin 9   (right motor direction)
 *    L298N ENB  ->  Arduino pin 10  (speed for RIGHT motor)
 *
 *    L298N OUT1 / OUT2  ->  LEFT back motor
 *    L298N OUT3 / OUT4  ->  RIGHT back motor
 *
 *    L298N +12V (or VS) ->  Battery +   (use a 6-12V battery pack)
 *    L298N GND          ->  Battery -  AND  Arduino GND  (shared!)
 *    L298N 5V           ->  Arduino 5V  (only if you removed the jumper)
 *
 *  IMPORTANT: The battery GND and the Arduino GND MUST be connected
 *  together, or the motors will not work.
 *
 *  NOTE: ENA and ENB MUST be PWM pins (the ones with a ~ symbol)
 *  so we can control the speed. On the UNO those are 5, 6, 9, 10, 11, 3.
 * ============================================================
 */

// ---------- LEFT back motor pins ----------
const int ENA = 5;   // speed (PWM)
const int IN1 = 6;
const int IN2 = 7;

// ---------- RIGHT back motor pins ----------
const int IN3 = 8;
const int IN4 = 9;
const int ENB = 10;  // speed (PWM)

// ---------- Speed setting ----------
// PWM value from 0 (stopped) to 255 (full speed).
// 200 is a good, strong, steady speed for a small car.
// Lower this number if the car is too fast, raise it (max 255) if too slow.
const int CAR_SPEED = 200;


void setup() {
  // Tell the Arduino all these pins are outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Start with the car stopped so it doesn't jump on power-up
  stopCar();
}


void loop() {
  // Drive the car forward at a good steady speed.
  moveForward();

  // The car keeps moving forward as long as it has power.
  // (If you want it to do something else, see the functions below.)
}


// ============================================================
//  MOVEMENT FUNCTIONS
//  Mix and match these in loop() to control how the car drives.
// ============================================================

// Drive straight forward
void moveForward() {
  // LEFT motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, CAR_SPEED);

  // RIGHT motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, CAR_SPEED);
}

// Drive straight backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, CAR_SPEED);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, CAR_SPEED);
}

// Turn left (right wheel spins, left wheel stops)
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, CAR_SPEED);
}

// Turn right (left wheel spins, right wheel stops)
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, CAR_SPEED);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

// Stop both motors
void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
