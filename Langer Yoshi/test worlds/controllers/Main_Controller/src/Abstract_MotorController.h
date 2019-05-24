#pragma once

#include "Command.h"
#include "Abstract_Motors.h"

#define M_PI 3.14159265358979323846  /* pi */

class Abstract_CommandHandler;

class Abstract_MotorController {
public:
	Abstract_MotorController() {};
	virtual void doCommand(Command cmd) = 0;
	virtual void stop(void) = 0;
	virtual Command getIntermediate(void) = 0;
	virtual void check() = 0;
	virtual void addCommandHandler(Abstract_CommandHandler *ch) = 0;
private:
	virtual void rotate(double degrees) = 0;
	virtual void drive(double metres) = 0;
	virtual double calculateDistance() = 0;	//TODO: insert parameters -> wie weit ist er wirklich gefahren?
};