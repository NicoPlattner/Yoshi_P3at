#include <tuple>
#include "Command.h"
#include "Abstract_MotorController.h"
#include "WayPoint.h"

#ifndef ABSTRACT_COMMAND_HANDLER_H
#define ABSTRACT_COMMAND_HANDLER_H

#define PI 3.14159265

class Abstract_NavigationStrategist;
class Abstract_MotorController;

class Abstract_CommandHandler {
public:
	Abstract_CommandHandler(Abstract_MotorController *mc) {};
	virtual void commandMotor(double currentRotation, WayPoint origin, WayPoint destination) = 0;	//gets current rotation, current position and destination and creates an appropriate command for the motor controller
	virtual void stop(void) = 0;				//flush command in MC
	virtual WayPoint getIntermediatePos() = 0;	//get current pos during execution of command
	virtual void mcDone(double rotation) = 0;		//forward to navigation strategist
	virtual void addNavigationStrategist(Abstract_NavigationStrategist *ns) = 0;
protected:
	virtual void startCommand(Command c) = 0;	//CmdHandler hällt MC Objekt schon und ruft MC.doCommand() auf
	virtual Command createCommand(double rotation, double distance) = 0;		//use current pos and destination to create command
	virtual double getVecDegree(double vecX, double vecY) = 0;
	Abstract_MotorController *motorController;
	Abstract_NavigationStrategist *navigationStrategist;
};


#endif


