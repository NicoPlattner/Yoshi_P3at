#pragma once

#include "Abstract_RoadmapController.h"

class P3AT_RoadmapController : public Abstract_RoadmapController{ //see Abstract_RoadmapController.h for more information
public:
	P3AT_RoadmapController() {};
	WayPoint getCoord();
	WayPoint getCoord(int index);
	void addCoord(int x, int y);
	void addCoord(int x, int y, int index);
	void delCoord();
	void delCoord(int index);
protected:
	WayPoint makeEmpty();	//creates empty WayPoint for when roadmap is empty
};
