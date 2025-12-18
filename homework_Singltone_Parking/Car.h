#ifndef CAR_H
#define CAR_H

#include "Engine.h"

class Car
{
protected:
	std::string m_brand;
	std::string m_model;
	int m_year;
	Engine m_engine;

public:
	Car();
	Car(std::string m_brand, std::string m_model, int m_year);
	Car(const Car& other) = delete;
	Car& operator=(const Car& other) = delete;
	~Car() = default;

public:
	void engineON();
	void engineOFF();
	void drive() const;
	void stop();
	virtual void info();
};

#endif //CAR