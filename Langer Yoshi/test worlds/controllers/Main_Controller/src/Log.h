#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Log {
protected:
	Log() = default;
public:
	static void writeLog(std::string msg);	//writes string into "out.txt" file into new line
	static void emptyLog();		//empties "out.txt" file
};