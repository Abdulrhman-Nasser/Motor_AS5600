#include <AS5600.h>

AS5600 encoder;
float output;
#define IN1 7
#define IN2 8
#define IN3 2
#define IN4 4
#define EN2 9
#define EN1 5

void MoveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, speed);
  analogWrite(EN2, speed);
  Serial.print("Moving forward with speed : ");
  Serial.println(speed);
}
void MoveBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN1, speed);
  analogWrite(EN2, speed);
  Serial.print("Moving backward with speed : ");
  Serial.println(speed);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int x = Serial.parseInt();
    Serial.read();
    if (x >= 0) {
      MoveForward(x);
    } else {
      x = x * -1;
      MoveBackward(x);
    }
  }
  output = encoder.getScaledAngle();
  Serial.println(output);
}
