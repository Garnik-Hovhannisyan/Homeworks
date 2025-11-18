#ifndef CAR_H
#define CAR_H

class Car
{
private:
	std::string brand;
	std::string model;
	int year;

public:
	Car();
	Car(std::string brand, std::string model, int year);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car() = default;

	friend std::ostream& operator << (std::ostream& os, const Car& car);
	friend class Matrix;
};

#endif // CAR_H