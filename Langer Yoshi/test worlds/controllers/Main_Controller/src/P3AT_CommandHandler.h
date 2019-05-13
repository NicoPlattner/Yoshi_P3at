#include "Abstract_CommandHandler.h"
#include "P3AT_MotorController.h"

#ifndef P3AT_COMMAND_HANDLER_H
#define P3AT_COMMAND_HANDLER_H

class P3AT_CommandHandler : public Abstract_CommandHandler {
public:
	P3AT_CommandHandler(P3AT_MOTOR_CONTROLLER *MC);
	void commandMotor(double currentRotation, WayPoint origin, WayPoint destination);
	void stop(void);
	WayPoint getIntermediatePos();
	bool commandDone(void);
private:
	void startCommand(Command c);	//CmdHandler hällt MC Objekt schon und ruft MC.doCommand() auf
	Command createCommand(double rotation, double distance);
	double getVecDegree(double vecX, double vecY);
	P3AT_MOTOR_CONTROLLER *motorController;
};


#endif