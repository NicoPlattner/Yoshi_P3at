#include<tuple>

#ifndef ABSTRACT_ROADMAP_CONTROLLER_H
#define ABSTRACT_ROADMAP_CONTROLLER_H

class AbstractRoadmapController {
public:
	std::tuple<int, int> getCoord(); //get next coordiante from roadmap
	std::tuple<int, int> getCoord(int index); //get coordinate from roadmap at index
	void addCoord(std::tuple<int, int> coord); //add coordinate to tail of list
	void addCoord(std::tuple<int, int> coord, int index); //add coordinate before index
	void delCoord(); //delete coordinate at head of list
	void delCoord(int index); //delete coordinate at index
};

#endif