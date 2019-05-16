#include "Log.h"

Log::Log()
{
}

Log * Log::getInstance()
{
	static Log instance;
	return &instance;
}

void Log::writeLog(std::string msg, std::string filepath, bool append)
{
	if (append) {
		std::ofstream file (filepath, std::fstream::out | std::fstream::app);
		if (file.is_open()) {
			file << msg << std::endl;
			file.close();
		}
		else {
			throw std::exception("Could not open Logfile");
		}
	}
	else {
		std::ofstream file(filepath, std::fstream::out);
		if (file.is_open()) {
			file << msg << std::endl;
			file.close();
		}
		else {
			throw std::exception("Could not open Logfile");
		}
	}
}

