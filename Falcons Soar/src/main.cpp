#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(0, "Soar");

	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
//pros::adi::Potentiometer pot('c');
void competition_initialize() {
	chassis.calibrate();
	
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
//if (pot.get_value()<2048){

//	}
//	else{
	//rightSide();
//	}

	
	
}
/*
pros::delay(100);
	master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,48,2000,{},false);
		master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,0,2000,{.forwards=false},false);

	chassis.turnToHeading(90,1000,{},false);
		chassis.turnToHeading(270,1000,{},false);
		chassis.turnToHeading(0,1000,{},false);
*/

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	//clamp.extend();
	
	 // Creates a motor group with forwards port 5 and reversed ports 4 & 6

	
	while (true) {
		//pros::lcd::set_text(7, std::to_string(pot.get_value()));
		//run all the subsystem loops
		driveLoop();
		intakeLoop();
		liftLoop();
		pros::delay(10);                               // Run for 10 ms then update
	}
}