#define numberOfPin 2

int hollInputPin[numberOfPin] = {A0, A1};
int hollInputData[numberOfPin] = {529, 529};

#define hollMassLen 500
int hollInputMass0[hollMassLen];
int hollInputMass1[hollMassLen];
unsigned long lastMillis;

#define hollMassLenSmall 20
int hollInputMassSmall0[hollMassLenSmall];
int hollInputMassSmall1[hollMassLenSmall];
unsigned long lastMillisSmall;

unsigned long m;

void hollSetup(){
  lastMillis = millisecond;
  lastMillisSmall = millisecond;
  m = millisecond;
}

void hollUpdate(){
  getDataFromSensor();
  getSmallData();
  getBigData();

  /*if (millisecond - m > 10000){
    for(int i = hollMassLen - 1; i >= 0 ; i--){
      Serial.println(hollInputMass[i]);
    }
    m = millisecond;
  }*/
  if (millisecond - m > 100){
    Serial.println((String)(hollInputData[0]) + " " + (String)(hollInputData[1]));
    m = millisecond;
  }
}

void getDataFromSensor(){
  for(int i = 0; i < numberOfPin; i++)
    hollInputData[i] = analogRead(hollInputPin[i]);
}

void getSmallData(){
  if (lastMillisSmall != millisecond){
    addNewDataToMassiveSmall(hollInputData);
    lastMillisSmall = millisecond;
  }
}
void addNewDataToMassiveSmall(int* data){
  for(int i = hollMassLenSmall - 1; i > 0; i--){
    hollInputMassSmall0[i] = hollInputMassSmall0[i-1]; 
    hollInputMassSmall1[i] = hollInputMassSmall1[i-1]; 
  }
  hollInputMassSmall0[0] = data[0];
  hollInputMassSmall1[0] = data[1];
}

void getBigData(){
  if (millisecond - lastMillis >= hollMassLenSmall){
    addNewDataToMassive(getMiddle());
  }
}
void addNewDataToMassive(int* data){
  for(int i = hollMassLen - 1; i > 0; i--){
    hollInputMass0[i] = hollInputMass0[i-1]; 
    hollInputMass1[i] = hollInputMass1[i-1]; 
  }
  hollInputMass0[0] = data[0];
  hollInputMass1[0] = data[1];
}
int* getMiddle(){
  int middle[] = {0,0};
  for(int i = 0; i < hollMassLenSmall; i++){
    middle[0] += hollInputMassSmall0[i];
    middle[1] += hollInputMassSmall1[i]; 
  }
  middle[0] = middle[0] / lastMillisSmall;
  middle[1] = middle[1] / lastMillisSmall;
  return middle;
}
