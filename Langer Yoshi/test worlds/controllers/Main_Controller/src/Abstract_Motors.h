#include <vector>
#include <webots/motor.h>

#ifndef ABSTRACT_MOTORS_H
#define ABSTRACT_MOTORS_H

class Abstract_Motors {
protected:
	double RADIUS_WHEEL;
	double ROTATION_SPEED;
	double UMFANG_WENDEKREIS;
protected:
	Abstract_Motors(double radius_wheel, double rotation_speed, double umfang_wendekreis) {
		this->RADIUS_WHEEL = radius_wheel;
		this->ROTATION_SPEED = rotation_speed;
		this->UMFANG_WENDEKREIS = umfang_wendekreis;
	};
	virtual void rotate(double degree) = 0;
	virtual void drive(double distance) = 0;
	virtual void stop(void) = 0;
	virtual bool isDone(bool isTurning, double distance) = 0;
};

#endif
