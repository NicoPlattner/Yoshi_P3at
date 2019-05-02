#include<tuple>

#ifndef ABSTRACT_NAVIGATION_STRATEGIST_H
#define ABSTRACT_NAVIGATION_STRATEGIST_H

class Abstract_NavigationStrategist
{
public:
	virtual void mcDone(); //called when motor controller is done with last command; updates position from roadmap
	virtual void mcDone(std::tuple<int, int> coord); //called if last command was interruted; updates position with "coord"
	virtual void causeMotion(); //gets next destination from roadmap and calls setCommand
};

#endif