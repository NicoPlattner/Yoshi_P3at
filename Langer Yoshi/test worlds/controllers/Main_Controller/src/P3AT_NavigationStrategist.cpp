#include "stdafx.h"

#include "P3AT_NavigationStrategist.h"
#include "Log.h"

P3AT_NavigationStrategist::P3AT_NavigationStrategist(Abstract_RoadmapController *rc, Abstract_CommandHandler *ch) 
	: Abstract_NavigationStrategist::Abstract_NavigationStrategist(rc, ch){
	this->roadmapController = rc;
	//add pointer of NS to CH and of CH to NS (2-ways communication)
	this->commandHandler = ch;
	this->commandHandler->addNavigationStrategist(this);
	//set current position to (0, 0)
	this->currentPosition.x = 0;
	this->currentPosition.y = 0;
}

void P3AT_NavigationStrategist::mcDone(double rotation) {
	if (noOldWayPoint == true) {	//if there is no old way point to discard skip the discarding step
		noOldWayPoint = false;
	}
	else {	
		//update position with last destination and then discard it
		WayPoint newPos = roadmapController->getCoord();
		currentPosition = newPos;
		roadmapController->delCoord();

		//update position with parsed value
		currentRotation += rotation;
	}
	
	causeMotion();
}

void P3AT_NavigationStrategist::mcDone(double rotation, double percentDone) {
	//TODO
}

void P3AT_NavigationStrategist::causeMotion() {
	//get next destination
	WayPoint nextWP = roadmapController->getCoord();

	//if there are no destinations left set noOldWayPoint to true
	if (nextWP.isEmpty) {
		noOldWayPoint = true;
	}
	commandHandler->commandMotor(currentRotation, currentPosition, nextWP);
}

void P3AT_NavigationStrategist::stopMotors() {
	commandHandler->stop();
}

void P3AT_NavigationStrategist::updateWorldmap(double * sensorData) {
	//TODO
}
