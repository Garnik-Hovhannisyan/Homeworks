#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"

class Zoo
{
public:
	Animal** arr;
	int size = 0;

public:
	Zoo() = default;
	Zoo(int size);
	Zoo(const Zoo& other);
	Zoo& operator=(const Zoo& other);
	Zoo(Zoo&& other);
	Zoo& operator=(Zoo&& other);
	~Zoo();

public:
	void showVoice() const;
	void showInfo() const;
};

#endif // ZOO_H