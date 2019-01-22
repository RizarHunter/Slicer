bool isWork = false;//false;
bool side = true; 

unsigned long millisecond = 0;

void setup() {
  timerSetup();
  buttonSetup();
  setupLogic();
  //engineSetup();
  serialSetup();
  
  delay(1500);
} 
  
void loop() { 
  timerUpdate();
  buttonUpdate();
  updateLogic();
  engineUpdate();
}
