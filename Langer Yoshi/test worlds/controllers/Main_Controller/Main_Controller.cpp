#include "src/P3AT_MotorController.h"
#include "src/P3AT_RoadmapController.h"
#include "src/P3AT_CommandHandler.h"
#include "src/P3AT_NavigationStrategist.h"

#define TIME_STEP 32

int main(int argc, char **argv)
{
	wb_robot_init();
	Abstract_MotorController *mc = new P3AT_MotorController();
	Abstract_RoadmapController *rc = new P3AT_RoadmapController();
	Abstract_CommandHandler *ch = new P3AT_CommandHandler(mc);
	Abstract_NavigationStrategist *navStrat = new P3AT_NavigationStrategist(rc, ch);

	rc->addCoord(0, 0);
	rc->addCoord(1, -1);
	rc->addCoord(-1, -1);
	rc->addCoord(-1, 1);
	rc->addCoord(1, 1);

	// control loop
	while (wb_robot_step(TIME_STEP) != -1) {
		/*Command drive;
		Command rotate;

		drive.distance = 0.5;
		drive.rotation = 0;

		rotate.distance = 0;
		rotate.rotation = 90;

		//mc.doCommand(drive);
		mc->doCommand(rotate);*/
		mc->check();
	}
	
	wb_robot_cleanup();

	return 0;
}
