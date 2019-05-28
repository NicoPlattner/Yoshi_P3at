#include "stdafx.h"

#include "P3AT_Bumper.h"

P3AT_Bumper::P3AT_Bumper() {
	bumper1 = wb_robot_get_device("bump1");
	wb_touch_sensor_enable(bumper1, 32);
}

bool P3AT_Bumper::getData() {
	return wb_touch_sensor_get_value(bumper1);
}