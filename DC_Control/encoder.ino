//      Encoder setup functions       //
//              WIP                   //
// ---------------------------------- //

/*Encoder inputs -- Interrupts*/
// encoderLF_A, encoderLF_B
// encoderLB_A, encoderLB_B
// encoderRF_A, encoderRF_B
// encoderRB_A, encoderRB_B

/*Encoder counters:*/
// encoderCount_LF
// encoderCount_LB
// encoderCount_RF
// encoderCount_RB

/*Encoder interrupts: */
// ISR_encoderLF_A
// ISR_encoderLF_B
// ISR_encoderLB_A
// ISR_encoderLB_B
// ISR_encoderRF_A
// ISR_encoderRF_B
// ISR_encoderRB_A
// ISR_encoderRB_B


//*CHANGE FUNCTION TYPE. ISR(). ADJUST pinA vs pinB to motor orientation so all count forwards*//
void ISR_encoderLF_A(){
    bool pinA = digitalRead(encoderLF_A);
    bool pinB = digitalRead(encoderLF_B);

    if(pinB == LOW){
        if(pinA == HIGH){
            encoderCount_LF++;
        }
        else{
            encoderCount_LF--;
        }
    }
    else{
        if(pinA == HIGH){
            encoderCount_LF--;
        }
        else{
            encoderCount_LF++;
        }
    }
}
void ISR_encoderLF_B(){
    bool pinA = digitalRead(encoderLF_A);
    bool pinB = digitalRead(encoderLF_B);

    if(pinA == LOW){
        if(pinB == HIGH){
            encoderCount_LF--;
        }
        else{
            encoderCount_LF++;
        }
    }
    else{
        if(pinB == HIGH){
            encoderCount_LF++;
        }
        else{
            encoderCount_LF--;
        }
    }    
}
void ISR_encoderLB_A(){
    bool pinA = digitalRead(encoderLB_A);
    bool pinB = digitalRead(encoderLB_B);

    if(pinB == LOW){
        if(pinA == HIGH){
            encoderCount_LB++;
        }
        else{
            encoderCount_LB--;
        }
    }
    else{
        if(pinA == HIGH){
            encoderCount_LB--;
        }
        else{
            encoderCount_LB++;
        }
    }
}
void ISR_encoderLB_B(){
    bool pinA = digitalRead(encoderLB_A);
    bool pinB = digitalRead(encoderLB_B);

    if(pinA == LOW){
        if(pinB == HIGH){
            encoderCount_LB--;
        }
        else{
            encoderCount_LB++;
        }
    }
    else{
        if(pinB == HIGH){
            encoderCount_LB++;
        }
        else{
            encoderCount_LB--;
        }
    }    
}
void ISR_encoderRF_A(){
    bool pinA = digitalRead(encoderRF_A);
    bool pinB = digitalRead(encoderRF_B);

    if(pinB == LOW){
        if(pinA == HIGH){
            encoderCount_RF++;
        }
        else{
            encoderCount_RF--;
        }
    }
    else{
        if(pinA == HIGH){
            encoderCount_RF--;
        }
        else{
            encoderCount_RF++;
        }
    }
}
void ISR_encoderRF_B(){
    bool pinA = digitalRead(encoderRF_A);
    bool pinB = digitalRead(encoderRF_B);

    if(pinA == LOW){
        if(pinB == HIGH){
            encoderCount_RF--;
        }
        else{
            encoderCount_RF++;
        }
    }
    else{
        if(pinB == HIGH){
            encoderCount_RF++;
        }
        else{
            encoderCount_RF--;
        }
    }    
}
void ISR_encoderRB_A(){
    bool pinA = digitalRead(encoderRB_A);
    bool pinB = digitalRead(encoderRB_B);

    if(pinB == LOW){
        if(pinA == HIGH){
            encoderCount_RB++;
        }
        else{
            encoderCount_RB--;
        }
    }
    else{
        if(pinA == HIGH){
            encoderCount_RB--;
        }
        else{
            encoderCount_RB++;
        }
    }
}
void ISR_encoderRB_B(){
    bool pinA = digitalRead(encoderRB_A);
    bool pinB = digitalRead(encoderRB_B);

    if(pinA == LOW){
        if(pinB == HIGH){
            encoderCount_RB--;
        }
        else{
            encoderCount_RB++;
        }
    }
    else{
        if(pinB == HIGH){
            encoderCount_RB++;
        }
        else{
            encoderCount_RB--;
        }
    }    
}

/*Placeholder encoder math function. Need one for each counter.*/
void PLH_LF(){
    time = millis();
    timeChange = time-timePrev;
    theta = encoderCount_LF/rotPerRev; // rotPerRev = motor internal rotations per output revolution
    RPM = (theta-thetaPrev)/(timeChange/1000)*60;
    thetaPrev = theta;
    timePrev = time;
}

//**SINE LIMITER FUNCTION**//
float sign(float x){
  if (x > 0) {
    return 1;
  } else if (x < 0) {
    return -1;
  } else {
    return 0;
  }
}

//**TIMER COMPARE COUNT**// 50ms per count // 
ISR(TIMER1_COMPA_vect){
  count++;
  Serial.print(count * 0.05); Serial.print(" \t");
}



/*Encoder lib and setup*/
// #include <Encoder.h>
// Encoder encoderLF(encoderLF_A, encoderLF_B);
// Encoder encoderLB(encoderLB_A, encoderLB_B);
// Encoder encoderRF(encoderRF_A, encoderRF_B);
// Encoder encoderRB(encoderRB_A, encoderRB_B);



/*Interrupt setup function*/
void pciSetup(int pin){
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // Enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // Clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // Enable interrupt for the group
}

