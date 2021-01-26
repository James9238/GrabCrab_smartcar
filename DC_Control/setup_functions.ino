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

}

void encoderSetup(){
  /*Encoder pinMode*/
  pinMode(encoderLF_A, INPUT_PULLUP);
  pinMode(encoderLF_B, INPUT_PULLUP);

  pinMode(encoderLB_A, INPUT_PULLUP);
  pinMode(encoderLB_B, INPUT_PULLUP);
  
  pinMode(encoderRF_A, INPUT_PULLUP);
  pinMode(encoderRF_B, INPUT_PULLUP);

  pinMode(encoderRB_A, INPUT_PULLUP);
  pinMode(encoderRB_B, INPUT_PULLUP);

  /*PCI interrupt setup for encoder pins*/
  pciSetup(encoderLF_A); pciSetup(encoderLF_B);
  pciSetup(encoderLB_A); pciSetup(encoderLB_B);
  pciSetup(encoderRF_A); pciSetup(encoderRF_B);
  pciSetup(encoderRB_A); pciSetup(encoderRB_B);

  /*Interrupt routine attach*/
  attachInterrupt(digitalPinToInterrupt(encoderLF_A), ISR_encoderLF_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderLF_B), ISR_encoderLF_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderLB_A), ISR_encoderLB_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderLB_B), ISR_encoderLB_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderRF_A), ISR_encoderRF_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderRF_B), ISR_encoderRF_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderRB_A), ISR_encoderRB_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderRB_B), ISR_encoderRB_B, CHANGE);
}

void HWTimerInterrupt(){
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 12499; //Prescaler = 64
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS11 | 1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

/*Boot with stop_all()?*/
void directionSetup(){
  forward_LF();
  forward_LB();
  forward_RF();
  forward_RB();
}