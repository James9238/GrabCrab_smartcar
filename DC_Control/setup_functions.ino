void pinmodeSetup(){
  /*PWM enable*/
  pinMode(enLF, OUTPUT);
  pinMode(enLB, OUTPUT);
  pinMode(enRF, OUTPUT);
  pinMode(enRB, OUTPUT);
  /*H-Bridge direction control pins*/
  pinMode(inLF_1, OUTPUT); pinMode(inLF_2, OUTPUT); /*Left front engine*/
  pinMode(inLB_1, OUTPUT); pinMode(inLB_2, OUTPUT); /*Left back engine*/
  pinMode(inRF_1, OUTPUT); pinMode(inRF_2, OUTPUT); /*Right front engine*/
  pinMode(inRB_1, OUTPUT); pinMode(inRB_2, OUTPUT); /*Right back engine*/
  /*Control inputs*/
  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(potSWPin, INPUT);
}

void directionSetup(){
  forward_LF();
  forward_LB();
  forward_RF();
  forward_RB();
}
