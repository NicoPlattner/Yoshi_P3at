#pragma once

//This class holds the robot's motors and acts as an abstraction layer. It also checks if the latest command is done

class Abstract_Motors {
public:
	Abstract_Motors(std::vector<WbDeviceTag> motors, double radius_wheel, double rotation_speed, double umfang_wendekreis) { };
	virtual void rotate(double degree) = 0;	//robot turns on the spot; negative degrees cuases left turn, positive right turn
	virtual void drive(double distance) = 0;	//move forward in a straight line for "distance" meters
	virtual void stop(void) = 0;	//sets motor speed to 0
	virtual bool isDone(bool isTurning, double distance, double degree) = 0;	//checks if latest command is done
	virtual double getDonePercentage(bool isTurning, double distance, double degree) = 0;	//returns how much of the current command has been completed in % (does not return whether this is the percentage of turning or driving)
protected:
	double RADIUS_WHEEL;
	double ROTATION_SPEED;
	double UMFANG_WENDEKREIS;
	std::vector<WbDeviceTag> _motors;
};

