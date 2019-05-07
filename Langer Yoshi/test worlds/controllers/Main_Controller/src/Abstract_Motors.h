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
	Abstract_Motors(float radius_wheel, float rotation_speed,float umfang_wendekreis) {
		this->RADIUS_WHEEL = radius_wheel;
		this->ROTATION_SPEED = rotation_speed;
		this->UMFANG_WENDEKREIS = umfang_wendekreis;
	};
	virtual void rotate(int degree) = 0;
	virtual void drive(float distance) = 0;
	virtual void stop(void) = 0;
};

#endif
