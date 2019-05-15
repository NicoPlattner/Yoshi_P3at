#include "P3AT_CommandHandler.h"
#include "P3AT_MotorController.h"
#include "P3AT_NavigationStrategist.h"
#include <math.h>


P3AT_CommandHandler::P3AT_CommandHandler(P3AT_MOTOR_CONTROLLER *MC) : Abstract_CommandHandler() {
	this->motorController = MC;
	this->motorController->addCommandHandler(this);
};

void P3AT_CommandHandler::commandMotor(double currentRotation, WayPoint origin, WayPoint destination) {
	double distXpart = pow((destination.x - origin.x), 2);
	double distYpart = pow((destination.y - origin.y), 2);
	double distance = sqrt(distXpart + distYpart);

	double angle = getVecDegree(destination.x - origin.x, destination.y - origin.y);
	double rotate = angle - currentRotation;

	if (rotate > 180) {
		rotate -= 360;
	}
	else if (rotate < -180) {
		rotate += 360;
	}

	Command c = createCommand(rotate, distance);
	startCommand(c);

	//TODO call mcDone(angle) in NavigationStrategist
}

void P3AT_CommandHandler::stop(void) {
	//TODO
	motorController->stop();
}

WayPoint P3AT_CommandHandler::getIntermediatePos() {
	//TODO
	WayPoint wp = WayPoint();
	return wp;
}

void P3AT_CommandHandler::mcDone(double rotation) {
	navigationStrategist->mcDone(rotation);
}

void P3AT_CommandHandler::addNavigationStrategist(P3AT_NavigationStrategist *ns){
	navigationStrategist = ns;
}

void P3AT_CommandHandler::startCommand(Command c) {
	motorController->doCommand(c);
}

Command P3AT_CommandHandler::createCommand(double rotation, double distance) {
	Command com = Command();
	com.distance = distance;
	com.rotation = rotation;
	return com;
}

double P3AT_CommandHandler::getVecDegree(double vecX, double vecY) {
	double rads = 0;
	double angle = 0;
	if (vecY == 0) {
		if (vecX > 0) {
			angle = 90;
		}
		else {
			angle = 270;
		}
	}
	else {
		rads = atan(vecX / vecY);
		angle = rads * 180 / PI;
		if (vecY < 0) {
			angle -= 180;
		}
	}
	if (angle < 0) {
		angle += 360;
	}
	return angle;
}