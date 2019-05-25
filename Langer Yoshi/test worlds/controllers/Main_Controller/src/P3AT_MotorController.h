#pragma once

#include "Abstract_MotorController.h"
#include "P3AT_Motors.h"
#include <webots/robot.h>
#include <math.h>

class Abstract_CommandHandler;	//CH

class P3AT_MotorController : public Abstract_MotorController {	//see Abstract_MotorController.h for more information
public:
	P3AT_MotorController();
	void doCommand(Command cmd);
	void stop(void);
	WayPoint getIntermediate(void);
	void check();
	void addCommandHandler(Abstract_CommandHandler *ch);
private:
	void rotate(double degrees);	//calls rotate in Motors
	void drive(double metres);		//calls drive in Motors
	double calculateDistance();		//TODO ???
	void fetchNextCommand();		//requests new command from CH

	Command currentCommand;
	Abstract_CommandHandler *commandHandler;
	bool _isStopped = false;	//is true if the robot had to stop prematurely and causes alternate navigation strategy
	bool _isTurning = true;		//is true if the rotate part of the current command is not yet done
};