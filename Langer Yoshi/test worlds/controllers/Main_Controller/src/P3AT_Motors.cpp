#include "P3AT_Motors.h"
#include <webots/robot.h>

#include <iostream>
#include <fstream>

P3AT_Motors::P3AT_Motors(std::vector<WbDeviceTag> motors, double radius_wheel, double rotation_speed, double umfang_wendekreis)
	: Abstract_Motors(motors, radius_wheel, rotation_speed, umfang_wendekreis){
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
	} else	if (this->_motors.size() == 4) {
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
	if (degree > 0) {
		direction = 1;
	}
	else {
		direction = -1;
	}

	double strecke = this->UMFANG_WENDEKREIS / 360 * degree * direction;
	double streckePerSekunde = RpsToMps(this->ROTATION_SPEED, this->RADIUS_WHEEL);
	this->_calculatedDuration = strecke / streckePerSekunde;		//TODO: same for drive
	this->_startTimeStamp = wb_robot_get_time();
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

void P3AT_Motors::recalcDistance() {	//TODO: add rotation (srly why wasn't it from the start?)
	double intermediateTime = wb_robot_get_time() - this->_startTimeStamp;
	this->_startTimeStamp = wb_robot_get_time();
	this->_distanceDriven += (RpsToMps(wb_motor_get_velocity(this->_motors[0]), this->RADIUS_WHEEL) * intermediateTime);
}

bool P3AT_Motors::isDone(bool isTurning, double distance) {
	if (isTurning) {
		if (wb_robot_get_time() - this->_startTimeStamp >= _calculatedDuration) {
			this->setAllWheelsSpeed(0);
			return true;
		}
	}
	else {
		recalcDistance();			//TODO: can we please have this be useful for either mode or not use it
		if (abs(distance) <= abs(this->_distanceDriven)) {
			this->setAllWheelsSpeed(0);
			return true;
		}
	}
	return false;
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
	return rps*radius;
}
