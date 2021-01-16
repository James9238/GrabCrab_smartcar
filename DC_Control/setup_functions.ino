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
  /*Test control inputs on A0-A4*/
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  pinMode(potPin, INPUT);
}

/*Boot with stop_all()?*/
void directionSetup(){
  forward_LF();
  forward_LB();
  forward_RF();
  forward_RB();
}
