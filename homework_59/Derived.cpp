#include <iostream>

#include "Derived.h"
#include "Animal.h"

//DOG
void Dog::voice() const
{
	std::cout << name << " says: haf!" << std::endl;
}

void Dog::play()
{
	std::cout << name << " playing with toy" << std::endl;
}

void Dog::follow()
{
	std::cout << name << " following owner" << std::endl;
}

void Dog::info() const
{
	std::cout << "Dog information:" << std::endl;
	Animal::info();
	std::cout << "Breed - " << breed << std::endl;
	std::cout << "Trained - " << (trained ? "Yes" : "NO") << std::endl;
	std::cout << "Hungry - " << (hungry ? "Yes" : "NO") << std::endl;
	std::cout << "---------\n";
}
//CAT
void Cat::voice() const
{
	std::cout << name << " says: meow!" << std::endl;
}

void Cat::scratch()
{
	std::cout << name << " scratch" << std::endl;
}

void Cat::info() const
{
	std::cout << "Cat information:" << std::endl;
	Animal::info();
	std::cout << "Eye Color - " << eyeColor << std::endl;
	std::cout << "Hungry - " << (hungry ? "Yes" : "NO") << std::endl;
	std::cout << "Love Milk - " << (loveMilk ? "Yes" : "NO") << std::endl;
	std::cout << "---------\n";
}
// HORSE
void Horse::voice() const
{
	std::cout << name << " says: neigh" << std::endl;
}

void Horse::run()
{
	std::cout << name << " is running" << std::endl;
}

void Horse::rest()
{
	std::cout << name << " .rest." << std::endl;
}

void Horse::info() const
{
	std::cout << "Horse information:" << std::endl;
	Animal::info();
	std::cout << "Is Racing - " << (isRacing ? "Yes" : "NO") << std::endl;
	std::cout << "Max Speed - " << maxSpeed << std::endl;
	std::cout << "---------\n";
}
//BIRD
void Bird::voice() const
{
	std::cout << name << " says: dzen!" << std::endl;
}

void Bird::searchFood()
{
	std::cout << name << " searching food" << std::endl;
}

void Bird::fly()
{
	if (canFly)
	{
		std::cout << name << " flying" << std::endl;
	}
	else 
	{
		std::cout << name << " cant fly" << std::endl;
	}
}

void Bird::info() const
{
	std::cout << "Bird information:" << std::endl;
	Animal::info();
	std::cout << "Can Fly - " << (canFly ? "Yes" : "NO") << std::endl;
	std::cout << "Feather Color - " << featherColor << std::endl;
	std::cout << "---------\n";
}
//BEAR
void Bear::hunt()
{
	std::cout << name << " is hunting" << std::endl;
}

void Bear::voice() const
{
	std::cout << name << " says: GRRRR!" << std::endl;
}
 
void Bear::info() const
{
	std::cout << "Bird information:" << std::endl;
	Animal::info();
	std::cout << "Fur Color - " << furColor << std::endl;
	std::cout << "Variation - " << variation << std::endl;
	std::cout << "---------\n";
}
//LION
void Lion::eatMeat()
{
	std::cout << name << " eating meat" << std::endl;
}

void Lion::fight()
{
	if (leader)
	{
		std::cout << name << " fighting for pride" << std::endl;
	}
	else 
	{
		std::cout << name << " fighting for survive" << std::endl;
	}	
}

void Lion::voice() const
{
	std::cout << name << " says: ROARRRR!" << std::endl;
}

void Lion::info() const
{
	std::cout << "Bird information:" << std::endl;
	Animal::info();
	std::cout << "Pride Leader - " << (leader ? "Yes" : "NO") << std::endl;
	std::cout << "Hungry - " << (hungry ? "Yes" : "NO") << std::endl;
	std::cout << "---------\n";
}