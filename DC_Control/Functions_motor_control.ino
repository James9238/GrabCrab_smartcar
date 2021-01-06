void STOP_ISR(){
  STOP_LF(); STOP_LB(); STOP_RF(); STOP_RB();
  EMERGENCY_STOP = true;
  digitalWrite(STOP_LED, HIGH);
}

void yAxisControl(int y){
  if(y > 550){
    /*Set all motors forward*/
    forward_LF(); forward_LB(); forward_RF(); forward_RB();
    motorSpeedLF = map(y, 550, 1023, 0, 255);
    motorSpeedLB = map(y, 550, 1023, 0, 255);
    motorSpeedRF = map(y, 550, 1023, 0, 255);
    motorSpeedRB = map(y, 550, 1023, 0, 255);
  }
  else if(y < 470){
    /*Set all motors in reverse*/
    reverse_LF(); reverse_LB(); reverse_RF(); reverse_RB();
    motorSpeedLF = map(y, 470, 0, 0, 255);
    motorSpeedLB = map(y, 470, 0, 0, 255);
    motorSpeedRF = map(y, 470, 0, 0, 255);
    motorSpeedRB = map(y, 470, 0, 0, 255);
  }
}
void xAxisControl(int x){
  if(x < 470){
    /*Turn left, decrease left speed -> increase right speed*/
    int xMapped = map(x, 470, 0, 0, 255);
    motorSpeedLF = motorSpeedLF - xMapped;
    motorSpeedLB = motorSpeedLB - xMapped;
    motorSpeedRF = motorSpeedRF + xMapped;
    motorSpeedRB = motorSpeedRB + xMapped;
    /*Limit range to 0-255 for all motors*/
    if(motorSpeedLF < 0){motorSpeedLF = 0;} if(motorSpeedLF > 255){}{motorSpeedLF = 255;}
    if(motorSpeedLB < 0){motorSpeedLB = 0;} if(motorSpeedLB > 255){}{motorSpeedLB = 255;}
    if(motorSpeedRF < 0){motorSpeedRF = 0;} if(motorSpeedRF > 255){}{motorSpeedRF = 255;}
    if(motorSpeedRB < 0){motorSpeedRB = 0;} if(motorSpeedRB > 255){}{motorSpeedRB = 255;}
  }
  if(x > 550){
    /*Turn right, decrease right speed -> increase left speed*/
    int xMapped = map(x, 470, 0, 0, 255);
    motorSpeedLF = motorSpeedLF + xMapped;
    motorSpeedLB = motorSpeedLB + xMapped;
    motorSpeedRF = motorSpeedRF - xMapped;
    motorSpeedRB = motorSpeedRB - xMapped;
    /*Limit range to 0-255 for all motors*/
    if(motorSpeedLF < 0){motorSpeedLF = 0;} if(motorSpeedLF > 255){}{motorSpeedLF = 255;}
    if(motorSpeedLB < 0){motorSpeedLB = 0;} if(motorSpeedLB > 255){}{motorSpeedLB = 255;}
    if(motorSpeedRF < 0){motorSpeedRF = 0;} if(motorSpeedRF > 255){}{motorSpeedRF = 255;}
    if(motorSpeedRB < 0){motorSpeedRB = 0;} if(motorSpeedRB > 255){}{motorSpeedRB = 255;}
  }
  /*Possibly required lower limit. Set to 20 initially, adjust up if necessary*/
  if(motorSpeedLF < 20){motorSpeedLF = 0;}
  if(motorSpeedLB < 20){motorSpeedLB = 0;}
  if(motorSpeedRF < 20){motorSpeedRF = 0;}
  if(motorSpeedRB < 20){motorSpeedRB = 0;}
}

void update_LF(int value){
  analogWrite(enLF, value);
}
void update_LB(int value){
  analogWrite(enLB, value);
}
void update_RF(int value){
  analogWrite(enRF, value);
}
void update_RB(int value){
  analogWrite(enRB, value);
}

void motorUpdate(){
  update_LF(motorSpeedLF);  update_LB(motorSpeedLB);  update_RF(motorSpeedRF);  update_RB(motorSpeedRB);
}

/*Left front forward*/
void forward_LF(){
  digitalWrite(inLF_1, LOW); digitalWrite(inLF_2, HIGH);
}
/*Left front reverse*/
void reverse_LF(){
  digitalWrite(inLF_1, HIGH); digitalWrite(inLF_2, LOW);
}
/*Left front STOP*/
void STOP_LF(){
  digitalWrite(inLF_1, LOW); digitalWrite(inLF_2, LOW);
}


/*Left back forward*/
void forward_LB(){
  digitalWrite(inLB_1, LOW); digitalWrite(inLB_2, HIGH);
}
/*Left back reverse*/
void reverse_LB(){
  digitalWrite(inLB_1, HIGH); digitalWrite(inLB_2, LOW);
}
/*Left back STOP*/
void STOP_LB(){
  digitalWrite(inLB_1, LOW); digitalWrite(inLB_2, LOW);
}


/*Right front forward*/
void forward_RF(){
  digitalWrite(inRF_1, LOW); digitalWrite(inRF_2, HIGH);
}
/*Right front reverse*/
void reverse_RF(){
  digitalWrite(inRF_1, HIGH); digitalWrite(inRF_2, LOW);
}
/*Right front STOP*/
void STOP_RF(){
  digitalWrite(inRF_1, LOW); digitalWrite(inRF_2, HIGH);
}


/*Right back forward*/
void forward_RB(){
  digitalWrite(inRB_1, LOW); digitalWrite(inRB_2, HIGH);
}
/*Right back reverse*/
void reverse_RB(){
  digitalWrite(inRB_1, HIGH); digitalWrite(inRB_2, LOW);
}
/*Right back STOP*/
void STOP_RB(){
  digitalWrite(inRB_1, LOW); digitalWrite(inRB_2, HIGH);
}
