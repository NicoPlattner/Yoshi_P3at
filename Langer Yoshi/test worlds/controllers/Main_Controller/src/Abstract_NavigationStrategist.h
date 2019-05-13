#include<tuple>
#include"WayPoint.h"

#ifndef ABSTRACT_NAVIGATION_STRATEGIST_H
#define ABSTRACT_NAVIGATION_STRATEGIST_H

class Abstract_NavigationStrategist
{
public:
	virtual void mcDone(); //called when motor controller is done with last command; updates position from roadmap
	virtual void mcDone(WayPoint intermediate); //called if last command was interruted; updates position with "coord"
	virtual void causeMotion(); //gets next destination from roadmap and calls setCommand
};

#endif

/*some definitions; MOVE SOMEWHERE ELSE!
*starting position is x = 0, y = 0
(should coords be floats rather than int?)
*starting rotation (looking north) is 0
*rotation is always a value within [0; 360[
*/