#define numberOfPin 2

int hollInputPin[numberOfPin] = {A0, A1};
int hollInputData[numberOfPin] = {529, 529};
const int middleInputData = 545;

#define hollMassLenSmall 10
#define delayTimeForGetData 10
unsigned long timeOfWriting[hollMassLenSmall];
int hollInputMassSmall0[hollMassLenSmall];
int hollInputMassSmall1[hollMassLenSmall];
unsigned long lastMillisSmall;

#define hollMassLen 30
int hollInputMass0[hollMassLen];
int hollInputMass1[hollMassLen];
unsigned long lastMillis;
int numberOfMassAfterStart = 0;

int distance = 8; // Дистаннція віднімання повинне бути менше за hollMassLen ----------------
int high = 150; // Поріг чутливості для зупиннення мотора ------------------------------------

void hollSetup() {
  lastMillis = millisecond;
  lastMillisSmall = millisecond;
}

void hollUpdate() {
  getDataFromSensor();
  getSmallData();
  getBigData();
}

void getDataFromSensor() {
  for (int i = 0; i < numberOfPin; i++)
    hollInputData[i] = analogRead(hollInputPin[i]) - middleInputData;
}

void getSmallData() {
  if (millisecond - lastMillisSmall >= delayTimeForGetData) {
    addNewDataToMassiveSmall(hollInputData);
    lastMillisSmall = millisecond;
  }
}
void addNewDataToMassiveSmall(int* data) {
  for (int i = hollMassLenSmall - 1; i > 0; i--) {
    hollInputMassSmall0[i] = hollInputMassSmall0[i - 1];
    hollInputMassSmall1[i] = hollInputMassSmall1[i - 1];
    timeOfWriting[i] = timeOfWriting[i - 1];
  }
  hollInputMassSmall0[0] = data[0];
  hollInputMassSmall1[0] = data[1];
  timeOfWriting[0] = millisecond;
}

void getBigData() {
  if (millisecond - lastMillis >= hollMassLenSmall * delayTimeForGetData) {
    addNewDataToMassive(getMiddle0(), getMiddle1());
    setNumberOfMassAfterStart();
    lastMillis = millisecond;
  }
}
void addNewDataToMassive(int data0, int data1) {
  for (int i = hollMassLen - 1; i > 0; i--) {
    hollInputMass0[i] = hollInputMass0[i - 1];
    hollInputMass1[i] = hollInputMass1[i - 1];
  }
  hollInputMass0[0] = data0;
  hollInputMass1[0] = data1;
}
int getMiddle0() {
  int middle = 0;
  for (int i = 0; i < hollMassLenSmall; i++) {
    middle += hollInputMassSmall0[i];
  }
  middle = middle / hollMassLenSmall;
  return middle;
}
int getMiddle1() {
  int middle = 0;
  for (int i = 0; i < hollMassLenSmall; i++) {
    middle += hollInputMassSmall1[i];
  }
  middle = middle / hollMassLenSmall;
  return middle;
}
void setNumberOfMassAfterStart() {
  if (isWork) numberOfMassAfterStart++;
  else numberOfMassAfterStart = 0;
}

bool isNeedInteruptSpin() {
  int realDistance = abs(hollInputMass0[distance] - hollInputMass0[0])
    + abs(hollInputMass1[distance] - hollInputMass1[0]);
  if (numberOfMassAfterStart > distance && realDistance < high)
    return true;
  else
    return false;
}
