#include <Servo.h>

int vrx = A0;
int vry = A3;
int R3 = 8;
int knob = A4;
int score = 0; //it's game over when the score is 5

long randNumber;

int red = 7;
int blue = 6;
int blue2 = 13;
int red2 = 12;
int moleC = 5;
int moleR = 4;
int moleL = 3;

int servopin = 9;
Servo myservo;

int miss0 = 0;
int miss1 = 25;
int miss2 = 63;
int miss3 = 98;
int miss4 = 132;
int miss5 = 180;

int counter = 0;
int hit = 0;
int miss = 1;


int spd = 0;
int xValue = 0;
int yValue = 0;


void setup(){
  Serial.begin(9600);
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(knob, INPUT);
  pinMode(R3, INPUT);

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(moleC, OUTPUT);
  pinMode(moleR, OUTPUT);
  pinMode(moleL, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue2, OUTPUT);

  myservo.attach(servopin);
  
}

void loop(){

  xValue = map(analogRead(vrx),0, 1024, 0, 1000);
  yValue = map(analogRead(vry),0, 1024, 0, 1000);
  //you can change the speed of the moles with the knob
  
  spd = map(analogRead(knob),0, 1023, 500, 30);
  //spd = analogRead(knob);
  Serial.println(spd);
  Serial.println(score);


  String xString = String(xValue);
  String yString = String(yValue);
  String jsStatus = "x: " + xString + " " + "y: " + yString;
  //Serial.println(jsStatus);

  //creates random number from 1 to 3
  randNumber = random(1, 4); 
  //Serial.println(randNumber);

  counter = miss; //reset
  

  if(randNumber == 1){
    digitalWrite(moleL, HIGH);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, LOW);

    digitalWrite(red, LOW);
    digitalWrite(blue,LOW);
    delay(spd);
   }   

  else if(randNumber == 2){
    digitalWrite(moleC, HIGH);
    digitalWrite(moleR, LOW);
    digitalWrite(moleL, LOW);

    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(spd);

  }

  else if(randNumber ==3){
    digitalWrite(moleR, HIGH);
    digitalWrite(moleL, LOW);
    digitalWrite(moleC, LOW);

    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(spd);

  }


  xValue = map(analogRead(vrx),0, 1024, 0, 1000);
  yValue = map(analogRead(vry),0, 1024, 0, 1000);

  
  if(randNumber == 1 && xValue < 10){
    digitalWrite(moleL, HIGH);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, LOW);

    digitalWrite(red, HIGH);
    digitalWrite(blue,HIGH);

    counter = hit;
    score = 0;
   } 

   else  if(randNumber == 1 && 10 < xValue){
    digitalWrite(moleL, HIGH);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, LOW);

    digitalWrite(red, LOW);
    digitalWrite(blue,LOW);

    score = score + 1;
   }

  if(randNumber == 2 && yValue < 10){
    digitalWrite(moleL, LOW);
    digitalWrite(moleR, HIGH);
    digitalWrite(moleC, LOW);

    digitalWrite(red, HIGH);
    digitalWrite(blue,HIGH);

    counter = hit;
    score = 0;
   } 

   else if(randNumber == 2 && 10 < yValue){
    digitalWrite(moleL, LOW);
    digitalWrite(moleR, HIGH);
    digitalWrite(moleC, LOW);

    digitalWrite(red, LOW);
    digitalWrite(blue,LOW);

    score = score + 1;
   }

   if(randNumber == 3 && 900 < xValue){
    digitalWrite(moleL, LOW);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, HIGH);

    digitalWrite(red, HIGH);
    digitalWrite(blue,HIGH);

    counter = hit;
    score = 0;
   } 

   else if(randNumber == 3 && xValue < 900){
    digitalWrite(moleL, LOW);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, HIGH);

    digitalWrite(red, LOW);
    digitalWrite(blue,LOW);

    score = score + 1;
   }


  digitalWrite(moleL, LOW);
  digitalWrite(moleR, LOW);
  digitalWrite(moleC, LOW);

  delay(10);

  if (counter == hit){
    digitalWrite(moleL, LOW);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, LOW);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(50);
    
  }

  else{
    digitalWrite(red, LOW);
    digitalWrite(blue,LOW);
    digitalWrite(moleL, LOW);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, LOW);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,LOW);
  }

  delay(100);

  if(score == 0){
    myservo.write(miss0);
    delay(1000);
  }
  else if(score == 1){
    myservo.write(miss1);
    delay(1000);
  }
  else if(score == 2){
    myservo.write(miss2);
    delay(1000);
  }
  else if(score == 3){
    myservo.write(miss3);
    delay(1000);
  }
  else if(score == 4){
    myservo.write(miss4);
    delay(1000);
  }
  else if(score == 5){
    myservo.write(miss5);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,HIGH);
    delay(50);
    digitalWrite(red2,HIGH);
    digitalWrite(blue2,LOW);
    delay(50);
    digitalWrite(red2,LOW);
    digitalWrite(blue2,LOW);
    delay(50);
    delay(5000);
    myservo.write(miss0);
    delay(1000);
    score = 0;
  }


  
}

