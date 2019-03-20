#define startLimitSwitch 8 // 48
#define endLimitSwitch 9//50
bool limitSwitch[2] = {false, false};

unsigned long delayOfCheak = 30;
unsigned long countedTimeLimitUpdate = 0;

void limitSwitchSetup(){
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  
  pinMode(startLimitSwitch, INPUT);
  pinMode(endLimitSwitch, INPUT);
}

void limitSwitchUpdate(){
  if (limitSwitchCheak()) { // заходить сюда раз в певний час, щоб не було дрібіжчанія
    limitSwitchPush(); // Знімає дані із кнопок
    //Serial.println((String)(limitSwitch[0]?'+':'-') + (String)(limitSwitch[1]?'+':'-'));
  }
}

bool limitSwitchCheak() {
  if (millisecond - countedTimeLimitUpdate > delayOfCheak) {
    countedTimeLimitUpdate = millisecond;
    return true;
  }
  return false;
}

void limitSwitchPush(){
  limitSwitch[0] = digitalRead(startLimitSwitch);
  limitSwitch[1] = digitalRead(endLimitSwitch);
}


bool getlimitSwitchStart(){
  return limitSwitch[0];
}
bool getlimitSwitchEnd(){
  return limitSwitch[1];
}
