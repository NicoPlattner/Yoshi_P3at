#pragma once
#include "P3AT_Bumper.h"
#include "P3AT_Ultrasound.h"
#include "Abstract_SensorController.h"

class P3AT_SensorController : Abstract_SensorController {
public:
	P3AT_SensorController(Abstract_NavigationStrategist *ns);
	void checkSenses();
private:
	P3AT_Bumper *bumper;
	P3AT_Ultrasound *ultrasound;
};