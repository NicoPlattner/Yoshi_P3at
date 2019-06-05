#include "stdafx.h"

#include "P3AT_MotorController.h"
#include "P3AT_CommandHandler.h"
#include "Command.h"
#include "Log.h"

P3AT_MotorController::P3AT_MotorController() : Abstract_MotorController::Abstract_MotorController() {
	// get devices
	WbDeviceTag front_left_wheel = wb_robot_get_device("front left wheel");
	WbDeviceTag front_right_wheel = wb_robot_get_device("front right wheel");
	WbDeviceTag back_left_wheel = wb_robot_get_device("back left wheel");
	WbDeviceTag back_right_wheel = wb_robot_get_device("back right wheel");

	std::vector<WbDeviceTag> motVec;
	motVec.push_back(front_left_wheel);
	motVec.push_back(back_left_wheel);
	motVec.push_back(front_right_wheel);
	motVec.push_back(back_right_wheel);

	double radius_wheel = 0.10;	//Reifenradius ~10cm???
	double rotation_speed = 2 * M_PI; //Eine halbe Reifenumdrehung pro Sekunde
	double umfang_wendekreis = 1.6336;	//Diagonale Rad zu Rad ~ 70cm -> Kreisumfang mit der Diagonale als Annäherung in Meter (1.6336)

	currentCommand.isObsolete = true;

	this->Motors = new P3AT_Motors(motVec, radius_wheel, rotation_speed, umfang_wendekreis);

}

void P3AT_MotorController::doCommand(Command c) {
	this->currentCommand = c;
	if (!currentCommand.isObsolete) {
		if (_isTurning) {
			if (currentCommand.rotation != 0) {
				rotate(currentCommand.rotation);
			}
			else {
				_isTurning = false;
				doCommand(currentCommand);
			}
		}
		else {
			drive(currentCommand.distance);
		}
	}
}


void P3AT_MotorController::stop() {
	this->Motors->stop();
	this->_isStopped = true;
	this->currentCommand.isObsolete = true;
}


WayPoint P3AT_MotorController::getIntermediate() {

	//TODO
	WayPoint c;

	return c;
}


void P3AT_MotorController::rotate(double degrees) {
	this->Motors->rotate(degrees);
}


void P3AT_MotorController::drive(double metres) {
	std::ostringstream strs;
	strs << "Driving " << metres <<  " meters\n";
	std::string str = strs.str();
	Log::writeLog(str);
	this->Motors->drive(metres);
}

double P3AT_MotorController::calcDistance() {
	return Motors->getDonePercentage(_isTurning, currentCommand.distance, currentCommand.rotation);
}

void P3AT_MotorController::check() {
	if (_isStopped) {
		reportStop();
		_isStopped = false;
	}
	else if (currentCommand.isObsolete == true) {
		Log::writeLog("isObsolete");
		fetchNextCommand();
	}
	else if (this->Motors->isDone(_isTurning, currentCommand.distance, currentCommand.rotation)) {
		if (_isTurning) {
			_isTurning = false;
			doCommand(currentCommand);
		}
		else {
			_isTurning = true;
			Motors->stop();
			fetchNextCommand();
		}
	}
}

void P3AT_MotorController::fetchNextCommand() {
	commandHandler->mcDone(currentCommand.rotation);
}

void P3AT_MotorController::reportStop() {
	double percentDone = calcDistance();
	commandHandler->mcDone(currentCommand.rotation, percentDone);
}

void P3AT_MotorController::addCommandHandler(Abstract_CommandHandler *ch) {
	commandHandler = ch;
}