#include<list>
#include "WayPoint.h"

#ifndef ABSTRACT_ROADMAP_CONTROLLER_H
#define ABSTRACT_ROADMAP_CONTROLLER_H

class Abstract_RoadmapController {
public:
	Abstract_RoadmapController() {};
	virtual WayPoint getCoord(); //get next coordiante from roadmap
	virtual WayPoint getCoord(int index); //get coordinate from roadmap at index
	virtual void addCoord(int x, int y); //add coordinate to tail of list
	virtual void addCoord(int x, int y, int index); //add coordinate before index
	virtual void delCoord(); //delete coordinate at head of list
	virtual void delCoord(int index); //delete coordinate at index
protected:
	std::list<WayPoint> roadmap;
};

#endif