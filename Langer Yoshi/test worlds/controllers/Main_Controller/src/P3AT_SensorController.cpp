#include "stdafx.h"

#include "P3AT_SensorController.h"
#include "Log.h"

#define MAX_SENSOR_NUMBER 16

static WbDeviceTag sensors[MAX_SENSOR_NUMBER];

P3AT_SensorController::P3AT_SensorController(Abstract_NavigationStrategist *ns) : Abstract_SensorController::Abstract_SensorController(ns) {
	this->navigationStrategist = ns;

	ultrasound = new P3AT_Ultrasound();
	bumper = new P3AT_Bumper();
}

void P3AT_SensorController::checkSenses() 
{
	if (ultrasound->getData() >= 800) {
		navigationStrategist->stopMotors();
	}

	if (bumper->getData()) {
		navigationStrategist->stopMotors();
	}
}