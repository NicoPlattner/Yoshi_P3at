#include "Abstract_Motors.h"

#ifndef P3AT_MOTORS_H
#define P3AT_MOTORS_H

class P3AT_Motors : public Abstract_Motors {
private:
	std::vector<WbDeviceTag> Motors;
	void setLeftWheelsSpeed(double speed);
	void setRightWheelsSpeed(double speed);
	void setAllWheelsSpeed(double speed);
	double _distanceDriven=0;
	double _startTimeStamp;
	double _calculatedDuration;
	bool _operating=false;

public:
	P3AT_Motors(std::vector<WbDeviceTag> Motoren, float radius_wheel, float rotation_speed, float umfang_wendekreis);
	void rotate(int degree);
	void drive(float distance);
	void stop(void);
	bool isOperating(void);
};

double RpsToMps(double rps, float radius);

#endif