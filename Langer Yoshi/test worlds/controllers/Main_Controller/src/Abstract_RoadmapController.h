#pragma once

#include<list>
#include "WayPoint.h"

class Abstract_RoadmapController {
public:
	Abstract_RoadmapController() {};
	virtual WayPoint getCoord() = 0; //get coordiante from tail of roadmap (see *)
	virtual WayPoint getCoord(int index) = 0; //get coordinate from roadmap at index (see *)
	virtual void addCoord(int x, int y) = 0; //add coordinate to tail of list
	virtual void addCoord(int x, int y, int index) = 0; //add coordinate before index
	virtual void delCoord() = 0; //delete coordinate at tail of list
	virtual void delCoord(int index) = 0; //delete coordinate at index
protected:
	virtual WayPoint makeEmpty() = 0;	//creates empty WayPoint for when roadmap is empty
	std::list<WayPoint> roadmap;
};

// * NOTE: if index is out of scope or getCoord() is called with empty roadmap a WayPoint with isEmpty = true is returned