#include <list>
#include <webots/motor.h>

#ifndef ABSTRACT_MOTORS_H
#define ABSTRACT_MOTORS_H

class Motors {
public:
	Motors(std::list<WbDeviceTag>);	//2 Motors List-> left = 0, right = 1 | 4 Motors List-> front left/right = 0/1, back left/right = 2,3
	virtual void rotate(int degree);
	virtual void drive(float distance);
	virtual void stop(void);
};

#endif
