#pragma once
#include "Abstract_NavigationStrategist.h"

class Abstract_SensorController {
protected:
	Abstract_NavigationStrategist *navigationStrategist;
public:
	Abstract_SensorController(Abstract_NavigationStrategist *ns) { };
	virtual void checkSenses() = 0;
};
