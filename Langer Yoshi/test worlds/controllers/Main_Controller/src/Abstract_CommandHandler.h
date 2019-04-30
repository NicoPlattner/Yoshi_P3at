#include <tuple>
#include "Command.h"
#include "Abstract_MotorController.h"

#ifndef ABSTRACT_COMMAND_HANDLER_H
#define ABSTRACT_COMMAND_HANDLER_H

class Abstract_CommandHandler {
public:
	Abstract_CommandHandler(Abstract_MotorController MC);
	virtual void setCommand(std::tuple<int,int> origin, int direction, std::tuple<int,int> destination);
	virtual void stop(void);
	virtual std::tuple<int, int> getIntermediatePos();
	virtual bool commandDone(void);
private:
	virtual void startCommand(void);	//CmdHandler hällt MC Objekt schon und ruft MC.doCommand() auf
	virtual Command createCommand();
};


#endif


