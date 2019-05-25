#include "stdafx.h"

#include "P3AT_SensorController.h"
#include "Log.h"

#define MAX_SENSOR_NUMBER 16

static WbDeviceTag sensors[MAX_SENSOR_NUMBER];

P3AT_SensorController::P3AT_SensorController(Abstract_NavigationStrategist *ns) : Abstract_SensorController::Abstract_SensorController(ns) {
	this->navigationStrategist = ns;

	int time_step = wb_robot_get_basic_time_step();
	char sensor_name[5] = "";
	int i;

	for (i = 0; i < MAX_SENSOR_NUMBER; ++i) {
		sensors[i] = wb_robot_get_device(sensor_name);
		wb_distance_sensor_enable(sensors[i], time_step);
	}
}

void P3AT_SensorController::checkSenses() 
{	
	Log::writeLog(std::to_string(wb_distance_sensor_get_value(sensors[4])));
}