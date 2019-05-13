#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <webots/lidar.h>
#include <webots/motor.h>
#include <webots/robot.h>
#include "src/P3AT_Motors.h"

#define TIME_STEP 32
#define M_PI 3.14159265358979323846  /* pi */

int main(int argc, char **argv)
{
	wb_robot_init();
	// get devices
	WbDeviceTag front_left_wheel = wb_robot_get_device("front left wheel");
	WbDeviceTag front_right_wheel = wb_robot_get_device("front right wheel");
	WbDeviceTag back_left_wheel = wb_robot_get_device("back left wheel");
	WbDeviceTag back_right_wheel = wb_robot_get_device("back right wheel");

	std::vector<WbDeviceTag> motVec;
	motVec.push_back(front_left_wheel);
	motVec.push_back(back_left_wheel);
	motVec.push_back(front_right_wheel);
	motVec.push_back(back_right_wheel);

	float radius_wheel = 0.10;	//Reifenradius ~10cm???
	float rotation_speed = 2*M_PI; //Eine halbe Reifenumdrehung pro Sekunde
	float umfang_wendekreis = 1.8;	//Diagonale Rad zu Rad ~ 70cm -> Kreisumfang mit der Diagonale als Annäherung in Meter

	P3AT_Motors *Motors = new P3AT_Motors(motVec, radius_wheel, rotation_speed, umfang_wendekreis);

	// control loop
	while (wb_robot_step(TIME_STEP) != -1) {
			Motors->rotate(45);	//90 Grad -> Uhrzeigersinn
			//Motors->drive(0.5); //0.5 Meter
	}
	
	wb_robot_cleanup();

	return 0;
}
