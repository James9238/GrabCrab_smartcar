/*
Individual motor direction setup for robot movements:
forward, reverse, slopeLF, slopeLB, slopeRF, slopeRB, strafeL, strafeR, turnL, turnR

combine forward, reverse, stop + _LF / _LB / _RF / _RB in according setups.
*/

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

// MISSING: Turn around rear and front center points. Forward and reverse while turning?