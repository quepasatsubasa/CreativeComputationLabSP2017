int reading;
int blue = 6;
int brightness;


void setup(){
  Serial.begin(9600);
  pinMode(blue,OUTPUT);

}

void loop(){
  reading = analogRead(A0);
  brightness = map(reading,0,1023,1,255);
  Serial.println(reading);

  analogWrite(blue, brightness);
  
}
