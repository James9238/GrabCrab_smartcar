#define in1 8
#define in2 9
#define enA 2

#define potPin A0


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(potPin, INPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void loop() {
  int potVal = map(analogRead(potPin), 0, 1023, 0, 255);
  if(potVal < 70){
    potVal = 0;
  }
  analogWrite(enA, potVal);
}
