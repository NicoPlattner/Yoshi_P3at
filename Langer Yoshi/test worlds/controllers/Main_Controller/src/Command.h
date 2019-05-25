#pragma once

//the command handler creates commands for the motor controller

struct Command {	
	double rotation = 0;	//amount of degrees the robot should turn (positive = turn right, negative = turn left)
	double distance = 0;	//distance the robot should move in meters
	bool isObsolete = false;	//is set if the command can't be completed; MC will fetch the next command if this is set
};
