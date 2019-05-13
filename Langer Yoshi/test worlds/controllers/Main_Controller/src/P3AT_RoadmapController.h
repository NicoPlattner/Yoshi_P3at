#include "Abstract_RoadmapController.h"

#ifndef P3AT_ROADMAP_CONTROLLER_H
#define P3AT_ROADMAP_CONTROLLER_H

class P3AT_RoadmapController : public Abstract_RoadmapController{
public:
	P3AT_RoadmapController() {};
	WayPoint getCoord(); //get next coordiante from roadmap
	WayPoint getCoord(int index); //get coordinate from roadmap at index
	void addCoord(int x, int y); //add coordinate to tail of list
	void addCoord(int x, int y, int index); //add coordinate before index
	void delCoord(); //delete coordinate at head of list
	void delCoord(int index); //delete coordinate at index
protected:
	WayPoint makeEmpty();
	std::list<WayPoint> roadmap;
};

#endif