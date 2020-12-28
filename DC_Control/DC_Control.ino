/*Joystick DC Control for GrabCrab smartcar*/

/*Nano PWM Pinout: 3, 5, 6, 9, 10, 11 // 490Hz(980Hz: pin 5, 6*/
/*Mega PWM Pinout: 2-13, 44-46*/

/*Define PWM pinout*/
#define enLF 3 // Left Front
#define enLB 5 // Left Back
#define enRF 6 // Right Front
#define enRB 9 // Right Back

/*Define in-ports*/
/*Left front: */
#define inLF_1  1
#define inLF_2  2
/*Left back: */
#define inLB_1  4
#define inLB_2  7
/*Right front: */
#define inRF_1  8
#define inRF_2  10
/*Right back: */
#define inRB_1  11
#define inRB_2  12

/*Define control inputs*/
#define xAxisPin       A0
#define yAxisPin       A1
#define potSWPin       A2

/*Motor speed variables*/
int motorSpeedLF = 0;
int motorSpeedLB = 0;
int motorSpeedRF = 0;
int motorSpeedRB = 0;

bool EMERGENCY_STOP = false;
#define STOP_LED A5
