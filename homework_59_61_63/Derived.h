#ifndef DERIVED_H
#define	DERIVED_H

#include "Animal.h"

class Dog : public Animal
{
private:
	std::string breed;
	bool trained;
	bool hungry;

public:
	Dog(std::string name, std::string color, int age, double weight, std::string breed, bool trained, bool hungry)
		: Animal(name, color, age, weight), breed(breed), trained(trained), hungry(hungry) {}

public:
	virtual void voice() const;
	void play();
	void follow();
	virtual void info() const;
};

class Cat : public Animal
{	
private:
	std::string eyeColor;
	bool hungry;
	bool loveMilk;

public:
	Cat(std::string name, std::string color, int age, double weight, std::string eyeColor, bool hungry, bool loveMilk)
		: Animal(name, color, age, weight), eyeColor(eyeColor), hungry(hungry), loveMilk(loveMilk) {}

public:
	virtual void voice() const;
	void scratch();
	virtual void info() const;
};

class Horse : public Animal
{
private:
	bool isRacing;
	int maxSpeed;

public:
	Horse(std::string name, std::string color, int age, double weight, bool isRacing, int maxSpeed)
		: Animal(name, color, age, weight), isRacing(isRacing), maxSpeed(maxSpeed){}

public:
	virtual void voice() const;
	void run();
	void rest();
	virtual void info() const;
};

class Bird : public Animal
{
private:
	std::string featherColor;
	bool canFly;

public:
	Bird(std::string name, std::string color, int age, double weight, std::string featherColor, bool canFly)
		: Animal(name, color, age, weight), featherColor(featherColor), canFly(canFly){ }

public:
	virtual void voice() const;
	void searchFood();
	void fly();
	virtual void info() const;
};

class Bear : public Animal
{
private:
	std::string variation;
	std::string furColor;

public:
	Bear(std::string name, std::string color, int age, double weight, std::string variation, std::string furColor)
		: Animal(name, color, age, weight), variation(variation), furColor(furColor){}

public:
	void hunt();
	virtual void voice() const;
	virtual void info() const;
};

class Lion : public Animal
{
private:
	bool leader;
	bool hungry;

public:
	Lion(std::string name, std::string color, int age, double weight, bool leader, bool hungry)
		: Animal(name, color, age, weight), leader(leader), hungry(hungry){}

public:
	void eatMeat();
	void fight();
	virtual void voice() const;
	virtual void info() const;
};

#endif // DERIVED_H