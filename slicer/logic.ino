unsigned long spinTimeFull = 1000;
unsigned long spinTime ;

void setupLogic(){
  
}

void updateLogic(){
  if (millisecond - spinTime < spinTimeFull){
    isWork = true;
  }
  else
    isWork = false;
}

void setSpinTime(){
  spinTime = millisecond;
}
