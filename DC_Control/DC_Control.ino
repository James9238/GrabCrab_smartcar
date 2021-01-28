// GrabCrab Smartcar project //

/*
Author: Henrik Bryne
Mail: jegerbryne@gmail.com
2020/2021 USN Cybernetics
*/

/*
    WIP:
        Encoder functions
        -- Update encoder pinouts to correct INT Vectors
        -- Find encoder count for 1 revolution of motor output shaft
            -- Reference below link for interrupt details and registers:
            -- Reference ATmega2560 datasheet 15.2 Register Description.
            -- Use 6 external: INT5->0 & 2/3 pin change interrupts: PCINT0-2
            -- More research on implementation. attachInterrupt invalid.
        -- Should also test accuracy with 1 encoder/motor.
            -- Shouldn't need directional input, which is the benefit of 2.
http://arduinomega.blogspot.com/2011/05/setting-interrupts-manually-real-int0.html
        
*/

/*TODO:
    -- Move all pinouts to Mega in pinout sheet
    -- Set encoder pins in pinout sheet and implement here. 

    -- Find or design motor & encoder shield for Mega2560!

    -- Clean up clean up clean up all the time. Pls me.
    
    -- Serial comms with RPi, send/recieve functions.
        -- Identifier parse or separate software serials from RPi?
        -- ID parse and clear all with invalid ID should work.
            -- TX2/RX2 clear, passthrough maybe?
    
    -- Fix emergency stop implementation.
        -- External circuit to cut power?
        -- Need software control.
*/

// Define inputs, outputs and global variables // 

/*Define encoder inputs*/
/*DUMMY PINS! EDIT / EDIT!!!*/

const int encoderLF_A = 22; // Interrupt vector A
const int encoderLF_B = 23; // Interrupt vector A

const int encoderLB_A = 24; // Interrupt vector B
const int encoderLB_B = 25; // Interrupt vector B

const int encoderRF_A = 26; // Interrupt vector C
const int encoderRF_B = 27; // Interrupt vector C

const int encoderRB_A = 28; // Interrupt vector D
const int encoderRB_B = 29; // Interrupt vector D

/*Set encoder and timer counters*/
volatile long encoderCount_LF   = 0;
volatile long encoderCount_LB   = 0;
volatile long encoderCount_RF   = 0;
volatile long encoderCount_RB   = 0;

int rotPerRev                   = 50;

volatile unsigned long count    = 0;
unsigned long countPrev         = 0;

unsigned long time              = 0;
unsigned long timeChange        = 0;
unsigned long timePrev          = 0;

float theta, RPM, RPM_target;
float thetaPrev                 = 0;

float RPM_max                   = 330;
#define pi 3.1416
float Vmax                      = 12;
float Vmin                      = -12;
float V                         = 0.1;
float e, ePrev = 0, inte, intePrev = 0;
float kp                        = 0.02;
float ki                        = 0.00015;
float kd                        = 0;



/*Nano PWM Pinout: 3, 5, 6, 9, 10, 11 //
/*Mega PWM Pinout: 2-13, 44-46*/

/*Define PWM pinout*/
#define enLF 5    // Left Front
#define enLB 10   // Left Back
#define enRF 6    // Right Front
#define enRB 11   // Right Back

/*Define in-ports*/
/*Left front: */
#define inLF_1  A5
#define inLF_2  A4
/*Left back: */
#define inLB_1  A3
#define inLB_2  A2
/*Right front: */
#define inRF_1  8
#define inRF_2  9
/*Right back: */
#define inRB_1  12
#define inRB_2  13

/*TEST SETUP INPUTS // unused //

#define potPin          A4

#define in1             A0
#define in2             A1
#define in3             A2
#define in4             A3
*/

/*TEST CONTROL VARS // unused //
bool bit1 = 0;
bool bit2 = 0;
bool bit3 = 0;
bool bit4 = 0;
String directions = "NULL";
*/


/*Motor speed variables*/
int motorSpeedLF = 0;
int motorSpeedLB = 0;
int motorSpeedRF = 0;
int motorSpeedRB = 0;

String directions = "NULL";

/* PLACEHOLDER ISR, NEW SOLUTION REQUIRED. 
 * ALL INTERRUPT CHANNELS OCCUPIED.
 * Variable for interrupt routine
 */
bool EMERGENCY_STOP = false;
#define STOP_LED A5

// enum directions{forward, backward, slopeLF, slopeLB, slopeRF, slopeRB, strafeL, strafeR, turnL, turnR};
