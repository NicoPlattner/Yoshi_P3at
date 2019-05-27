#pragma once

#include "WayPoint.h"

//This function adds, gets and removes waypoints from the roadmap
//roadmap functions like a stack for coordinates, if no index is specified

class Abstract_RoadmapController {	//RC
public:
	Abstract_RoadmapController() {};
	virtual WayPoint getCoord() = 0; //get coordiante from tail of roadmap (see *)
	virtual WayPoint getCoord(int index) = 0; //get coordinate from roadmap at index (see *)
	virtual void addCoord(double x, double y) = 0; //add coordinate to tail of list
	virtual void addCoord(double x, double y, int index) = 0; //add coordinate before index
	virtual void delCoord() = 0; //delete coordinate at tail of list
	virtual void delCoord(int index) = 0; //delete coordinate at index
protected:
	std::list<WayPoint> roadmap;
};

// * NOTE: if index is out of scope or getCoord() is called with empty roadmap a WayPoint with isEmpty = true is returned