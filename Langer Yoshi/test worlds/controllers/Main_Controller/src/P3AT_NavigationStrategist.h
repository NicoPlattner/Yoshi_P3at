#include "Abstract_NavigationStrategist.h"
#include "P3AT_RoadmapController.h"
#include "P3AT_CommandHandler.h"

#ifndef P3AT_NAVIGATION_STRATEGIST_H
#define P3AT_NAVIGATION_STRATEGIST_H

class P3AT_NavigationStrategist : public Abstract_NavigationStrategist {
public:
	P3AT_NavigationStrategist(P3AT_RoadmapController *rc, P3AT_CommandHandler *ch);
	void mcDone(double rotation); //called when motor controller is done with last command; updates position from roadmap; calls causeMotion again
	void mcDone(double rotation, WayPoint intermediate); //called if last command was interruted; updates position with "coord"
	void causeMotion(); //gets next destination from roadmap and calls commandMotor; also called initially to start navigation
private:
	P3AT_RoadmapController *roadmapController;
	P3AT_CommandHandler *commandHandler;
	double currentRotation = 0;
	WayPoint currentPosition;
};

#endif