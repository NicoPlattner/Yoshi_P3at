#pragma once

#include "Command.h"
#include "WayPoint.h"

#define PI 3.14159265358979323846

class Abstract_NavigationStrategist;	//NS
class Abstract_MotorController;			//MC

//This class receives instructions and/or destination waypoints from the NS and turns them into commands
//for the MC. It also forwards requests for new commands by MC to the NS

class Abstract_CommandHandler {			//CH
public:
	Abstract_CommandHandler(Abstract_MotorController *mc) {};
	virtual void commandMotor(double currentRotation, WayPoint position, WayPoint destination) = 0;	//creates a command for the motor controller
	virtual void stop(void) = 0;				//calls stop() in motor controller
	virtual WayPoint getIntermediatePos() = 0;	//get new current position during execution of command
	virtual void mcDone(double rotation) = 0;		//calls mcDone(rotation) in navigation strategist
	virtual void mcDone(double rotation, double percentDone) = 0;	//calls mcDone(rotation, percentDone) in navigation strategist
	virtual void addNavigationStrategist(Abstract_NavigationStrategist *ns) = 0;	//adds pointer to NS to CH in constructor of NS
protected:
	Abstract_MotorController *motorController;
	Abstract_NavigationStrategist *navigationStrategist;
};


