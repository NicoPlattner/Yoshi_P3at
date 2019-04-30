#include "Command.h"
#include "Abstract_Motors.h"

#ifndef ABSTRACT_MOTOR_CONTROLLER_H
#define ABSTRACT_MOTOR_CONTROLLER_H

class Abstract_MotorController {
public:
	Abstract_MotorController(Motors motors);
	virtual void doCommand(Command cmd);
	virtual void stop(void);
	virtual Command getIntermediate(void);
private:
	virtual void rotate(); //TODO: insert parameters
	virtual void drive();	//TODO: insert parameters
	virtual float calculateDistance();	//TODO: insert parameters -> wie weit ist er wirklich gefahren?
};

#endif