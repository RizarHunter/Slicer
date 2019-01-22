#define enb 13
#define dir 12
#define pul 11

int dTime; // distance between last pul pin changing and this moment
bool pulBool = false; // type of signal to engine (pin pul)
unsigned long microsecondCommonForEngine; // last time of changing signal to pul pin
unsigned long numberOfSpinning = 0; // current number of chenging pul pin
int delaySpinTime = 900; // spead of spinning

void engineSetup() {
  pinMode(pul, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(enb, OUTPUT);
  
  digitalWrite(enb, HIGH);
  digitalWrite(enb, LOW); // On
  
  digitalWrite(dir, HIGH); // Anti clock spin
}

void engineUpdate() {
  updateSteper();
}

void updateSteper() {
  if (isWork) {
  digitalWrite(pul, LOW);
  delay(10);
  digitalWrite(pul, HIGH);
  delay(10);
    //findNewPeriod();
    //changingOfHighAndLow();
    //pulBoolSetPin();
    //Serial.print("++");
  }
}

void findNewPeriod() {
  updateTimeOfSpinning();
  if (newSpin()) {
    setTimeOfSpinning();
    addOneNumberOfSpinning();
  }
}
void updateTimeOfSpinning() {
  dTime = micros() - microsecondCommonForEngine;
}
bool newSpin() {
  if (dTime - delaySpinTime > 0
    || abs(dTime - delaySpinTime) > 100000000) // переповнення
    return true;
  return false;
}
void setTimeOfSpinning() {
  microsecondCommonForEngine = micros();
}
void addOneNumberOfSpinning(){
  numberOfSpinning++;
}

void changingOfHighAndLow() {
  if (numberOfSpinning % 2 == 0) {
    pulBool = false;
  }
  else {
    pulBool = true;
  }
}
void pulBoolSetPin() {
  if (pulBool) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);
}
