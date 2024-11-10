#include <Servo.h>

Servo myservoA;
Servo myservoB;  // create servo object to control a servo
Servo myservoC;
Servo myservoD;


int potpinA = A0;
int potpinB = A1;  // analog pin used to connect the potentiometer
int potpinC = A2;
int potpinD = A3;


int valA;  // variable to read the value from the analog pin
int valB;
int valC;
int valD;


#define buttonA 13
#define buttonB 12
#define buttonC 8
#define buttonD 7


bool button_stateA = false; //set initial state as false
bool button_stateB = false;   
bool button_stateC = false;
bool button_stateD = false;


void setup() {
  myservoA.attach(11);
  myservoB.attach(10);  
  myservoC.attach(9);
  myservoD.attach(6); // attaches the servo on pin 9 to the servo object


  int buttons[] = { 13, 12, 8, 7 };
  for (int i : buttons) {
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  read_Button();
  val_Read();
  val_Map();
  test_Servo();
  // sets the servo position according to the scaled value
  delay(15);  // waits for the servo to get there
}

void read_Button() {
  if (digitalRead(buttonA) == 0) {
    button_stateA = !button_stateA;
  }
  if (digitalRead(buttonB) == 0) {
    button_stateB = !button_stateB;
  }
  if (digitalRead(buttonC) == 0) {
    button_stateC = !button_stateC;
  }
  if (digitalRead(buttonD) == 0) {
    button_stateD = !button_stateD;
  }
  
  delay(150);
}

void val_Read() {
  valA = analogRead(potpinA);
  valB = analogRead(potpinB);
  valC = analogRead(potpinC);
  valD = analogRead(potpinD);
}

void val_Map() {
  valA = map(valA, 0, 1023, 0, 180);
  valB = map(valB, 0, 1023, 0, 180);
  valC = map(valC, 0, 1023, 0, 180);
  valD = map(valD, 0, 1023, 0, 180);
}

void test_Servo() {
  switch (button_stateA) {
    case 0:
      myservoA.write(valA);
      break;
    case 1:
      myservoA.write(0);
      break;
  }

  switch (button_stateB) {
    case 0:
      myservoB.write(valB);
      break;
    case 1:
      myservoB.write(0);
      break;
  }

  switch (button_stateC) {
    case 0:
      myservoC.write(valC);
      break;
    case 1:
      myservoC.write(0);
      break;
  }

  switch (button_stateD) {
    case 0:
      myservoD.write(valD);
      break;
    case 1:
      myservoD.write(0);
      break;
  }

}
