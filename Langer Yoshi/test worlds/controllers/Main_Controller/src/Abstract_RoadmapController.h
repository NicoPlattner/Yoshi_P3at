#include<tuple>
#include<list>

#ifndef ABSTRACT_ROADMAP_CONTROLLER_H
#define ABSTRACT_ROADMAP_CONTROLLER_H

class AbstractRoadmapController {
public:
	AbstractRoadmapController(std::list<int> roadmap);
	virtual std::tuple<int, int> getCoord(); //get next coordiante from roadmap
	virtual std::tuple<int, int> getCoord(int index); //get coordinate from roadmap at index
	virtual void addCoord(std::tuple<int, int> coord); //add coordinate to tail of list
	virtual void addCoord(std::tuple<int, int> coord, int index); //add coordinate before index
	virtual void delCoord(); //delete coordinate at head of list
	virtual void delCoord(int index); //delete coordinate at index
};

#endif