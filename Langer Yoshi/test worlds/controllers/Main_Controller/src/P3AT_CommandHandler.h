#pragma once

#include "Abstract_CommandHandler.h"

class P3AT_MotorController;
class P3AT_NavigationStrategist;

class P3AT_CommandHandler : public Abstract_CommandHandler {	//see Abstract_CommandHandler.h for more information
public:
	P3AT_CommandHandler(Abstract_MotorController *MC);
	void commandMotor(double currentRotation, WayPoint position, WayPoint destination);
	void stop(void);
	WayPoint getIntermediatePos();
	void mcDone(double rotation);
	void mcDone(double rotation, double percentDone);
	void addNavigationStrategist(Abstract_NavigationStrategist *ns);
protected:
	Command createCommand(double rotation, double distance);	//adds the calculated rotation and distance to a new command and returns it
	double getVecDegree(double vecX, double vecY); //returns degrees of angle between the vector and y-axis
};

