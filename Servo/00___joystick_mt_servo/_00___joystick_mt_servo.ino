#include <Servo.h>

// Servo keert terug naar originele positie bij loslaten joystick!

int valueX = 0;
int servoX = 0;
int valueY = 0;
int servoY = 0;
Servo myservo;

void setup(){
  Serial.begin(9600); 
  myservo.attach(9);
}

void loop(){
  valueX = analogRead(0);
  Serial.print("X:");
  Serial.print(valueX, DEC);
  servoX = map(valueX, 0, 1023, 0, 180);
  myservo.write(servoX);
  delay(15);
  valueY = analogRead(1);
  Serial.print("| Y:");
  Serial.print(valueY, DEC);
  Serial.println();
  delay(10);
}

