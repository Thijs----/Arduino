#include <Servo.h>

// Servo keert NIET terug naar originele positie bij loslaten joystick!

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
  if(valueX != 507 && valueX != 508){
  servoX = map(valueX, 0, 1023, 0, 180);
  int temp = myservo.read();
  int temp2 = temp + (servoX - 90)/4;
  if(temp2 >= 180){
   myservo.write(180);
   Serial.println(180); 
  }
  if(temp2 <= 0){
   myservo.write(0); 
   Serial.println(0);
  }
  if(temp2 > 0 && temp2 < 180){
  myservo.write(temp2);
  Serial.println(temp2);
  }
  }
  delay(50);
}

