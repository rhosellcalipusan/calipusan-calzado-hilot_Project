#include<NewPing.h>

const int MotorPin1 = 5;
const int MotorPin2 = 6;
const int MotorPin3 = 9;
const int MotorPin4 = 10;
const int MotorPin5 = 4;
const int MotorPin6 = 7;
const int MotorPin7 = 13;
const int MotorPin8 = 8;



const int echoPin = 2;
const int trigPin = 3;

const int left = 11;
const int right = 12;

NewPing sonar(trigPin, echoPin, 100);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);
  pinMode(MotorPin5, OUTPUT);
  pinMode(MotorPin6, OUTPUT);
  pinMode(MotorPin7, OUTPUT);
  pinMode(MotorPin8, OUTPUT);

  pinMode(right, INPUT);
  pinMode(left, INPUT);
}

void loop() {
delay(50);
  
  unsigned int dist = sonar.ping_cm();

  Serial.println(dist);

  int rightVal = digitalRead(right);
  int leftVal = digitalRead(left);

  if( rightVal == 1 && leftVal == 1 && dist <= 50 && dist >= 5)

  {
    digitalWrite(MotorPin1, HIGH);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, HIGH);
    digitalWrite(MotorPin4, LOW);
    digitalWrite(MotorPin5, HIGH);
    digitalWrite(MotorPin6, LOW);
    digitalWrite(MotorPin7, HIGH);
    digitalWrite(MotorPin8, LOW);
  }
  else if(rightVal == 0 && leftVal == 1)
  {
    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, HIGH);
    digitalWrite(MotorPin4, LOW);
    digitalWrite(MotorPin5, LOW);
    digitalWrite(MotorPin6, LOW);
    digitalWrite(MotorPin7, HIGH);
    digitalWrite(MotorPin8, LOW);
  }
  else if(rightVal == 1 && leftVal == 0)
  {
    digitalWrite(MotorPin1, HIGH);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, LOW);
    digitalWrite(MotorPin4, LOW);
    digitalWrite(MotorPin5, HIGH);
    digitalWrite(MotorPin6, LOW);
    digitalWrite(MotorPin7, LOW);
    digitalWrite(MotorPin8, LOW);
  }
  else
  {
    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, LOW);
    digitalWrite(MotorPin4, LOW);
    digitalWrite(MotorPin5, LOW);
    digitalWrite(MotorPin6, LOW);
    digitalWrite(MotorPin7, LOW);
    digitalWrite(MotorPin8, LOW);
  }
  
}
