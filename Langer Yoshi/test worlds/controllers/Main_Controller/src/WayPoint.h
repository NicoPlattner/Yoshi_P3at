#pragma once

//way points are used to track the robot's current position and the points the robot will attempt to drive to

struct WayPoint {
	double x = 0;				//x coordinate distance from the bootup position
	double y = 0;				//y coordinate distance from the bootup position
	bool isEmpty = false;	//this is set as true if the roadmap is empty or an index that does not exist was requested from the roadmap
};
