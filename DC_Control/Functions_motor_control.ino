/*Individual motor speed update functions*/
void update_LF(int value){
  if(inLF_1 != inLF_2){
    if(value < 70){
      analogWrite(enLF, 0);
    }
    else{
      analogWrite(enLF, value);
    }
  }
}

void update_LB(int value){
  if(inLB_1 != inLB_2){
    if(value < 70){
      analogWrite(enLB, 0);
    }
    else{
      analogWrite(enLB, value);
    }
  }
}

void update_RF(int value){
  if(inRF_1 != inRF_2){
    if(value < 70){
      analogWrite(enRF, 0);
    }
    else{
      analogWrite(enRF, value);
    }
  }
}

void update_RB(int value){
  if(inRB_1 != inRB_2){
    if(value < 70){
      analogWrite(enRB, 0);
    }
    else{
      analogWrite(enRB, value);
    }
  }
}

/*Compressed update call function*/
void motorUpdate(){
  update_LF(motorSpeedLF);  update_LB(motorSpeedLB);  update_RF(motorSpeedRF);  update_RB(motorSpeedRB);
}

