#include "Abstract_RoadmapController.h"

#ifndef P3AT_ROADMAP_CONTROLLER_H
#define P3AT_ROADMAP_CONTROLLER_H

class P3AT_RoadmapController : public Abstract_RoadmapController{ //see Abstract_RoadmapController.h for info on functions
public:
	P3AT_RoadmapController() {};
	WayPoint getCoord();
	WayPoint getCoord(int index);
	void addCoord(int x, int y);
	void addCoord(int x, int y, int index);
	void delCoord();
	void delCoord(int index);
protected:
	WayPoint makeEmpty();
};

#endif