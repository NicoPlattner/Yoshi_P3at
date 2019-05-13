#include "P3AT_RoadmapController.h"
#include "../../includes/c/webots/robot.h"
#include <iterator>


WayPoint P3AT_RoadmapController::getCoord(){
	if (roadmap.begin() == roadmap.end()) {
		return makeEmpty();
	}
	return *roadmap.begin();
}

WayPoint P3AT_RoadmapController::getCoord(int index) {
	if (index >= roadmap.size()) {
		return makeEmpty();
	}
	std::list<WayPoint> ::iterator it = roadmap.begin();
	std::advance(it, index);
	return *it;
}

void P3AT_RoadmapController::addCoord(int x, int y) {
	WayPoint wp;
	wp.x = x;
	wp.y = y;
	roadmap.push_front(wp);
}

void P3AT_RoadmapController::addCoord(int x, int y, int index) {
	WayPoint wp;
	wp.x = x;
	wp.y = y;
	std::list<WayPoint> ::iterator it = roadmap.begin();
	std::advance(it, index);
	roadmap.insert(it, wp);
}

void P3AT_RoadmapController::delCoord() {
	roadmap.pop_front();
}

void P3AT_RoadmapController::delCoord(int index) {
	std::list<WayPoint> ::iterator it = roadmap.begin();
	std::advance(it, index);
	roadmap.erase(it);
}

WayPoint P3AT_RoadmapController::makeEmpty() {
	WayPoint empty;
	empty.isEmpty = true;
	return empty;
}
