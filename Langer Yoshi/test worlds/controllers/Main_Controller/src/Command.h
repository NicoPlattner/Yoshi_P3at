#ifndef COMMAND_H
#define COMMAND_H

//the command handler creates commands for the motor controller

struct Command {	
	double rotation;	//amount of degrees the robot should turn (positive = turn right, negative = turn left)
	double distance;	//distance the robot should move in meters
	bool isObsolete;	//is set if the command can't be completed; MC will fetch the next command if this is set
};


#endif