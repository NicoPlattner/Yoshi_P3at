#include "stdafx.h"

#include "P3AT_RoadmapController.h"


WayPoint P3AT_RoadmapController::getCoord() {
	if (roadmap.size() == 0) {
		return makeEmpty();
	}
	return *roadmap.begin();
}

WayPoint P3AT_RoadmapController::getCoord(int index) {
	//if index out of scope, return empty Waypoint
	if (index >= roadmap.size()) {
		return makeEmpty();
	}
	//iterates through roadmap until it reaches index, returns coordinate
	std::list<WayPoint> ::iterator it = roadmap.begin();
	std::advance(it, index);
	return *it;
}

void P3AT_RoadmapController::addCoord(double x, double y) {
	WayPoint wp;
	wp.x = x;
	wp.y = y;
	roadmap.push_front(wp);
}

void P3AT_RoadmapController::addCoord(double x, double y, int index) {
	WayPoint wp;
	wp.x = x;
	wp.y = y;
	//iterates through roadmap until it reaches index, inserts coordinate before index
	std::list<WayPoint> ::iterator it = roadmap.begin();
	std::advance(it, index);
	roadmap.insert(it, wp);
	//TODO: error handling for too large index???
}

void P3AT_RoadmapController::delCoord() {
	if (!roadmap.size() == 0) {
		roadmap.pop_front();
	}
	//TODO: return value for when empty??
}

void P3AT_RoadmapController::delCoord(int index) {
	if (index <= roadmap.size()) {
		//iterates through roadmap until it reaches index, deletes coordinate at index
		std::list<WayPoint> ::iterator it = roadmap.begin();
		std::advance(it, index);
		roadmap.erase(it);
	}
	//TODO: return value for when empty??
}

WayPoint P3AT_RoadmapController::makeEmpty() {
	WayPoint empty;
	empty.isEmpty = true;
	return empty;
}