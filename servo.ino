#include <Servo.h>

int servopin = 9;
Servo myservo;

int angle = 0;
int dir = 1;
int reading = 0;


void setup(){
  Serial.begin(9600);
  myservo.attach(servopin);
  
}

void loop(){
  reading = analogRead(A0);
  Serial.println(angle);
  angle = map(reading, 0, 1023, 0, 180);

  //if (angle <= 0){dir = 1;}

  //if(angle >= 179){dir = -1;}

  //angle = angle + dir;
  //delay(500);

  myservo.write(angle);
  
}

