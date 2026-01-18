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
	virtual std::string getType() const = 0;
	std::string getName() const;
	double getWeight() const;

	bool operator >(const Animal& other) const;
	bool operator <(const Animal& other) const;
	bool operator ==(const Animal& other) const;
};

struct AnimalComparator
{
	bool operator ()(const Animal* obj1, const Animal* obj2) const
	{
		return obj1->getWeight() < obj2->getWeight();
	}
};

struct AnimalHash
{
	size_t operator ()(const Animal* obj) const
	{
		return std::hash<std::string>()(obj->getName()) ^ std::hash<double>()(obj->getWeight());
	}
};

struct AnimalEqual
{
	bool operator ()(const Animal* obj1, const Animal* obj2) const
	{
		return obj1->getName() == obj2->getName() && obj1->getWeight() == obj2->getWeight();
	}
};

#endif // ANIMAL_H