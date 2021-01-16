// GrabCrab Smartcar project //

/*
Author: Henrik Bryne
Mail: jegerbryne@gmail.com
2020/2021 USN Cybernetics
*/

/*TODO:
    Include encoder pins
        +2 pins * 4 encoders. A0-A5 free, need 2 more digital input pins.
        Possible to free 2 more pins?
            Combine direction control pinout with external logic?
  
    Complete functions for individual speed control based on encoder data.
        Clean up old test functions
    
    Serial comms with RPi, send/recieve functions.
        Identifier parse or separate software serials from RPi?
    
    Fix emergency stop implementation.
        external transistor circuit to cut power?
*/

// Define inputs, outputs and global variables // 

/*Nano PWM Pinout: 3, 5, 6, 9, 10, 11 //
/*Mega PWM Pinout: 2-13, 44-46*/

/*Define PWM pinout*/
#define enLF 5    // Left Front
#define enLB 10   // Left Back
#define enRF 6    // Right Front
#define enRB 11   // Right Back

/*Define in-ports*/
/*Left front: */
#define inLF_1  2
#define inLF_2  3
/*Left back: */
#define inLB_1  4
#define inLB_2  7
/*Right front: */
#define inRF_1  8
#define inRF_2  9
/*Right back: */
#define inRB_1  12
#define inRB_2  13

/*Define control inputs*/

#define potPin          A4

#define in1             A0
#define in2             A1
#define in3             A2
#define in4             A3

/*Control input variables*/
bool bit1 = 0;
bool bit2 = 0;
bool bit3 = 0;
bool bit4 = 0;

String directions = "NULL";

/*Motor speed variables*/
int motorSpeedLF = 0;
int motorSpeedLB = 0;
int motorSpeedRF = 0;
int motorSpeedRB = 0;

/*Variable for interrupt routine*/
bool EMERGENCY_STOP = false;
#define STOP_LED A5

// enum directions{forward, backward, slopeLF, slopeLB, slopeRF, slopeRB, strafeL, strafeR, turnL, turnR};
