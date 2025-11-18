#include <iostream>
#include <string>

class Car
{
private:
	std::string m_brand;
	std::string m_model;

public:
	Car(std::string brand, std::string model)
	{
		m_brand = brand;
		m_model = model;
	}

	Car(const Car& other)
	{
		m_brand = other.m_brand;
		m_model = other.m_model;
	}

	Car& operator=(const Car& other)
	{
		if (this != &other)
		{
			this->m_brand = other.m_brand;
			this->m_model = other.m_model;
		}
		return *this;
	}

	~Car() {}

	void info()
	{
		std::cout << "\nCar Information: " << std::endl;
		std::cout << "Brand: " << m_brand << std::endl;
		std::cout << "Model: " << m_model << std::endl;
	}

};

class Parking 
{
private:
	int m_total;
	int m_occupied;

public:
	Parking(int total)
	{
		m_total = total;
		m_occupied = 0;
	}

	Parking(const Parking& other)
	{
		m_total = other.m_total;
		m_occupied = other.m_occupied;
	}

	Parking& operator=(const Parking& other)
	{
		if (this != &other)
		{
			this->m_total = other.m_total;
			this->m_occupied = other.m_occupied;
		}
		return *this;
	}

	~Parking() 
	{
		std::cout << "\nBase destructor called." << std::endl;
	}

	bool parkCar(const Car& car)
	{
		if (m_occupied < m_total)
		{
			m_occupied++;
			std::cout << "Car parked successfully." << std::endl;
			return true;
		}
		else
		{
			std::cout << "Parking is full." << std::endl;
			return false;
		}
	}

	void leaveCar(const Car& car)
	{
		if (m_occupied > 0)
		{
			m_occupied--;
			std::cout << "Car left the parking." << std::endl;
		}
		else
		{
			std::cout << "No cars in the parking." << std::endl;
		}
	}

	void info()
	{
		std::cout << "\nParking Information: " << std::endl;
		std::cout << "Total spots: " << m_total << std::endl;
		std::cout << "Occupied spots: " << m_occupied << std::endl;
	}
};

int main()
{
	Parking park(10);

	Car car1("Nissan", "Versa");
	Car car2("Audi", "A4");
	Car car3 = car2;

	park.parkCar(car1);
	park.leaveCar(car1);

	park.parkCar(car2);
	park.parkCar(car3);

	park.info();
}
