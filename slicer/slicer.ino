bool isWork = false;
bool side = true; 

unsigned long millisecond = 0;

void setup() {
  timerSetup();
  buttonSetup();
  hollSetup();
  limitSwitchSetup();
  
  setupLogic();
  
  engineSetup();
  serialSetup();
  songSetup();
  
  delay(1500);
} 
  
void loop() { 
  timerUpdate();
  buttonUpdate();
  hollUpdate();
  limitSwitchUpdate();
  
  updateLogic();
  
  engineUpdate();
  songUpdate();
}
