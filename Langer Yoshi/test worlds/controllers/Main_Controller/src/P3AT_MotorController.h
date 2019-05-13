#include "Abstract_MotorController.h"
#include "P3AT_Motors.h"
#include <webots/robot.h>
#include <math.h>


#ifndef P3AT_MOTOR_CONTROLLER_H
#define P3AT_MOTOR_CONTROLLER_H
#define M_PI 3.14159265358979323846  /* pi */

class P3AT_MOTOR_CONTROLLER : public Abstract_MotorController {
public:
	P3AT_MOTOR_CONTROLLER();
	void doCommand(Command cmd);
	void stop(void);
	Command getIntermediate(void);
private:
	P3AT_Motors *Motors;
	void rotate(double degrees);
	void drive(double metres);
	float calculateDistance();
};

#endif