#ifndef DERIVED_H
#define DERIVED_H

#include "Car.h"

class Toyota : public Car
{
public:
	Toyota();
	Toyota(std::string m_model, int m_year);
	Toyota(const Car& other) = delete;
	Toyota& operator=(const Car& other) = delete;
	~Toyota() = default;

public:
	void info() override;
};

class Nissan : public Car
{
public:
	Nissan();
	Nissan(std::string m_model, int m_year);
	Nissan(const Car& other) = delete;
	Nissan& operator=(const Car& other) = delete;
	~Nissan() = default;

public:
	void info() override;
};

class Bmw : public Car
{
public:
	Bmw();
	Bmw(std::string m_model, int m_year);
	Bmw(const Car& other) = delete;
	Bmw& operator=(const Car& other) = delete;
	~Bmw() = default;

public:
	void info() override;
};

#endif // DERIVED