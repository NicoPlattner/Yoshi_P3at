#include "P3AT_SensorController.h"

P3AT_SensorController::P3AT_SensorController(Abstract_NavigationStrategist *ns) : Abstract_SensorController::Abstract_SensorController(ns) {
	this->navigationStrategist = ns;
}

void P3AT_SensorController::checkSenses() {

}