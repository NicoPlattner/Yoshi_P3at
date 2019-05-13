#include<list>
#include "WayPoint.h"

#ifndef ABSTRACT_ROADMAP_CONTROLLER_H
#define ABSTRACT_ROADMAP_CONTROLLER_H

class Abstract_RoadmapController {
public:
	Abstract_RoadmapController() {};
	virtual WayPoint getCoord() = 0; //get next coordiante from roadmap
	virtual WayPoint getCoord(int index) = 0; //get coordinate from roadmap at index
	virtual void addCoord(int x, int y) = 0; //add coordinate to tail of list
	virtual void addCoord(int x, int y, int index) = 0; //add coordinate before index
	virtual void delCoord() = 0; //delete coordinate at head of list
	virtual void delCoord(int index) = 0; //delete coordinate at index
protected:
	virtual WayPoint makeEmpty() = 0;
	std::list<WayPoint> roadmap;
};

#endif