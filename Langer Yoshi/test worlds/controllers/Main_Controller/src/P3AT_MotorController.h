#pragma once

#include "Abstract_MotorController.h"
#include "P3AT_Motors.h"
#include <webots/robot.h>
#include <math.h>

#define M_PI 3.14159265358979323846  /* pi */

class P3AT_CommandHandler;

class P3AT_MOTOR_CONTROLLER : public Abstract_MotorController {
public:
	P3AT_MOTOR_CONTROLLER();
	void doCommand(Command cmd);
	void stop(void);
	Command getIntermediate(void);
	void check();
	void addCommandHandler(P3AT_CommandHandler *ch);
private:
	P3AT_Motors *Motors;
	bool _isStopped = false;
	bool _isTurning = true;
	void rotate(double degrees);
	void drive(double metres);
	double calculateDistance();
	void fetchNextCommand();
	Command currentCommand;
	P3AT_CommandHandler *commandHandler;
};