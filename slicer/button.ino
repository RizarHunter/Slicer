#define button 2

bool thisPush = false; 
bool lastPush = false;

unsigned long delayOfCheaking = 30;
unsigned long countedTimeButtonUpdate = 0;
unsigned long millisecondPushed = 0;
unsigned long delayTimeForUninterruptedSpinning = 3000;

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
    if (lastPush){ }
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
  setSpinTime();
}
void bigAction(){
  setSpinTime();
}
