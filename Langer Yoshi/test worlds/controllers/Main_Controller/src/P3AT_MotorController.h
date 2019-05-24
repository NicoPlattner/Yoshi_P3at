#pragma once

#include "Abstract_MotorController.h"
#include "P3AT_Motors.h"
#include <webots/robot.h>
#include <math.h>



class Abstract_CommandHandler;

class P3AT_MotorController : public Abstract_MotorController {
public:
	P3AT_MotorController();
	void doCommand(Command cmd);
	void stop(void);
	Command getIntermediate(void);
	void check();
	void addCommandHandler(Abstract_CommandHandler *ch);
private:
	P3AT_Motors *Motors;
	bool _isStopped = false;
	bool _isTurning = true;
	void rotate(double degrees);
	void drive(double metres);
	double calculateDistance();
	void fetchNextCommand();
	Command currentCommand;
	Abstract_CommandHandler *commandHandler;
};