#include <list>
#include <webots/motor.h>

#ifndef ABSTRACT_MOTORS_H
#define ABSTRACT_MOTORS_H

class Motors {
public:
	virtual void rotate(int degree);
	virtual void drive(float distance);
	virtual void stop(void);
};

#endif
