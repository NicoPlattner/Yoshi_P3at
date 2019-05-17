#ifndef WAY_POINT_H
#define WAY_POINT_H

//way points are used to track the robot's current position and the points the robot will attempt to drive to

struct WayPoint {
	int x = 0;				//x coordinate distance from the bootup position
	int y = 0;				//y coordinate distance from the bootup position
	bool isEmpty = false;	//this is set as true if the roadmap is empty or an index that does not exist was requested from the roadmap
};

#endif