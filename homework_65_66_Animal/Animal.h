#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
protected:
	std::string name;
	std::string color;
	int age;
	double weight;

public:
	Animal() = default;
	Animal(std::string name, std::string color, int age, double weight);
	Animal(const Animal& other) = default;
	Animal& operator =(const Animal& other) = default;
	virtual ~Animal() = default;

public:
	void eat() const;
	void sleep() const;
	virtual void info() const;
	virtual void voice() const = 0;
	virtual Animal* clone() const = 0;
};

#endif // ANIMAL_H