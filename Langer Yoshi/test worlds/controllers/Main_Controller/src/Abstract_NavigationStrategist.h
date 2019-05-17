#pragma once

#include<tuple>
#include"WayPoint.h"

class Abstract_RoadmapController;
class Abstract_CommandHandler;

class Abstract_NavigationStrategist
{
public:
	Abstract_NavigationStrategist(Abstract_RoadmapController *rc, Abstract_CommandHandler *ch) {};
	virtual void mcDone(double rotation) = 0; //called when motor controller is done with last command; updates position from roadmap; calls causeMotion again
	virtual void mcDone(double rotation, WayPoint intermediate) = 0; //called if last command was interruted; updates position with "coord"
	virtual void causeMotion() = 0; //gets next destination from roadmap and calls commandMotor; also called initially to start navigation
protected:
	double currentRotation = 0;
	WayPoint currentPosition;
	bool firstComFetch = true;
};

/*some definitions; MOVE SOMEWHERE ELSE!
*starting position is x = 0, y = 0
(should coords be floats rather than int?)
*starting rotation (looking north) is 0
*rotation is always a value within [0; 360[
*/