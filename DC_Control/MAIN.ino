void setup() {
  attachInterrupt(digitalPinToInterrupt(potSWPin), STOP_ISR, RISING);
  pinmodeSetup();       /*Output and input setup*/
  directionSetup();     /*Startup direction setup*/
}

void loop() {
  /*Joystick values*/
  int xAxis = analogRead(xAxisPin);
  int yAxis = analogRead(yAxisPin);
  bool potSW = digitalRead(potSWPin);
  
  if(!EMERGENCY_STOP){
    yAxisControl(yAxis);  /*Reads and maps yAxis to 0-255 and adjusts engine speeds and direction*/
    xAxisControl(xAxis);  /*Reads and maps xAxis to 0-255 and adjusts engine speeds and direction*/

    motorUpdate(); /*Update all motors with motorspeeds from control functions*/
  }
}
