// GrabCrab Smartcar project //

/*
Author: Henrik Bryne
Mail: jegerbryne@gmail.com
2020/2021 USN Cybernetics first year
*/

// Define inputs, outputs and global variables // 

/*Nano PWM Pinout: 3, 5, 6, 9, 10, 11 // 490Hz(980Hz: pin 5, 6*/
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

#define potPin          A0

#define in1             A1
#define in2             A2
#define in3             A3
#define in4             A4

/*Control input variables*/
bool bit1 = 0;
bool bit2 = 0;
bool bit3 = 0;
bool bit4 = 0;



/*Motor speed variables*/
int motorSpeedLF = 0;
int motorSpeedLB = 0;
int motorSpeedRF = 0;
int motorSpeedRB = 0;

/*Variable for interrupt routine*/
bool EMERGENCY_STOP = false;
#define STOP_LED A5

// enum directions{forward, backward, slopeLF, slopeLB, slopeRF, slopeRB, strafeL, strafeR, turnL, turnR};
