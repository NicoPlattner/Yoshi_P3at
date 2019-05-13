#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <webots/lidar.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include "src/P3AT_MotorController.h"
#include "src/Command.h"
#include "src/P3AT_RoadmapController.h"

#define TIME_STEP 32

int main(int argc, char **argv)
{
	wb_robot_init();
	P3AT_MOTOR_CONTROLLER *mc = new P3AT_MOTOR_CONTROLLER();

	P3AT_RoadmapController *rc = new P3AT_RoadmapController();

	// control loop
	while (wb_robot_step(TIME_STEP) != -1) {
		Command drive;
		Command rotate;

		drive.distance = 0.5;
		drive.rotation = 0;

		rotate.distance = 0;
		rotate.rotation = 90;

		//mc.doCommand(drive);
		mc->doCommand(rotate);
	}
	
	wb_robot_cleanup();

	return 0;
}
