#include "main.h"

pros::Motor L1 ((int)-3, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor L2 ((int)-2, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor L3 ((int)-1, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor R1 ((int)6, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor R2 ((int)5, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::Motor R3 ((int)4, pros::v5::MotorGears::blue, pros::MotorUnits::rotations);
pros::MotorGroup leftDrive({-3,-2,-1});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup rightDrive({4,5,6});


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
                              10.5, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              450, // dri.vetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);
// imu
pros::Imu imu(11);
// horizontal tracking wheel encoder
//pros::Rotation horizontal_encoder(20);
pros::Rotation vertical_encoder(18);
pros::Rotation horizontal_encoder(17);
// horizontal tracking wheel
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, 1.9921875, -0.5);
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.5625);
// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel,//&horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);
// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)10
                                              0, // integral gain (kI)
                                              65, // derivative gain (kD)54.5
                                              0, // anti windup
                                               1 , //1 small error range, in inches
                                              70, //100 small error range timeout, in milliseconds
                                              3, //3 large error range, in inches
                                              500, //500 large error range timeout, in milliseconds
                                              0 //20 maximum acceleration (slew)
);
// angular PID controller
lemlib::ControllerSettings angular_controller(6, // proportional gain (kP)6
                                              0, // integral gain (kI)
                                              46, // derivative gain (kD)46
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