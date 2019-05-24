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
	virtual void mcDone(double rotation) = 0;		//calls mcDone() in navigation strategist
	virtual void addNavigationStrategist(Abstract_NavigationStrategist *ns) = 0;	//adds pointer to NS to CH in constructor of NS
protected:
	virtual Command createCommand(double rotation, double distance) = 0;		//adds the calculated rotation and distance to a new command and returns it
	virtual double getVecDegree(double vecX, double vecY) = 0;		//returns degrees of angle between the vector and y-axis
	Abstract_MotorController *motorController;
	Abstract_NavigationStrategist *navigationStrategist;
};


