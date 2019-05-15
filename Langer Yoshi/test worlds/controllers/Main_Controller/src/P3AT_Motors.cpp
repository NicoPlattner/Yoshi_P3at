#include "P3AT_Motors.h"
#include <webots/robot.h>

#include <iostream>
#include <fstream>

P3AT_Motors::P3AT_Motors(std::vector<WbDeviceTag> Motoren, float radius_wheel, float rotation_speed, float umfang_wendekreis) 
	: Abstract_Motors(radius_wheel, rotation_speed, umfang_wendekreis){
	std::vector<WbDeviceTag>::iterator Iter;
	for (Iter = Motoren.begin(); Iter != Motoren.end(); Iter++) {
		this->Motors.push_back(*Iter);
		wb_motor_set_position(this->Motors.back(), INFINITY);
	}
}

void P3AT_Motors::setLeftWheelsSpeed(double speed) {
	if(this->Motors.size()==2)
		wb_motor_set_velocity(this->Motors[0],speed);
	if (this->Motors.size() == 4) {
		wb_motor_set_velocity(this->Motors[0], speed);
		wb_motor_set_velocity(this->Motors[1], speed);
	}
}
void P3AT_Motors::setRightWheelsSpeed(double speed) {	
	if (this->Motors.size() == 2) {
		wb_motor_set_velocity(this->Motors[1], speed);
	}
	if (this->Motors.size() == 4) {
		wb_motor_set_velocity(this->Motors[2], speed);
		wb_motor_set_velocity(this->Motors[3], speed);
	}
}

void P3AT_Motors::setAllWheelsSpeed(double speed) {
	std::vector<WbDeviceTag>::iterator Iter;
	for (Iter = this->Motors.begin(); Iter != this->Motors.end(); Iter++) {
		wb_motor_set_velocity(*Iter, speed);
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

	if (!this->_operating) {	//TODO: MIGRATE???
		_operating = true;
		float strecke = this->UMFANG_WENDEKREIS / 360 * degree;
		float streckePerSekunde = RpsToMps(this->ROTATION_SPEED, this->RADIUS_WHEEL);
		this->_calculatedDuration = strecke / streckePerSekunde;
		this->_startTimeStamp = wb_robot_get_time();
		this->setLeftWheelsSpeed(direction*this->ROTATION_SPEED);
		this->setRightWheelsSpeed((-direction)*this->ROTATION_SPEED);
	}
	else {
		if (wb_robot_get_time() - this->_startTimeStamp >= _calculatedDuration) {
			this->setAllWheelsSpeed(0);
		}
	}
}
void P3AT_Motors::drive(double distance) {		
	this->_operating = true;
	this->_distanceDriven = 0;
	this->_startTimeStamp = wb_robot_get_time();
	if (distance > 0) {
		this->setAllWheelsSpeed(this->ROTATION_SPEED);
	}
	else {
		this->setAllWheelsSpeed(-this->ROTATION_SPEED);
	}
}

void P3AT_Motors::recalcDistance() {	//TODO: add rotation
	double intermediateTime = wb_robot_get_time() - this->_startTimeStamp;
	this->_startTimeStamp = wb_robot_get_time();
	this->_distanceDriven += (RpsToMps(wb_motor_get_velocity(this->Motors[0]), this->RADIUS_WHEEL) * intermediateTime);
}

bool P3AT_Motors::isDone(double distance) {		//TODO: add rotation
	recalcDistance();
	if (abs(distance) <= abs(this->_distanceDriven)) {
		this->setAllWheelsSpeed(0);
		return true;
	}
	return false;
}

void P3AT_Motors::stop(void) {
	this->setAllWheelsSpeed(0);
}

bool P3AT_Motors::isOperating(void) {
	return this->_operating;
}

/*
*Radiant per Second to Meters per Second Converter
*Given: Speed in radiant per seconds and radius of the wheel
*Requirements: Radius has to be given in meter
*Return: Speed in meters per second
*/
double RpsToMps(double rps, float radius) {
	return rps*radius;
}
