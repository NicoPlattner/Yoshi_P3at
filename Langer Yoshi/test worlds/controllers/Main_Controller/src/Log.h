#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Log {
protected:
	Log();
public:
	//static Log* getInstance();
	static void writeLog(std::string msg);
	static void emptyLog();
};