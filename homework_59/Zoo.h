#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"

class Zoo
{
public:
	Animal** arr;
	int size = 0;

public:
	Zoo(int size);
	Zoo(const Zoo& other) = delete;
	Zoo operator=(const Zoo& other) = delete;
	~Zoo();

public:
	void showVoice() const;
	void showInfo() const;
};

#endif // ZOO_H