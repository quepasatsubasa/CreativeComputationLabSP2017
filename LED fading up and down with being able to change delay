int reading = 0;
int counter = 0;
int blue = 6;
int brightness;
int u = 0;
int u2 = 0;


void setup(){
  Serial.begin(9600);
  pinMode(blue,OUTPUT);

}

void loop(){

  brightness = map(reading,0,1023,0,255);
  Serial.print(brightness);
  Serial.print(" ");
  Serial.print(reading);
  Serial.print(" ");
  Serial.print(u2);
  Serial.print(" ");
  Serial.print(counter);
  Serial.println(" ");
  
  
  analogWrite(blue, brightness);
  u = analogRead(A0);
  u2 = map(u,0,1023,0,20);

  
  
  if(counter == 0){
    reading++;
    delay(u2);
  }
  if(counter == 1){
    reading--;
    delay(u2);
  }
  if(reading < 1){
    counter = 0;
  }
  if(reading > 1023){
    counter = 1;
  }
  
}

