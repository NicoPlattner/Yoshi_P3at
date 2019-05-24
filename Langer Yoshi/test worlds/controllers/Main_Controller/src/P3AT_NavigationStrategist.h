#pragma once

#include "Abstract_NavigationStrategist.h"
#include "P3AT_RoadmapController.h"
#include "P3AT_CommandHandler.h"

class P3AT_NavigationStrategist : public Abstract_NavigationStrategist {	//see Abstract_NavigationStrategist.h for info on functions
public:
	P3AT_NavigationStrategist(Abstract_RoadmapController *rc, Abstract_CommandHandler *ch);
	void mcDone(double rotation); 
	void mcDone(double rotation, WayPoint intermediate); 
	void causeMotion(); 	
};
