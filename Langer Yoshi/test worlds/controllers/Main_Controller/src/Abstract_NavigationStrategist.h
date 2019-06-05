#pragma once

#include "WayPoint.h"

class Abstract_RoadmapController;	//RC
class Abstract_CommandHandler;		//CH
class Abstract_WorldmapController;  //WC

/*some definitions:
*starting position is x = 0, y = 0
*starting rotation (looking "north") is 0
*rotation is always a value within [0; 360[
*/

//This class acts as a central intersection between different parts of the robot and is responsible for forwarding
//information. Once a navigation strategy is implemented it will also be realized by the NS

class Abstract_NavigationStrategist {  //NS
public:
	Abstract_NavigationStrategist(Abstract_RoadmapController *rc, Abstract_CommandHandler *ch) {};
	virtual void mcDone(double rotation) = 0; //called when motor controller is done with last command; updates position from roadmap; calls causeMotion again
	virtual void mcDone(double rotation, double percentDone) = 0; //called if last command was interruted; updates position with "percentDone"
	virtual void causeMotion() = 0; //gets next destination from roadmap and calls commandMotor in CH
	virtual void stopMotors() = 0;	//stops movement, if sensors indicate an obstacle ahead
	virtual void updateWorldmap(double *sensorData) = 0;	//forwards data from SC to WC
protected:
	Abstract_RoadmapController * roadmapController;
	Abstract_CommandHandler *commandHandler;
};

