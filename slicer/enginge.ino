#include <Stepper.h>
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
int speedSpin = 60; //50-250

Stepper myStepper(stepsPerRevolution, IN1, IN2, IN3, IN4);

void engineSetup(){
  myStepper.setSpeed(speedSpin);
}

void engineUpdate(){
  if (isWork) {
    spinEngine();
    Serial.print("--------");
  }
}

void spinEngine(){
  if (side) {
    myStepper.step(stepsPerRevolution);
    delay(200);
  }
  else {
    myStepper.step(-stepsPerRevolution);
    delay(200);
  }
}
