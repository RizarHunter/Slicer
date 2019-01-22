#define button 2

bool thisPush = false; 
bool lastPush = false;

unsigned long delayOfCheaking = 30;
unsigned long countedTimeButtonUpdate = 0;
unsigned long millisecondPushed = 0;
unsigned long delayTimeForUninterruptedSpinning = 10000;

void buttonSetup() {
  pinMode(button, INPUT);
}

void buttonUpdate() {  
  if (buttonCheak()) {
    buttonPush();
    buttonAction();
  }
}

bool buttonCheak(){
  if (millisecond - countedTimeButtonUpdate > delayOfCheaking){
    countedTimeButtonUpdate = millisecond;
    return true;
  }
  return false;
}

void buttonPush(){
  lastPush = thisPush;
  thisPush = digitalRead(button);
}

void buttonAction(){
  if (thisPush){
    if (lastPush){
    
    }
    else {
      millisecondPushed = millisecond;
      smallAction();
    }
  }
  else{
    millisecondPushed = millisecond;
  }

  if (millisecond - millisecondPushed > delayTimeForUninterruptedSpinning){
    bigAction();
  }
}


void smallAction(){
  Serial.println("44");
  setSpinTime();
}
void bigAction(){
  Serial.println("44444");
  setSpinTime();
}
