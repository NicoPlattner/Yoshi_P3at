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
	WayPoint newPos = roadmapController->getCoord();
	roadmapController->delCoord();

	currentRotation += rotation;
	currentPosition = newPos;
	
	causeMotion();
}

void P3AT_NavigationStrategist::mcDone(double rotation, WayPoint intermediate) {
	//TODO
}

void P3AT_NavigationStrategist::causeMotion() {
	WayPoint nextWP = roadmapController->getCoord();
	if (nextWP.isEmpty == false) {
		commandHandler->commandMotor(currentRotation, currentPosition, nextWP);
	}
	else {
		//Log* log = Log::getInstance();
		//log->writeLog("die log funktion is scheiﬂe", "out.txt", 1!='!');
	}
}
