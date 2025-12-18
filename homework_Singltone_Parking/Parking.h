#ifndef PARKING_H
#define PARKING_H

#include "Car.h"

class Parking
{
private:
	int m_total;
	int m_occupied;
	static Parking* instance;

private:
	Parking(int total);

	Parking(const Parking& other) = delete;
	Parking& operator=(const Parking& other) = delete;

	Parking(Parking&& other) = delete;
	Parking& operator=(Parking&& other) = delete;
	
public:
	~Parking() = default;

	bool parkCar(const Car& car);
	void leaveCar(const Car& car);
	void info();

	static Parking& getInstance(int total);
};

#endif // PARKING_H