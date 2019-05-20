#include "src/P3AT_MotorController.h"
#include "src/P3AT_RoadmapController.h"
#include "src/P3AT_CommandHandler.h"
#include "src/P3AT_NavigationStrategist.h"
#include "src/Log.h"

#define TIME_STEP 32

int main(int argc, char **argv)
{
	//Empty out file with append = false and write initial message
	Log* log = Log::getInstance();
	log->writeLog("Start Robot", "out.txt", false);

	//Initialize robot and controllers
	wb_robot_init();
	Abstract_MotorController *mc = new P3AT_MotorController();
	Abstract_RoadmapController *rc = new P3AT_RoadmapController();
	Abstract_CommandHandler *ch = new P3AT_CommandHandler(mc);
	Abstract_NavigationStrategist *navStrat = new P3AT_NavigationStrategist(rc, ch);

	//Add coordinates to the roadmap that should be driven to 
	rc->addCoord(0, 0);
	rc->addCoord(2, -1);
	rc->addCoord(0, -1);
	rc->addCoord(0, 1);
	rc->addCoord(2, 1);

	int testCounter = 0;

	// control loop
	while (wb_robot_step(TIME_STEP) != -1) {
		mc->check();	//check if last command is done
		if (testCounter == 1000) {
			Log *log = Log::getInstance();
			log->writeLog("NEW COMMAND ADDED               !!!", "out.txt", true);
			rc->addCoord(0, 3);
		}
		testCounter++;
	}
	
	wb_robot_cleanup();

	return 0;
}
