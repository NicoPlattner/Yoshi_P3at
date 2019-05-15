#include "P3AT_MotorController.h"
#include "P3AT_CommandHandler.h"
#include "Command.h"

P3AT_MOTOR_CONTROLLER::P3AT_MOTOR_CONTROLLER() : Abstract_MotorController::Abstract_MotorController() {
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

	float radius_wheel = 0.10;	//Reifenradius ~10cm???
	float rotation_speed = 2 * M_PI; //Eine halbe Reifenumdrehung pro Sekunde
	float umfang_wendekreis = 1.8;	//Diagonale Rad zu Rad ~ 70cm -> Kreisumfang mit der Diagonale als Annäherung in Meter

	this->Motors = new P3AT_Motors(motVec, radius_wheel, rotation_speed, umfang_wendekreis);

}


void P3AT_MOTOR_CONTROLLER::doCommand(Command c) {
	this->currentCommand = c;
	/*if (c.rotation != 0) {	//TODO
		rotate(c.rotation);
	}
	else*/ if (currentCommand.distance != 0) {
		drive(currentCommand.distance);
	}
}


void P3AT_MOTOR_CONTROLLER::stop() {
	this->Motors->stop();
	this->isStopped = true;
	//TODO
}


Command P3AT_MOTOR_CONTROLLER::getIntermediate() {
	//TODO
	Command c;

	return c;
}


void P3AT_MOTOR_CONTROLLER::rotate(double degrees) {
	this->Motors->rotate(degrees);
}


void P3AT_MOTOR_CONTROLLER::drive(double metres) {
	this->Motors->drive(metres);
}

float P3AT_MOTOR_CONTROLLER::calculateDistance() {
	//TODO
	return 0;
}

void P3AT_MOTOR_CONTROLLER::check() {
	if (isStopped) {
		//TODO: implement call of local strategy in navigation strategist
	}
	else if (&currentCommand == NULL) {
		fetchNextCommand();
	}
	else if (this->Motors->isDone(currentCommand.distance)) {
		fetchNextCommand();
	}
}

void P3AT_MOTOR_CONTROLLER::fetchNextCommand() {
	commandHandler->mcDone(currentCommand.rotation);
}

void P3AT_MOTOR_CONTROLLER::addCommandHandler(P3AT_CommandHandler *ch) {
	commandHandler = ch;
}