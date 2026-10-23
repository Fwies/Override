#include "main.h"


/*pros::Motor lift1 ((int)-11, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor lift2 ((int)5, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor lift3 ((int)5, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);*/
pros::MotorGroup lift({14,23,23});
pros::adi::Pneumatics clamp({3, 'a'}, false);
//pros::adi::Pneumatics tilt('b', false);
pros::adi::DigitalIn limit('B');

liftPID pidLow(6,0,24,0); // pid parameters
liftPID pidHigh(1,0,0,0);
bool resetting = true;
// limits all in centidegrees
double homeHigh = 000;
double homeLow=-1000;
double limitHigh =69500; //
double limitLow = 12375; //
double targetHigh = homeHigh;
double targetLow = homeLow;
int increment = 0; // variable to keep track of time for driver macros
int resetCounter = 0;

void liftLoop(){
    lift.set_brake_mode_all(MOTOR_BRAKE_HOLD);
if(limit.get_value()==1){
    lift.tare_position_all();
}
//lift.move_absolute(4,600);
if(master.get_digital(DIGITAL_UP)){
    lift.move_velocity(12000);
}
if(master.get_digital(DIGITAL_DOWN)){
    lift.move_velocity(-12000);
}
    
}
void liftThreadLoop(void* param){
    while(true){
    liftLoop();
    pros::delay(10);
    }
}