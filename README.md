# GrabCrab_smartcar
 
# // GrabCrab Smartcar project //

#### Goal:
Smart vehicle with SLAM & Object recognition.  
Servocontrolled robotic arm(s) for handling objects.  
Individual microcontrollers for separate tasks.  
-- RPi master controller with remote live feed.  

## // TODO //  
### PLANNING:  
- Chassis layout.  
- Logic circuitry for reduced motorcontrol pin usage.  
- Part positioning and weight distribution for complete assembly.  
-   
  
### Progress:  
- [x] All motor direction control functions complete and functional, tested with ad-hoc 5bit remote.  
- [ ] Working on I/O logic for direction control communication with driver board to free up digital pins for encoder inputs.  
- [ ] Planning
  
### Parts:   
#### Controllers:  
- [x] RPi 4B 4GB (might need upgrade, TBD)
- [x] Arduino nano ARN1 (motor control)  
- [x] Arduino nano ARN2 (Servo and sensor controller).  
#### Other parts:  
- [x] 4x DC Motor w/ encoder  
- [x] 2x L298N Motor drivers (strongly considering upgrade due to voltage drop).  
- [x] 4x Servo(180*)  
- [x] 2x Servo(360*)
- [x] PCA9685 Servo driver board  
- [x] Breadboards and wiring
- [x] Assorted resistors
- [ ] Movement and mapping sensors  
- [x] -- 2x Ultrasonic Distance sensors  
-- -- Degrees of sensitivity?  
- [x] -- RPi compaible camera module. v2?  
- [ ] -- SLAM method? Modules for this.  
-- More? TBD  
- [ ] 14.4V battery pack  
- [ ] -- Might need separate 4A 5V source for RPi + arduinos  
- [ ] Casing materials for circuitry and controllers  
- [ ] -- 3mm PC or 2/4mm SAN plates should be fine for casings.  
- [ ] -- 4mm PMMA for top plate?  
