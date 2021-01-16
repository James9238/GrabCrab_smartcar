void setup() {
  // attachInterrupt(digitalPinToInterrupt(potSWPin), STOP_ISR, RISING);
  pinmodeSetup();       /*Output and input setup*/
  directionSetup();     /*Startup direction setup*/
  Serial.begin(9600);
}

void loop() {
  /*--TESTROUTINE--*/
  String inputBits = readInput();  // Binary 4bit direction control input. 
  
  int potVal = map(analogRead(potPin), 0, 1023, 0, 255);
  
  
  directionUpdate(inputBits);
  update_LF(potVal);
  update_RF(potVal);
  update_LB(potVal);
  update_RB(potVal);
  
  /*Serial debug-feed*/
  Serial.print("potVal: "); Serial.print(potVal); Serial.print(" | ");
  Serial.print("inputs: "); Serial.print(inputBits);
  Serial.print(" | ");
  Serial.print("directions: "); Serial.print(directions);
  Serial.println();
}
