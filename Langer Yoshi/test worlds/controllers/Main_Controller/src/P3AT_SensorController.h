#pragma once
#include "P3AT_Bumper.h"
#include "P3AT_Ultrasound.h"
#include "Abstract_SensorController.h"

class P3AT_SensorController : public Abstract_SensorController {	//see Abstract_SensorController.h for more information
public:
	P3AT_SensorController(Abstract_NavigationStrategist *ns);
	void checkSenses();
private:
	P3AT_Bumper *bumper;
	P3AT_Ultrasound *ultrasound;
};