void setup() {
  // attachInterrupt(digitalPinToInterrupt(potSWPin), STOP_ISR, RISING);
  pinmodeSetup();       /*Output and input setup*/
  directionSetup();     /*Startup direction setup*/
  Serial.begin(9600);
}

void loop() {
  /*something goes here*/

  int potVal = map(analogRead(potPin), 0, 1023, 0, 255);

  Serial.println(potVal);

  update_LF(potVal);
  update_RF(potVal);
  update_LB(potVal);
  update_RB(potVal);
  
}
