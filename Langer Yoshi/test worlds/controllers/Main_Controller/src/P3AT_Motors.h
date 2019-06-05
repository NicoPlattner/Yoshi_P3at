#pragma once

#include "Abstract_Motors.h"

class P3AT_Motors : public Abstract_Motors {	//see Abstract_Motors.h for more information
public:
	P3AT_Motors(std::vector<WbDeviceTag> motors, double radius_wheel, double rotation_speed, double umfang_wendekreis);
	void rotate(double degree);
	void drive(double distance);
	void stop(void);
	bool isDone(bool isTurning, double distance, double degree);
	double getDonePercentage(bool isTurning, double distance, double degree);

private:
	void setLeftWheelsSpeed(double speed);
	void setRightWheelsSpeed(double speed);
	void setAllWheelsSpeed(double speed);
	void recalcDistance(bool isTurning);	//updates distance driven between last check and this check
	double RpsToMps(double rps, double radius); //converts radiant per second to meters per second
	double degreeToDistance(double rotationDegree);

	double _distanceDriven = 0;
	double _startTimeStamp;
	double _calculatedDuration;
};