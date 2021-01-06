/*
Individual motor direction setup for robot movements:
forward, reverse, slopeLF, slopeLB, slopeRF, slopeRB, strafeL, strafeR, turnL, turnR

combine forward, reverse, stop + _LF / _LB / _RF / _RB in according setups.
*/

/*Serial comm codes:

// Not enough free pins for servo control on Arduino 1 with this solution //

In use:
1111  |   stop all
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

void readControlInput(){
  bit1 = digitalRead(in1);
  bit2 = digitalRead(in2);
  bit3 = digitalRead(in3);
  bit4 = digitalRead(in4);
}

void directionUpdate(){
  // 0010  |   forward
  if      (!bit4 && !bit3 && bit2 && !bit1){forward();}
  // 0011  |   reverse
  else if (!bit4 && !bit3 && bit2 && bit1){reverse();}
  // 0100  |   slopeLF
  else if (!bit4 && bit3 && !bit2 && !bit1){slopeLF();}
  // 0101  |   slopeLB
  else if (!bit4 && bit3 && !bit2 && bit1){slopeLB();}
  // 0110  |   slopeRF
  else if (!bit4 && bit3 && bit2 && !bit1){slopeRF();}
  // 0111  |   slopeRB
  else if (!bit4 && bit3 && bit2 && bit1){slopeRB();}
  // 1000  |   strafeL
  else if (bit4 && !bit3 && !bit2 && !bit1){strafeL();}
  // 1001  |   strafeR
  else if (bit4 && !bit3 && !bit2 && bit1){strafeR();}
  // 1010  |   turnL
  else if (bit4 && !bit3 && bit2 && !bit1){turnL();}
  // 1011  |   turnR
  else if (bit4 && !bit3 && bit2 && bit1){turnR();}
  // 1111  |   stop all
  else if (bit4 && bit3 && bit2 && bit1){turnR();}
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

// Set all motor controls to stop
void stop_all(){
  STOP_LF(); STOP_LB(); STOP_RF(); STOP_RB();
}

// MISSING: Turn around rear and front center points. Forward and reverse while turning?
