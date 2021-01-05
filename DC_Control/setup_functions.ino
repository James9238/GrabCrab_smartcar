void pinmodeSetup(){
  /*PWM enable*/
  pinMode(enLF, OUTPUT);
  pinMode(enLB, OUTPUT);
  pinMode(enRF, OUTPUT);
  pinMode(enRB, OUTPUT);
  /*H-Bridge direction control pins*/
  pinMode(inLF_1, OUTPUT); pinMode(inLF_2, OUTPUT); /*Left front motor*/
  pinMode(inLB_1, OUTPUT); pinMode(inLB_2, OUTPUT); /*Left back motor*/
  pinMode(inRF_1, OUTPUT); pinMode(inRF_2, OUTPUT); /*Right front motor*/
  pinMode(inRB_1, OUTPUT); pinMode(inRB_2, OUTPUT); /*Right back motor*/
  /*Control inputs*/
  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(potSWPin, INPUT);
  pinMode(xAxisPin2, INPUT);
  pinMode(yAxisPin2, INPUT);
  pinMode(potSWPin2, INPUT);
  pinMode(potPin, INPUT);
}

void directionSetup(){
  forward_LF();
  forward_LB();
  forward_RF();
  forward_RB();
}
