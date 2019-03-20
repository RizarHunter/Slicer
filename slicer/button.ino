#define buttons 3
const int button[buttons] = {49, 51, 53};//{2, 3, 4};

bool thisPush[buttons] = {false, false, false};
bool lastPush[buttons] = {false, false, false};

unsigned long delayOfCheaking = 30;
unsigned long countedTimeButtonUpdate = 0;

// 0 - ненежато, 1 - щойно нажато, 2 - нажато, 3 - щойно віджато
int buttonOut[buttons] = {0, 0, 0};

void buttonSetup() {
  for (int i = 0; i < buttons; i++)
    pinMode(button[i], INPUT);
}

void buttonUpdate() {
  if (buttonCheak()) { // заходить сюда раз в певний час, щоб не було дрібіжчанія
    for (int i = 0; i < buttons; i++) {
      buttonPush(i); // Знімає дані із кнопок
      buttonDetect(i); // Засуває перемикачів в масив buttonOut
    }
    buttonReaction();
  }
}

bool buttonCheak() {
  if (millisecond - countedTimeButtonUpdate > delayOfCheaking) {
    countedTimeButtonUpdate = millisecond;
    return true;
  }
  return false;
}

void buttonPush(int numberOfButton) {
  lastPush[numberOfButton] = thisPush[numberOfButton];
  thisPush[numberOfButton] = digitalRead(button[numberOfButton]);
}

void buttonDetect(int numberOfButton) {
  if ( ! thisPush[numberOfButton] &&  ! lastPush[numberOfButton])
    buttonOut[numberOfButton] = 0 + 2;
  if (thisPush[numberOfButton] &&  ! lastPush[numberOfButton])
    buttonOut[numberOfButton] = 1 + 2;
  if (thisPush[numberOfButton] && lastPush[numberOfButton])
    buttonOut[numberOfButton] = 2 - 2;
  if ( ! thisPush[numberOfButton] && lastPush[numberOfButton])
    buttonOut[numberOfButton] = 3 - 2;
}


void buttonReaction() { 
  if (buttonOut[0] == 1) { setStyleSpinUntilWall(); }
  if (buttonOut[1] == 1) { setStyleSpinBack(); }
  if (buttonOut[1] == 3) { setStyleStopSpin(); }
  if (buttonOut[2] == 3) { setStyleMinus(); }
}
