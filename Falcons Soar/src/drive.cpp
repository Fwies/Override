#include "main.h"

pros::Motor L1 ((int)-19, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor L2 ((int)-16, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor L3 ((int)13, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor R1 ((int)17, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor R2 ((int)18, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor R3 ((int)-12, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::MotorGroup leftDrive({13,-16,-19});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup rightDrive({-12,18,17});


double input = 0;
double speed = 1;

void driveLoop(){
   //tank drive code
    input = master.get_analog(ANALOG_LEFT_Y)*speed;
	if(input>0){
		input=(input*0.46456692913)+68;
	}
    if(input<0){
		input=(input*0.46456692913)-68;
	}
	leftDrive.move_voltage(((input*input*input)*0.00585281132));
	input = master.get_analog(ANALOG_RIGHT_Y)*speed;
	if(input>0){
		input=(input*0.46456692913)+68;
	}
	if(input<0){
		input=(input*0.46456692913)-68;
    }
	rightDrive.move_voltage(((input*input*input)*0.00585281132));    
}

lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              12.5, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 4" omnis
                              450, // dri.vetrain rpm is 360
                              0 // horizontal drift is 2 (for now)
);
// imu
pros::Imu imu(4);
// horizontal tracking wheel encoder
//pros::Rotation horizontal_encoder(20);
pros::Rotation vertical_encoder(14);

// horizontal tracking wheel
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, 0);

// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr,//&horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);
// lateral PID controller
lemlib::ControllerSettings lateral_controller(6, // proportional gain (kP)5
                                              0, // integral gain (kI)
                                              26, // derivative gain (kD)15
                                              0, // anti windup
                                               1 , //1 small error range, in inches
                                              70, //70 small error range timeout, in milliseconds
                                              3, //3 large error range, in inches
                                              500, //500 large error range timeout, in milliseconds
                                              0 //20 maximum acceleration (slew)
);
// angular PID controller
lemlib::ControllerSettings angular_controller(6, // proportional gain (kP)5
                                              0, // integral gain (kI)
                                              42, // derivative gain (kD)35
                                              0, // anti windup
                                              2,//2, // small error range, in degrees
                                              50, //50 small error range timeout, in milliseconds
                                              3,//3, // large error range, in degrees
                                              500,//500, // large error range timeout, in milliseconds
                                              0//0 // maximum acceleration (slew)
);
// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);