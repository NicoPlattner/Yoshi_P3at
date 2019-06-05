#pragma once

#include "Abstract_NavigationStrategist.h"
#include "P3AT_RoadmapController.h"
#include "P3AT_CommandHandler.h"

class P3AT_NavigationStrategist : public Abstract_NavigationStrategist {	//see Abstract_NavigationStrategist.h for more information
public:
	P3AT_NavigationStrategist(Abstract_RoadmapController *rc, Abstract_CommandHandler *ch);
	void mcDone(double rotation); 
	void mcDone(double rotation, double percentDone);
	void causeMotion(); 	
	void stopMotors();
	void updateWorldmap(double *sensorData);
protected:
	double currentRotation = 0;	//degrees of rotation relative to starting rotation
	WayPoint currentPosition;	//position relative to starting position (in meters)
	bool noOldWayPoint = true; //is set to true if no command has been fetched yet, or if the roadmap was empty during last fetch 
};
