#import "Abstract_Motors.h"

#ifndef P3AT_MOTORS_H
#define P3AT_MOTORS_H

class P3AT_Motors : public Motors {
public:
	P3AT_Motors(std::list<WbDeviceTag>);
	void rotate(int degree);
	void drive(float distance);
	void stop(void);
private:
};

#endif
