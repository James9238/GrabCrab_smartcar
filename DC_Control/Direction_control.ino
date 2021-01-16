/*
Individual motor direction setup for robot movements:
forward, reverse, slopeLF, slopeLB, slopeRF, slopeRB, strafeL, strafeR, turnL, turnR

combine forward, reverse, stop + _LF / _LB / _RF / _RB in according setups.
*/

/*Serial comm codes:
Considering logical circuit to implement outputs to motor driver boards.

In use:
1111  |   stop_all
0010  |   forward
0011  |   reverse
0100  |   slopeLF
0101  |   slopeLB
0110  |   slopeRF
0111  |   slopeRB
1000  |   strafeL
1001  |   strafeR
1010  |   turnL
1011  |   turnR


Unused:
0000  |   NULL
0001  |   NULL
1100  |   NULL
1101  |   NULL
1110  |   NULL


*/

String readInput(){
  String inputBits = "";
  if(digitalRead(in1)){inputBits.concat("1");} else{inputBits.concat("0");}
  if(digitalRead(in2)){inputBits.concat("1");} else{inputBits.concat("0");}
  if(digitalRead(in3)){inputBits.concat("1");} else{inputBits.concat("0");}
  if(digitalRead(in4)){inputBits.concat("1");} else{inputBits.concat("0");}
  return inputBits;
}

void directionUpdate(String input){
  // 0010  |   forward
  if      (input == "0010"){forward();directions = "forward";}
  // 0011  |   reverse
  else if (input == "0011"){reverse();directions = "reverse";}
  // 0100  |   slopeLF
  else if (input == "0100"){slopeLF();directions = "slopeLF";}
  // 0101  |   slopeLB
  else if (input == "0101"){slopeLB();directions = "slopeLB";}
  // 0110  |   slopeRF
  else if (input == "0110"){slopeRF();directions = "slopeRF";}
  // 0111  |   slopeRB
  else if (input == "0111"){slopeRB();directions = "slopeRB";}
  // 1000  |   strafeL
  else if (input == "1000"){strafeL();directions = "strafeL";}
  // 1001  |   strafeR
  else if (input == "1001"){strafeR();directions = "strafeR";}
  // 1010  |   turnL
  else if (input == "1010"){turnL();directions = "turnL";}
  // 1011  |   turnR
  else if (input == "1011"){turnR();directions = "turnR";}
  // 1111  |   stop all
  else if (input == "1111"){stop_all();directions = "stop_all";}
}

void forward(){
  forward_LF(); forward_LB(); forward_RF(); forward_RB();
}

void reverse(){
  reverse_LF(); reverse_LB(); reverse_RF(); reverse_RB(); 
}

// Drive left forwards at 45 degrees
void slopeLF(){
  STOP_LF(); STOP_RB(); forward_LB(); forward_RF();
}

// Drive left backwards at 45 degrees
void slopeLB(){
  STOP_LB(); STOP_RF(); reverse_LF(); reverse_RB(); 
}

// Drive right forwards at 45 degrees
void slopeRF(){
  STOP_LB(); STOP_RF(); forward_LF(); forward_RB(); 
}

// Drive right backwards at 45 degrees
void slopeRB(){
  STOP_LF(); STOP_RB(); forward_RF(); forward_LB();
}

// Strafe left at 90 degrees to vehicle orientation
void strafeL(){
  forward_LF(); reverse_LB(); reverse_RF(); forward_RB();
}

// Strafe right at 90 degrees to vehicle orientation
void strafeR(){
  reverse_LF(); forward_LB(); forward_RF(); reverse_RB();
}

// Turn left around vehicle centerpoint
void turnL(){
  forward_LF(); forward_LB(); reverse_RF(); reverse_RB();
}

// Turn right around vehicle centerpoint
void turnR(){
  reverse_LF(); reverse_LB(); forward_RF(); forward_RB();
}

// Set all motor controls to stop position
void stop_all(){
  STOP_LF(); STOP_LB(); STOP_RF(); STOP_RB();
}

// MISSING: Turn around rear and front center points. Forward and reverse while turning? //

// DIRECTION CONTROL BASE FUNCTIONS: //

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
  digitalWrite(inRF_1, LOW); digitalWrite(inRF_2, LOW);
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
  digitalWrite(inRB_1, LOW); digitalWrite(inRB_2, LOW);
}

/*
  Need better emergency stop implementation.
  Control external transistor to cut power?
*/
void STOP_ISR(){
  STOP_LF(); STOP_LB(); STOP_RF(); STOP_RB();
  EMERGENCY_STOP = true;
  digitalWrite(STOP_LED, HIGH);
}