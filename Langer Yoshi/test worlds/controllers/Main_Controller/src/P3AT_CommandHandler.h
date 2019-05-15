#pragma once

#include "Abstract_CommandHandler.h"


class P3AT_MOTOR_CONTROLLER;
class P3AT_NavigationStrategist;

class P3AT_CommandHandler : public Abstract_CommandHandler {
public:
	P3AT_CommandHandler(P3AT_MOTOR_CONTROLLER *MC);
	void commandMotor(double currentRotation, WayPoint origin, WayPoint destination);
	void stop(void);
	WayPoint getIntermediatePos();
	void mcDone(double rotation);
	void addNavigationStrategist(P3AT_NavigationStrategist *ns);
private:
	void startCommand(Command c);	//CmdHandler hällt MC Objekt schon und ruft MC.doCommand() auf
	Command createCommand(double rotation, double distance);
	double getVecDegree(double vecX, double vecY);
	P3AT_MOTOR_CONTROLLER *motorController;
	P3AT_NavigationStrategist *navigationStrategist;
};

