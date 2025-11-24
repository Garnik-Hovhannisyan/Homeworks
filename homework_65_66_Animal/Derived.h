#ifndef DERIVED_H
#define	DERIVED_H

#include "Animal.h"
#include "Amphibian.h"

// DOG
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
	void voice() const override;
	void play();
	void follow();
	void info() const override;
	Animal* clone() const override;
};
// CAT
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
	void voice() const override;
	void scratch();
	void info() const override;
	Animal* clone() const override;
};
// HORSE
class Horse : public Animal
{
private:
	bool isRacing;
	int maxSpeed;

public:
	Horse(std::string name, std::string color, int age, double weight, bool isRacing, int maxSpeed)
		: Animal(name, color, age, weight), isRacing(isRacing), maxSpeed(maxSpeed){}

public:
	void voice() const override;
	void run();
	void rest();
	void info() const override;
	Animal* clone() const override;
};
// BIRD
class Bird : public Animal
{
private:
	std::string featherColor;
	bool canFly;

public:
	Bird(std::string name, std::string color, int age, double weight, std::string featherColor, bool canFly)
		: Animal(name, color, age, weight), featherColor(featherColor), canFly(canFly){ }

public:
	void voice() const override;
	void searchFood();
	void fly();
	void info() const override;
	Animal* clone() const override;
};
// BEAR
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
	void voice() const override;
	void info() const override;
	Animal* clone() const override;
};
// LION
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
	void voice() const override;
	void info() const override;
	Animal* clone() const override;
};
// FROG
class Frog : public Animal, public Amphibian
{
private:
	bool poison;

public:
	Frog(std::string name, std::string color, int age, double weight, bool poison)
		: Animal(name, color, age, weight), poison(poison){}

public:
	void jump();
	void voice() const override; 
	void info() const override;
	Animal* clone() const override;
};

#endif // DERIVED_H