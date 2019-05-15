#include "Abstract_Motors.h"

#ifndef P3AT_MOTORS_H
#define P3AT_MOTORS_H

class P3AT_Motors : public Abstract_Motors {
private:
	std::vector<WbDeviceTag> Motors;
	void setLeftWheelsSpeed(double speed);
	void setRightWheelsSpeed(double speed);
	void setAllWheelsSpeed(double speed);
	void recalcDistance();
	double _distanceDriven=0;
	double _startTimeStamp;
	double _calculatedDuration;
	bool _operating=false;

public:
	P3AT_Motors();
	P3AT_Motors(std::vector<WbDeviceTag> Motoren, double radius_wheel, double rotation_speed, double umfang_wendekreis);
	void rotate(double degree);
	void drive(double distance);
	void stop(void);
	bool isOperating(void);
	bool isDone(bool isTurning, double distance);
};

double RpsToMps(double rps, double radius);

#endif