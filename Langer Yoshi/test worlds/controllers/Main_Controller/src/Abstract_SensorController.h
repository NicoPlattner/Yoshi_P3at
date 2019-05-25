#pragma once

#include "Abstract_NavigationStrategist.h"

class Abstract_SensorController {
public:
	Abstract_SensorController(Abstract_NavigationStrategist *ns) { };
	virtual void checkSenses() = 0;
protected:
	Abstract_NavigationStrategist * navigationStrategist;
};
