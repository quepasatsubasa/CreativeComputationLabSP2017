int button = 2;
int motor = 9;
int sensor = A1;
int resistor = A0;
int pitz = 8;
int LED = 6;
int sensorValue;
int highValue = 1023;
int lowValue = 0;
int motorInput;

void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(pitz, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  int reading = digitalRead(button);
  int readingLight = analogRead(sensor);
  int readingResistor = analogRead(resistor);
  motorInput = map(readingResistor,0,1023,0,255);
  delay(20);
  if (reading == 1) {
    if (readingResistor == 0) {
      digitalWrite(motor, LOW);
    } else if (readingResistor <= 600) {
      digitalWrite(motor, HIGH);
      delay(200);
      digitalWrite(motor, LOW);
      delay(200);
      digitalWrite(motor, HIGH);
    } else {
      digitalWrite(motor, motorInput);
    }
    if (readingLight >= 800) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }
    digitalWrite(pitz, HIGH);
    if (readingLight > highValue) {
      highValue = readingLight;
    } else if (readingLight < lowValue) {
      lowValue = readingLight;
    }
    digitalWrite(pitz, LOW);
  } else {
    digitalWrite(motor, LOW);
    digitalWrite(LED, LOW);
    digitalWrite(pitz, LOW);
  }
}
