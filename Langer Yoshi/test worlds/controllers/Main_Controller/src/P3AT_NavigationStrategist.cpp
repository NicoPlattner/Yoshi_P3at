#include "P3AT_NavigationStrategist.h"
#include "Log.h"

P3AT_NavigationStrategist::P3AT_NavigationStrategist(Abstract_RoadmapController *rc, Abstract_CommandHandler *ch) 
	: Abstract_NavigationStrategist::Abstract_NavigationStrategist(rc, ch){
	this->roadmapController = rc;
	this->commandHandler = ch;
	this->commandHandler->addNavigationStrategist(this);
	this->currentPosition.x = 0;
	this->currentPosition.y = 0;
}

void P3AT_NavigationStrategist::mcDone(double rotation) {
	if (noOldCommand == true) {
		noOldCommand = false;
	}
	else {
		WayPoint newPos = roadmapController->getCoord();
		roadmapController->delCoord();

		currentRotation += rotation;
		currentPosition = newPos;
	}
	
	causeMotion();
}

void P3AT_NavigationStrategist::mcDone(double rotation, WayPoint intermediate) {
	//TODO
}

void P3AT_NavigationStrategist::causeMotion() {
	WayPoint nextWP = roadmapController->getCoord();
	if (nextWP.isEmpty) {
		noOldCommand = true;
	}
	commandHandler->commandMotor(currentRotation, currentPosition, nextWP);
}
