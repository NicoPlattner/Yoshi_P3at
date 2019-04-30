#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <webots/lidar.h>
#include <webots/motor.h>
#include <webots/robot.h>

#define TIME_STEP 32
#define MAX_SPEED 6.4
#define CRUISING_SPEED 5.0
#define BACK_SLOWDOWN 0.9

int main(int argc, char **argv)
{
	wb_robot_init();

	// get devices
	WbDeviceTag front_left_wheel = wb_robot_get_device("front left wheel");
	WbDeviceTag front_right_wheel = wb_robot_get_device("front right wheel");
	WbDeviceTag back_left_wheel = wb_robot_get_device("back left wheel");
	WbDeviceTag back_right_wheel = wb_robot_get_device("back right wheel");

	// init motors
	wb_motor_set_position(front_left_wheel, INFINITY);
	wb_motor_set_position(front_right_wheel, INFINITY);
	wb_motor_set_position(back_left_wheel, INFINITY);
	wb_motor_set_position(back_right_wheel, INFINITY);

	// init speed for each wheel
	double back_left_speed = 1.0, back_right_speed = 1.0;
	double front_left_speed = 1.0, front_right_speed = 1.0;
	wb_motor_set_velocity(front_left_wheel, front_left_speed);
	wb_motor_set_velocity(front_right_wheel, front_right_speed);
	wb_motor_set_velocity(back_left_wheel, back_left_speed);
	wb_motor_set_velocity(back_right_wheel, back_right_speed);

	// init dynamic variables
	double speed_factor = 1.0;
	
	// control loop
	while (wb_robot_step(TIME_STEP) != -1) {

			back_left_speed = CRUISING_SPEED;
			back_right_speed = CRUISING_SPEED;
			front_left_speed = CRUISING_SPEED;
			front_right_speed = CRUISING_SPEED;


		// set actuators
		wb_motor_set_velocity(front_left_wheel, front_left_speed);
		wb_motor_set_velocity(front_right_wheel, front_right_speed);
		wb_motor_set_velocity(back_left_wheel, back_left_speed);
		wb_motor_set_velocity(back_right_wheel, back_right_speed);
	}
	
	wb_robot_cleanup();

	return 0;
}
