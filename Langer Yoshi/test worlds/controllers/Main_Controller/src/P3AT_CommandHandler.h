#pragma once

#include "Abstract_CommandHandler.h"

class P3AT_MotorController;
class P3AT_NavigationStrategist;

class P3AT_CommandHandler : public Abstract_CommandHandler {	//see Abstract_CommandHandler.h for info on functions
public:
	P3AT_CommandHandler(Abstract_MotorController *MC);
	void commandMotor(double currentRotation, WayPoint position, WayPoint destination);
	void stop(void);
	WayPoint getIntermediatePos();
	void mcDone(double rotation);
	void addNavigationStrategist(Abstract_NavigationStrategist *ns);
protected:
	Command createCommand(double rotation, double distance);
	double getVecDegree(double vecX, double vecY);
};

