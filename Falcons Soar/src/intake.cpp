#include "main.h"

pros::Motor I1 ((int)-20, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor I2 ((int)21, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);

void intakeLoop(){
    if(master.get_digital(DIGITAL_R1)){
        I1.move_velocity(600);
        I2.move_velocity(600);
    }
    else if(master.get_digital(DIGITAL_R2)){
        I1.move_velocity(-600);
        I2.move_velocity(-600);
    }
    else{
        I1.move_velocity(0);
        I2.move_velocity(0);
    }

}