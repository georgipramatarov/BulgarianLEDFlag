#define latchPin 2
#define clockPin 0
#define dataPin 1
byte dataToSend;
byte i;
byte j;
// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
 for(i=0; i<3; i++){
  for(j=0; j<4; j++){
    dataToSend = (1<<(i+4)) | (15 & ~(1 << j));
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, dataToSend);
    digitalWrite(latchPin, HIGH);
  }
 }
}
