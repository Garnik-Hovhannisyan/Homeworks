#include <iostream>

#include "logger.h"

Logger::Logger(const std::string& name)
{
	file.open(name);

	if (!file.is_open())
	{
		std::cout << "Can't open file" << std::endl;
	}
}

Logger& Logger::operator<<(const std::string& text)
{
	file << text;
	return* this;
}

Logger& Logger::operator<<(int text)
{
	file << text;
	return* this;
}

Logger& Logger::operator<<(char text)
{
	file << text;
	return* this;
}

Logger::~Logger()
{
	file.close();
}