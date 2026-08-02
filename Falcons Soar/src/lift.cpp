#include "main.h"

//1 is rotational
//2 is limit rotational
pros::Rotation rotLow(1);
pros::Rotation rotHigh(2);
pros::Motor liftLow ((int)-11, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor liftHigh ((int)5, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);

pros::adi::Pneumatics clamp('a', false);
pros::adi::Pneumatics tilt('b', false);

liftPID pidLow(6,0,24,0); // pid parameters
liftPID pidHigh(1,0,0,0);
bool resetting = true;
// limits all in centidegrees
double homeHigh = 0;
double homeLow=0;
double limitHigh =69500; //
double limitLow = 12375; //
double targetHigh = homeHigh;
double targetLow = homeLow;
int increment = 0; // variable to keep track of time for driver macros
int resetCounter = 0;
void liftLoop(){
    if(resetting){
        liftLow.move_voltage(-12000);
        liftHigh.move_voltage(-12000);
        if(abs(liftLow.get_actual_velocity()) < 10 && abs(liftHigh.get_actual_velocity())<10){
           resetCounter++;
        }
        if(resetCounter >20){
             resetting=false;
            rotLow.reset_position();
            rotHigh.reset_position();
            liftLow.move_voltage(0);
            liftHigh.move_voltage(0);
            master.rumble("...");
        }
    }
    if(!rotHigh.get_reversed()){
        rotHigh.reverse();
    }

    // increment the variable if its not 0 or negative
    if(increment>0){
        increment++; 
    }

    // after 50 ms move the top arm up to free it from the intake
    if(increment==5){
        targetHigh=8650;
        targetLow=1406;
    }

    // after 150 ms tilt the claw and set the increment to -1 to wait for next input 
    if(increment==20){
        tilt.extend();
        increment=-1;
    }

    // after new input and 300ms move the top arm up out of the way of the stack
    if(increment==50){
        tilt.extend();
        targetHigh=limitHigh;
        targetLow=limitLow;
        
    }

    // after 300 ms move the bottom lift to the bottom
    if(increment==80){
        targetLow=homeLow;
    }

    // wait until bottom lift is close to the bottom to move the top arm to home
    if(increment>80&&rotLow.get_position()<2000){
        targetHigh=homeHigh;
    }

    // once the top arm is close to home untilt the claw for intaking
    if(increment>80&&rotHigh.get_position()<6000){
        tilt.retract();
        increment=0;
    }
    
    // detect when L1 is pressed
    if(master.get_digital_new_press(DIGITAL_L1)){
        // clamp and start the sequence
        if(increment==0){
            clamp.extend();
            increment=1;
        }
        // on the repress start the return to home sequence and unclamp
        else{
            increment =21 ;
            clamp.retract();
        }
        
    }
    
    if(targetHigh>limitHigh){
        targetHigh=limitHigh;
    }
    if(targetHigh<homeHigh){
        targetHigh=homeHigh;
    }
    if(targetLow>limitLow){
        targetLow=limitLow;
    }
    if(targetLow<homeLow){
        targetLow=homeLow;
    }

    // return arms to home using the increment sequence
    if(master.get_digital_new_press(DIGITAL_L2)){
        increment==50;
    }
    
    
    if(master.get_digital(DIGITAL_UP)){
        targetHigh-=800;
        
    }

    else if(master.get_digital(DIGITAL_DOWN)){
        targetHigh+=800;
        
    }
    else{
        //liftHigh.move_velocity(0);
    }
    if(master.get_digital(DIGITAL_RIGHT)){
        targetLow+=200;
        targetHigh+=1000;
        
    }
    else if(master.get_digital(DIGITAL_LEFT)){
        targetLow+=200;
        targetHigh+=1000;
        
    }
    
    // move the lift motors from the inputs of the pids.
    if(!resetting){
    liftLow.move_voltage(2000+pidLow.update(targetLow-rotLow.get_position()));
    liftHigh.move_voltage(pidHigh.update(targetHigh-rotHigh.get_position()));
    }
    pros::lcd::set_text(1, std::to_string(rotLow.get_position()));
    pros::lcd::set_text(2, std::to_string(rotHigh.get_position()));
    pros::lcd::set_text(3, std::to_string(targetLow-rotLow.get_position()));
    pros::lcd::set_text(4, std::to_string(targetHigh-rotHigh.get_position()));
    master.set_text(0, 0, std::to_string(increment));
    //master.set_text(0, 0, std::to_string(pidHigh.update(targetHigh-rotHigh.get_position()))+" "+std::to_string(rotHigh.get_position()));




}