#include "Command.h"
#include "Abstract_Motors.h"

#ifndef ABSTRACT_MOTOR_CONTROLLER_H
#define ABSTRACT_MOTOR_CONTROLLER_H

class Abstract_MotorController {
public:
	Abstract_MotorController() {};
	virtual void doCommand(Command cmd) = 0;
	virtual void stop(void) = 0;
	virtual Command getIntermediate(void) = 0;
	virtual void check() = 0;
private:
	virtual void rotate(double degrees) = 0;
	virtual void drive(double metres) = 0;
	virtual double calculateDistance() = 0;	//TODO: insert parameters -> wie weit ist er wirklich gefahren?
};

#endif