int vrx = A0;
int vry = A3;
int R3 = 8;
int knob = A4;
int score = 0; //it's game over when the score is 5

long randNumber;

int red = 7;
int blue = 6;
int moleC = 5;
int moleR = 4;
int moleL = 3;

int miss1 = 13;
int miss2 = 12;
int miss3 = 11;
int miss4 = 10;
int miss5 = 9;

int spd = 0;
int xValue = 0;
int yValue = 0;
int counter = 0;

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

  pinMode(miss1, OUTPUT);
  pinMode(miss2, OUTPUT);
  pinMode(miss3, OUTPUT);
  pinMode(miss4, OUTPUT);
  pinMode(miss5, OUTPUT);
  
}

void loop(){

  xValue = map(analogRead(vrx),0, 1024, 0, 1000);
  yValue = map(analogRead(vry),0, 1024, 0, 1000);
  //you can change the speed of the moles with the knob
  
  spd = map(analogRead(knob),0, 678, 500, 30);
  //spd = analogRead(knob);
  Serial.println(spd);


  String xString = String(xValue);
  String yString = String(yValue);
  String jsStatus = "x: " + xString + " " + "y: " + yString;
  //Serial.println(jsStatus);

  //creates random number from 1 to 3
  randNumber = random(1, 4); 
  //Serial.println(randNumber);

  counter = 0; //reset
  

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

    counter = 1;
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

    counter = 1;
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

    counter = 1;
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

  delay(1000);

  if (counter == 1){
    digitalWrite(moleL, LOW);
    digitalWrite(moleR, LOW);
    digitalWrite(moleC, LOW);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    delay(50);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(50);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
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
  }

  delay(100);

  if(score == 1){
    digitalWrite(miss1, HIGH);
  }
  else if(score == 2){
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
  }
  else if(score == 3){
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
  }
  else if(score == 4){
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
  }
  else if(score == 5){
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(1200);
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(150);
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5,LOW);
    delay(150);
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(150);
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5,LOW);
    delay(150);
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(150);
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5,LOW);
    delay(150);
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(150);
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5,LOW);
    delay(150);
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(150);
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5,LOW);
    delay(150);
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(150);
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5,LOW);
    delay(150);
    digitalWrite(miss1, HIGH);
    digitalWrite(miss2,HIGH);
    digitalWrite(miss3, HIGH);
    digitalWrite(miss4,HIGH);
    digitalWrite(miss5,HIGH);
    delay(150);
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5,LOW);
    delay(1000);
    score = 0;
  }
  else if (score == 0){
    digitalWrite(miss1, LOW);
    digitalWrite(miss2,LOW);
    digitalWrite(miss3, LOW);
    digitalWrite(miss4,LOW);
    digitalWrite(miss5, LOW);
  }



  
}

