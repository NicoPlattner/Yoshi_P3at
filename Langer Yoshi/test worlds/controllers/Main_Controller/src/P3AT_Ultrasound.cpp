#include "stdafx.h"
#include "P3AT_Ultrasound.h"
#include "Log.h"



P3AT_Ultrasound::P3AT_Ultrasound() {
	int time_step = wb_robot_get_basic_time_step();
	char sensor_name[5] = "";
	int i;

	for (i = 0; i < MAX_SENSOR_NUMBER; ++i) {
		sprintf_s(sensor_name, "so%d", i);
		sensors[i] = wb_robot_get_device(sensor_name);
		wb_distance_sensor_enable(sensors[i], time_step);
	}
}

double P3AT_Ultrasound::getData() {
	return wb_distance_sensor_get_value(sensors[4]);
}