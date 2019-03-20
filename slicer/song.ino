#define songPin 22
unsigned long timeBeginSong;
unsigned long songTimeSmall = 40;
unsigned long songTimeLong = 600;

void songSetup() {
  pinMode(songPin, OUTPUT);
  digitalWrite(songPin, HIGH);
  timeBeginSong = millisecond;
}

void songUpdate() {
  if (millisecond < timeBeginSong) {
    digitalWrite(songPin, LOW);
  }
  else {
    digitalWrite(songPin, HIGH);
  }
}

void callSongSmall() {
  timeBeginSong = millisecond + songTimeSmall;
}
void callSongLong() { 
  timeBeginSong = millisecond + songTimeLong; 
}
