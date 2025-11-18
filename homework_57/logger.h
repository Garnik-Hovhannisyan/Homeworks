#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>

class Logger
{
private:
	std::ofstream file;

public:
	Logger() = delete;
	Logger(const std::string& name);
	Logger(const Logger& other) = delete;
	Logger& operator=(Logger& other) = delete;
	~Logger();

	Logger& operator<<(const std::string& text);
	Logger& operator<<(int text);
	Logger& operator<<(char text);
};

#endif // LOGGER_H