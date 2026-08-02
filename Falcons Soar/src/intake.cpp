#include "main.h"

pros::Motor I1 ((int)-20, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor I2 ((int)21, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);

void intake(){
    I1.move_velocity(600); // move both motors forwards full speed
    I2.move_velocity(600);
}
void outtake(){
    I1.move_velocity(-600); // move both motors backwards full speed
    I2.move_velocity(-600);
}
void stoptake(){
    I1.move_velocity(0); // stop moving motors
    I2.move_velocity(0);
}

void intakeLoop(){
    if(master.get_digital(DIGITAL_R1)){ // intake both if hold R1
        intake();
    }
    else if(master.get_digital(DIGITAL_R2)){// outtake both if holding r2
        outtake();
    }
    else{ // dont move if no input
        stoptake();
    }

}