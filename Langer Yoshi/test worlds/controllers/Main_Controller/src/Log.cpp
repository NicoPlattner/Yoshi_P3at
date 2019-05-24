#include "Log.h"

Log::Log() {
	//false;
}

/*Log * Log::getInstance() // David wtf???
{
	static Log instance;
	return &instance;
}*/

void Log::writeLog(std::string msg) {
	std::ofstream file("out.txt", std::fstream::out | std::fstream::app);
	if (file.is_open()) {
		file << msg << std::endl;
		file.close();
	}
	else {
		throw std::exception("Could not open Logfile");
	}
}

void Log::emptyLog() {
	std::ofstream file("out.txt", std::fstream::out);
	if (file.is_open()) {
		file << std::endl;
		file.close();
	}
	else {
		throw std::exception("Could not open Logfile");
	}
}