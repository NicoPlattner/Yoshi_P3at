#include "src/stdafx.h"

#include "src/P3AT_MotorController.h"
#include "src/P3AT_RoadmapController.h"
#include "src/P3AT_CommandHandler.h"
#include "src/P3AT_SensorController.h"
#include "src/P3AT_NavigationStrategist.h"
#include "src/Log.h"

#define TIME_STEP 32

int main(int argc, char **argv)
{
	//Empty out file with append = false and write initial message
	Log::emptyLog();

	//Initialize robot and controllers
	wb_robot_init();
	Abstract_MotorController *mc = new P3AT_MotorController();
	Abstract_RoadmapController *rc = new P3AT_RoadmapController();
	Abstract_CommandHandler *ch = new P3AT_CommandHandler(mc);
	Abstract_NavigationStrategist *navStrat = new P3AT_NavigationStrategist(rc, ch);
	Abstract_SensorController *senseController = new P3AT_SensorController(navStrat);
	

	//Add coordinates to the roadmap that should be driven to 
	rc->addCoord(-10, 20);
	rc->addCoord(0, 0);
	rc->addCoord(1, 1);
	rc->addCoord(1, -1);
	rc->addCoord(-1, -1);
	rc->addCoord(-1, 1);
	rc->addCoord(0, 1);

	int testCounter = 0;

	// control loop
	while (wb_robot_step(TIME_STEP) != -1) {
		mc->check();	//check if last command is done
		if (testCounter == 1000) {
			//Log::writeLog("NEW COMMAND ADDED               !!!");
			//rc->addCoord(0, 3);
		}
		testCounter++;

		senseController->checkSenses();
	}
	
	wb_robot_cleanup();

	return 0;
}
