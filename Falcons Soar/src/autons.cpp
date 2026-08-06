#include "main.h"
void highScoring(){
	pros::Task liftThread = pros::Task(liftThreadLoop);
clamp.retract();
/*master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,48,2000,{},false);
		master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,0,2000,{.forwards=false},false);*/
		intake();
		chassis.moveToPoint(0,-10,300,{.forwards=false},false);
		chassis.moveToPoint(0,10,500,{.maxSpeed=80,.minSpeed=80},false);
		chassis.moveToPoint(0,-10,300,{.forwards=false},false);
		
		chassis.moveToPoint(0,10,500,{.maxSpeed=80,.minSpeed=80},false);
		chassis.moveToPoint(2,-20,2000,{.forwards=false},false);
		clampLiftTilt();
		chassis.turnToPoint(14.5,-20,1000,{.forwards=false},false);
		chassis.moveToPoint(14.5,-20,1000,{.forwards=false},false);
		targetLow=targetLow-2000;
		targetHigh=targetHigh-8000;
		pros::delay(300);
		clamp.extend();
		pros::delay(300);
		targetLow=targetLow+4000;
		targetHigh=targetHigh+18000;
		chassis.moveToPoint(0,-32,1000,{},false);
		chassis.turnToPoint(14,-45.5,1000,{.forwards=false},false);
		chassis.moveToPoint(14,-45.5,1000,{.forwards=false},false);
		chassis.turnToHeading(315,1000,{},false);
		targetLow=targetLow-2500;
		targetHigh=targetHigh-12500;
		pros::delay(600);
		targetLow=targetLow-2000;
		targetHigh=targetHigh-10000;
		pros::delay(500);
		clamp.retract();
		pros::delay(200);
		targetLow=targetLow+4000;
		targetHigh=targetHigh+20000;
		chassis.turnToPoint(21,-24,1000,{.forwards=false},false);
		chassis.moveToPoint(21,-24,1000,{.forwards=false},false);
		targetLow=targetLow-3000;
		targetHigh=targetHigh-15000;
		pros::delay(300);
		clamp.extend();
		pros::delay(100);
		targetLow=targetLow+4000;
		targetHigh=targetHigh+20000;
		pros::delay(300);
		chassis.moveToPoint(40,-35, 1500,{},false);
		targetLow=targetLow-2000;
		targetHigh=targetHigh-10000;
		chassis.turnToPoint(48,-26,1000,{.forwards=false},false);
		chassis.moveToPoint(48,-26,1000,{.forwards=false},false);
		targetLow=targetLow-2000;
		targetHigh=targetHigh-10000;
		pros::delay(400);
		targetLow=targetLow-2000;
		targetHigh=targetHigh-10000;
		
		


        
		
		

		/*targetLow=5000;
		targetHigh=25000;*/
}
void rightSide(){
    pros::Task liftThread = pros::Task(liftThreadLoop);
/*master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,48,2000,{},false);
		master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,0,2000,{.forwards=false},false);*/
		intake();
		chassis.moveToPoint(0,-10,1000,{.forwards=false},false);
		
		
		clampLiftTilt();
		chassis.moveToPoint(-1,-6.5,1000,{},false);
		
		chassis.turnToPoint(-8,-13,1000,{.forwards=false},false);
		
		//pros::delay(500);
		chassis.moveToPoint(-8,-13,2000,{.forwards=false},false);
		//chassis.turnToHeading(315,500,{},false);
		
		clamp.retract();
		targetLow=targetLow-2500;
		targetHigh=targetHigh-12500;
		pros::delay(300);
		clamp.extend();
		pros::delay(200);
		targetLow=targetLow+5000;
		targetHigh=targetHigh+25000;
		
		chassis.moveToPoint(0,-6,1000,{},false);
		chassis.turnToPoint(11,-14,1000,{.forwards=false},false);
		chassis.moveToPoint(11,-14,1000,{.forwards=false},false);
		
		targetLow=targetLow-2500;
		targetHigh=targetHigh-12500;
		pros::delay(200);
		clamp.retract();
		targetHigh=rotHigh.get_position()+12500;
        targetLow=rotLow.get_position()+2500;
		pros::delay(300);
		chassis.moveToPoint(2,-4,1500,{},false);
        goHome();
		chassis.turnToPoint(48,-4,1000,{.forwards=false,.minSpeed=10,.earlyExitRange=3},false);
		chassis.moveToPoint(36,-4,3000,{.forwards=false,.minSpeed=30,.earlyExitRange=3},false);
		chassis.moveToPoint(48,-10,1000,{.forwards=false},false);
		chassis.turnToPoint(48,30,1000,{},false);
		chassis.moveToPoint(48,30,500,{.maxSpeed=81,.minSpeed=80},false);
		chassis.moveToPoint(48,-10,300,{.forwards=false},false);
		chassis.moveToPoint(48,30,500,{.maxSpeed=81,.minSpeed=80},false);
		chassis.moveToPoint(48,-36,2000,{.forwards=false},false);
		chassis.turnToPoint(30,-52,1000,{},false);
		intake();
		chassis.moveToPoint(30,-52,1000,{},false);
		chassis.turnToPoint(78,-27,3000,{.forwards=false},false);
		chassis.moveToPoint(78,-27,3000,{.forwards=false},false);
		clampLiftTilt();
		leftDrive.move_voltage(-3000);
		rightDrive.move_voltage(-3000);
		pros::delay(650);
		targetLow=targetLow-2000;
		targetHigh=targetHigh-10000;
		pros::delay(200);
		clamp.retract();
		
		

		/*targetLow=5000;
		targetHigh=25000;*/
}
void leftSide(){
    pros::Task liftThread = pros::Task(liftThreadLoop);
/*master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,48,2000,{},false);
		master.set_text(0, 0, std::to_string(chassis.getPose().theta));
		chassis.moveToPoint(0,0,2000,{.forwards=false},false);*/
		intake();
		chassis.moveToPoint(0,-10,1000,{.forwards=false},false);
		
		
		clampLiftTilt();
		chassis.moveToPoint(1,-6.5,1000,{},false);
		
		chassis.turnToPoint(7.5,-14,1000,{.forwards=false},false);
		
		//pros::delay(500);
		chassis.moveToPoint(7.5,-14,2000,{.forwards=false},false);
		//chassis.turnToHeading(315,500,{},false);
		
		clamp.retract();
		targetLow=targetLow-2600;
		targetHigh=targetHigh-13000;
		pros::delay(400);
		clamp.extend();
		pros::delay(200);
		targetLow=targetLow+5000;
		targetHigh=targetHigh+25000;
		
		chassis.moveToPoint(0,-6,1000,{},false);
		chassis.turnToPoint(-11,-13,1000,{.forwards=false},false);
		chassis.moveToPoint(-11,-13,1000,{.forwards=false},false);
		
		targetLow=targetLow-2500;
		targetHigh=targetHigh-12500;
		pros::delay(200);
		clamp.retract();
		targetHigh=rotHigh.get_position()+12500;
        targetLow=rotLow.get_position()+2500;
		pros::delay(300);
		chassis.moveToPoint(-2,-6,1500,{},false);
        goHome();
		chassis.turnToPoint(-48,-6,1000,{.forwards=false,.minSpeed=10,.earlyExitRange=3},false);
		chassis.moveToPoint(-36,-6,3000,{.forwards=false,.minSpeed=30,.earlyExitRange=3},false);
		chassis.moveToPoint(-48,-10,1000,{.forwards=false},false);
		chassis.turnToPoint(-48,30,1000,{},false);
		chassis.moveToPoint(-48,30,500,{.maxSpeed=81,.minSpeed=80},false);
		chassis.moveToPoint(-48,-10,300,{.forwards=false},false);
		chassis.moveToPoint(-48,30,500,{.maxSpeed=81,.minSpeed=80},false);
		chassis.moveToPoint(-48,-36,2000,{.forwards=false},false);
		chassis.turnToPoint(-30,-52,1000,{},false);
		chassis.moveToPoint(-30,-52,1000,{},false);
		chassis.turnToPoint(-78,-27,3000,{.forwards=false},false);
		chassis.moveToPoint(-78,-27,3000,{.forwards=false},false);
		clampLiftTilt();
		leftDrive.move_voltage(-3000);
		rightDrive.move_voltage(-3000);
		pros::delay(650);
		targetLow=targetLow-2000;
		targetHigh=targetHigh-10000;
		pros::delay(200);
		clamp.retract();
		
		

		/*targetLow=5000;
		targetHigh=25000;*/
}