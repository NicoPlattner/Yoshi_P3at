#pragma once

#define MAX_SENSOR_NUMBER 16

class P3AT_Ultrasound {
public:
	P3AT_Ultrasound();
	double getData();
private:
	WbDeviceTag sensors[MAX_SENSOR_NUMBER];
};