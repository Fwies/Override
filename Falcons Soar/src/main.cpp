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
pros::Task liftThread = pros::Task(liftThreadLoop);
		intake();
chassis.moveToPoint(0,-10,300,{.forwards=false},false);
	chassis.moveToPoint(0,10,500,{.maxSpeed=80,.minSpeed=80},false);
	chassis.moveToPoint(0,-10,300,{.forwards=false},false);
		
	chassis.moveToPoint(0,10,500,{.maxSpeed=80,.minSpeed=80},false);
	chassis.moveToPoint(0,-5,1000,{.forwards=false},false);
	clampLiftTilt();
	
	
	chassis.moveToPoint(-2,-20,1000,{.forwards=false},false);
	chassis.turnToPoint(-14.5,-20,1000,{.forwards=false},false);
	chassis.moveToPoint(-14.5,-20,1000,{.forwards=false},false);
	targetLow=targetLow-4000;
	targetHigh=targetHigh-10000;
	pros::delay(300);
	clamp.extend();
	pros::delay(200);
	//targetHigh=targetHigh-5000;
	targetLow=targetLow+4000;
	targetHigh=targetHigh+10000;
	pros::delay(400);
	chassis.moveToPoint(-5,-4,1000,{},false);
	goHome();
	stoptake();
	chassis.turnToHeading(275,1000,{},false);
	
	chassis.moveToPoint(-60,-4,3000,{.minSpeed=10,.earlyExitRange=10},false);
	
	chassis.moveToPoint(-71,-10,1000,{},false);
	chassis.turnToPoint(-71,4,1000,{},false);
	intake();
	chassis.moveToPoint(-71,4,600,{},false);
	pros::delay(3000);
	chassis.moveToPoint(-68,-20,2000,{.forwards=false},false);
	clampLiftTilt();
	chassis.turnToPoint(-31,-20,1000,{.forwards=false},false);
	targetLow=targetLow+4000;
	targetHigh=targetHigh+20000;
	chassis.moveToPoint(-31,-20,3000,{.forwards=false},false);
	targetLow=targetLow-4000;
	targetHigh=targetHigh-20000;
	pros::delay(300);
	clamp.extend();
	targetLow=targetLow+2000;
	targetHigh=targetHigh+10000;
	pros::delay(400);

	chassis.moveToPoint(-71,-10,3000,{},false);
	goHome();
	// go to matchloader rond 2
	chassis.turnToPoint(-71,4,1000,{},false);
	intake();
	chassis.moveToPoint(-71,4,1000,{},false);
	pros::delay(3000);
	chassis.moveToPoint(-68,-20,2000,{.forwards=false},false);
	clampLiftTilt();
	chassis.turnToPoint(-31,-20,1000,{.forwards=false},false);
	targetLow=targetLow+4000;
	targetHigh=targetHigh+20000;
	chassis.moveToPoint(-31,-20,3000,{.forwards=false},false);

	//place 2nd preload
	targetLow=targetLow-4000;
	targetHigh=targetHigh-20000;
	pros::delay(300);
	clamp.extend();
	targetLow=targetLow+2000;
	targetHigh=targetHigh+10000;
	pros::delay(400);

	chassis.moveToPoint(-71,-10,3000,{},false);
	goHome();



	chassis.turnToPoint(-71,4,1000,{},false);
	intake();
	chassis.moveToPoint(-71,4,1000,{},false);
	pros::delay(3000);
	chassis.moveToPoint(-68,-20,2000,{.forwards=false},false);
	clampLiftTilt();
	chassis.turnToPoint(-31,-20,1000,{.forwards=false},false);
	targetLow=targetLow+6000;
	targetHigh=targetHigh+30000;
	chassis.moveToPoint(-31,-20,3000,{.forwards=false},false);

	targetLow=targetLow-4000;
	targetHigh=targetHigh-20000;
	pros::delay(300);
	clamp.extend();
	targetLow=targetLow+2000;
	targetHigh=targetHigh+10000;
	pros::delay(400);
	





		


	
	
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
	clamp.extend();
	
	 // Creates a motor group with forwards port 5 and reversed ports 4 & 6

	
	while (true) {
		
		//run all the subsystem loops
		driveLoop();
		intakeLoop();
		liftLoop();
		pros::delay(10);                               // Run for 10 ms then update
	}
}