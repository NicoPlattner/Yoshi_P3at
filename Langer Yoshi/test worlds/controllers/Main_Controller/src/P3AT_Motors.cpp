#include "stdafx.h"

#include "P3AT_Motors.h"
#include "Log.h"

P3AT_Motors::P3AT_Motors(std::vector<WbDeviceTag> motors, double radius_wheel, double rotation_speed, double umfang_wendekreis)
	: Abstract_Motors(motors, radius_wheel, rotation_speed, umfang_wendekreis) {
	this->RADIUS_WHEEL = radius_wheel;
	this->ROTATION_SPEED = rotation_speed;
	this->UMFANG_WENDEKREIS = umfang_wendekreis;
	this->_motors = motors;

	for (auto motor : _motors) {
		wb_motor_set_position(motor, INFINITY);	//this is required for webots to function correctly
	}
}

void P3AT_Motors::setLeftWheelsSpeed(double speed) {
	if (this->_motors.size() == 2) {
		wb_motor_set_velocity(this->_motors[0], speed);
	}
	else if (this->_motors.size() == 4) {
		wb_motor_set_velocity(this->_motors[0], speed);
		wb_motor_set_velocity(this->_motors[1], speed);
	}
}
void P3AT_Motors::setRightWheelsSpeed(double speed) {
	if (this->_motors.size() == 2) {
		wb_motor_set_velocity(this->_motors[1], speed);
	}
	else	if (this->_motors.size() == 4) {
		wb_motor_set_velocity(this->_motors[2], speed);
		wb_motor_set_velocity(this->_motors[3], speed);
	}
}

void P3AT_Motors::setAllWheelsSpeed(double speed) {
	for (auto motor : _motors) {
		wb_motor_set_velocity(motor, speed);
	}
}

void P3AT_Motors::rotate(double degree) {
	int direction;
	direction = degree > 0 ? 1 : -1;

	this->_distanceDriven = 0;
	this->_startTimeStamp = wb_robot_get_time();
	std::ostringstream strs;
	strs << "new Dist.: " << this->_distanceDriven << " Meter\n";
	strs << "new Time: " << this->_startTimeStamp << " Sek\n";
	std::string str = strs.str();
	Log::writeLog(str);
	this->setLeftWheelsSpeed(direction*this->ROTATION_SPEED);
	this->setRightWheelsSpeed((-direction)*this->ROTATION_SPEED);
}
void P3AT_Motors::drive(double distance) {
	this->_distanceDriven = 0;
	this->_startTimeStamp = wb_robot_get_time();
	if (distance > 0) {
		this->setAllWheelsSpeed(this->ROTATION_SPEED);
	}
	else {
		this->setAllWheelsSpeed(-this->ROTATION_SPEED);
	}
}

void P3AT_Motors::recalcDistance(bool isTurning) {
	if (isTurning) {
		double intermediateTime = wb_robot_get_time() - this->_startTimeStamp;
		this->_startTimeStamp = wb_robot_get_time();
		double currentSpeed = RpsToMps(wb_motor_get_velocity(this->_motors[0]), this->RADIUS_WHEEL) * (0.390 / 0.473);	//komplizierte Formel für dreh geschwindigkeit :O
		this->_distanceDriven += currentSpeed * intermediateTime;
	}
	else {
		double intermediateTime = wb_robot_get_time() - this->_startTimeStamp;
		this->_startTimeStamp = wb_robot_get_time();
		this->_distanceDriven += (RpsToMps(wb_motor_get_velocity(this->_motors[0]), this->RADIUS_WHEEL) * intermediateTime);
	}

}

bool P3AT_Motors::isDone(bool isTurning, double distance, double degree) {
	if (isTurning) {
		recalcDistance(true);
		double tmp = this->_distanceDriven;
		std::ostringstream strs;
		strs << "DistTmp: " << tmp << "\n";
		std::string str = strs.str();
		Log::writeLog(str);
		if (abs(degreeToDistance(degree)) - 0.01 < abs(this->_distanceDriven)) {

			strs << "Gedreht: " << degree << " Grad, mit Distanz:" << degreeToDistance(degree) << " Meter\n";
			strs << "Distanz gefahren: " << this->_distanceDriven << "\n";
			std::string str = strs.str();
			Log::writeLog(str);
			this->setAllWheelsSpeed(0);
			return true;
		}
	}
	else {
		recalcDistance(false);
		if (abs(distance) - 0.01 < abs(this->_distanceDriven)) {
			this->setAllWheelsSpeed(0);
			return true;
		}
	}
	return false;
}

double P3AT_Motors::getDonePercentage(bool isTurning, double distance, double degree) {
	double doneDist;
	if (isTurning) {
		doneDist = abs(degreeToDistance(degree));
	}
	else {
		doneDist = abs(distance);
	}
	return doneDist / abs(this->_distanceDriven);
}

void P3AT_Motors::stop(void) {
	this->setAllWheelsSpeed(0);
}

/*
*Radiant per Second to Meters per Second Converter
*Given: Speed in radiant per seconds and radius of the wheel
*Requirements: Radius has to be given in meter
*Return: Speed in meters per second
*/
double P3AT_Motors::RpsToMps(double rps, double radius) {
	return rps * radius;
}

double P3AT_Motors::degreeToDistance(double rotationDegree) {
	return (rotationDegree / 360.0) * this->UMFANG_WENDEKREIS;
}
