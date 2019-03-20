int style = 2;
unsigned long timeToSpinOneTime = 1700; // Час кручення для оборота на 1 мм треба 1.700 мс, для двох 3.400 (Повний оборот за 13.500)
unsigned long lastSpinTime;

void setupLogic() { }

void updateLogic() {
  switch (style) {
    case -2 : case -1 : { spinCaseOut(); } break;
    case 0 : { spinCaseOneTime(); } break;
    case 1 : case 2 : { spinCaseStop(); } break;
    case 10 : { spinCaseIn(); }
  }
}
void spinCaseOut(){
  isWork = true;
  side = false;
  if (getlimitSwitchStart()) { 
    setStyleStopSpin();
    callSongLong();
  }
}
void spinCaseStop(){
  isWork = false;
}
void spinCaseOneTime() {
  if (millisecond - lastSpinTime < timeToSpinOneTime){
    side = true;
    isWork = true;
    if (getlimitSwitchEnd()){
      setStyleStopSpin();
      callSongLong();
    }
  }
  else {
    callSongSmall();
    setStyleStopSpin();
  }
}
void spinCaseIn() {
  side = true;
  isWork = true;
  if (isNeedInteruptSpin()) {
    setStyleStopSpin();
    callSongLong();
  }

  if (getlimitSwitchEnd()){
    setStyleStopSpin();
    callSongLong();
  }
}


void setStyleSpinBack() { if (getlimitSwitchStart()) { } else style = -2; }
void setStyleMinus() { if (style == 2) style--; else if (style == 1) setStyleBeginSpin(); }
void setStyleStopSpin() { style = 2; }
void setStyleBeginSpin() { if (getlimitSwitchEnd()) { setStyleStopSpin(); } else style = 0; lastSpinTime = millisecond; }
void setStyleSpinUntilWall() { if (getlimitSwitchEnd()) { } else style = 10; }
