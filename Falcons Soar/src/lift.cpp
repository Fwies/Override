#include "main.h"

//1 is rotational
//2 is top rotational
pros::Rotation rotLow(1);
pros::Rotation rotHigh(2);
pros::Motor liftLow ((int)-11, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor liftHigh ((int)5, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);

pros::adi::Pneumatics clamp('a', false);
pros::adi::Pneumatics tilt('b', false);

liftPID pidLow(6,0,24,0);
liftPID pidHigh(1,0,0,0);


double bottomHigh = 22000;
double bottomLow=20000;
double topHigh =-47800;
double topLow = 34800;
double targetHigh = bottomHigh;
double targetLow = bottomLow;
int increment = 0;
/*tilt.toggle();
        targetHigh=0;*/
void liftLoop(){
    if(increment!=0){
        increment++;
    }
    if(increment==5){
        targetHigh=10000;
    }
    if(increment==20){
        tilt.toggle();
    }
    if(master.get_digital_new_press(DIGITAL_L1)){
        clamp.toggle();
        increment=1;
        
    }
    
    if(master.get_digital_new_press(DIGITAL_L2)){
        targetHigh=topHigh;
        targetLow=topLow;
    }
    liftLow.set_brake_mode(MOTOR_BRAKE_HOLD);
    liftHigh.set_brake_mode(MOTOR_BRAKE_HOLD);
    if(master.get_digital(DIGITAL_UP)){
        targetHigh-=800;
        if(targetHigh<topHigh){
            targetHigh=topHigh;
        }
    }
    else if(master.get_digital(DIGITAL_DOWN)){
        targetHigh+=800;
        if(targetHigh>bottomHigh){
            targetHigh=bottomHigh;
        }
    }
    else{
        //liftHigh.move_velocity(0);
    }
    if(master.get_digital(DIGITAL_RIGHT)){
        targetLow+=200;
        if(targetLow>topLow){
            targetLow=topLow;
        }
    }
    else if(master.get_digital(DIGITAL_LEFT)){
        targetLow-=200;
        if(targetLow<bottomLow){
            targetLow=bottomLow;
        }
    }
    else{
        //liftLow.move_velocity(0);
    }
    liftLow.move_voltage(2000+pidLow.update(targetLow-rotLow.get_position()));
    liftHigh.move_voltage(-pidHigh.update(targetHigh-rotHigh.get_position()));
   
    //master.set_text(0, 0, std::to_string(pidLow.update(targetLow-rotLow.get_position()))+" "+std::to_string(rotLow.get_position()));
    master.set_text(0, 0, std::to_string(pidHigh.update(targetHigh-rotHigh.get_position()))+" "+std::to_string(rotHigh.get_position()));




}