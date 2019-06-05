#include "stdafx.h"

#include "P3AT_CommandHandler.h"
#include "P3AT_MotorController.h"
#include "P3AT_NavigationStrategist.h"
#include "Log.h"

P3AT_CommandHandler::P3AT_CommandHandler(Abstract_MotorController *MC) : Abstract_CommandHandler::Abstract_CommandHandler(MC) {
	//add pointer of MC to CH and of CH to MC (2-ways communication)
	this->motorController = MC;
	this->motorController->addCommandHandler(this);
};

void P3AT_CommandHandler::commandMotor(double currentRotation, WayPoint position, WayPoint destination) {
	if (destination.isEmpty == true) {	
		//if there are no more destinations, create obsolete command
		Command c = createCommand(0, 0);
		c.isObsolete = true;
		motorController->doCommand(c);
	}
	else {
		//Calculate distance with squrt( (x2 - x1)^2 + (y2 -y1)^2 ) 
		double distXpart = pow((destination.x - position.x), 2);
		double distYpart = pow((destination.y - position.y), 2);
		double distance = sqrt(distXpart + distYpart);

		//calculate rotation
		double angle = getVecDegree(destination.x - position.x, destination.y - position.y);
		double rotate = angle - currentRotation;	//subtract current rotation from angle between vector and y-axis

		//The robot shouldn't rotate more than 180° as it would be quicker to rotate in the opposite direction
		if (rotate > 180) {
			rotate -= 360;
		}
		else if (rotate < -180) {
			rotate += 360;
		}

		//LOG
		std::ostringstream strs;
		strs << position.x << "," << position.y << "; " << destination.x << "," << destination.y << "\n";
		strs << angle << "; " << rotate << "; " << distance;
		std::string str = strs.str();
		Log::writeLog(str);

		//create and start command
		Command c = createCommand(rotate, distance);
		motorController->doCommand(c);
	}
	
}

void P3AT_CommandHandler::stop(void) {
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

void P3AT_CommandHandler::mcDone(double rotation, double percentDone) {
	navigationStrategist->mcDone(rotation, percentDone);
}

void P3AT_CommandHandler::addNavigationStrategist(Abstract_NavigationStrategist *ns){
	navigationStrategist = ns;
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
	if (vecY == 0) {	//tan-1(x/y) would be dividing by 0 for y = 0
		if (vecX == 0) {
			angle = 0;	//if vector = (0, 0) no turning is necessary
		}
		else if (vecX > 0) {	
			angle = 90;	//vector is positive x-axis
		}
		else {
			angle = 270;//vector is negative x-axis
		}
	}
	else {
		rads = atan(vecX / vecY);	//returns tan^-1(x/y) in rads
		angle = rads * 180 / PI;	//convert rads to degrees
		if (vecY < 0) {		//the same value is returned for y and -y
			angle -= 180;	//get actual angle for negative y
		}
	}

	return angle;
}