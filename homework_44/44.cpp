#include <iostream>
#include <string>
class Car
{
private:
	std::string m_brand;
	std::string m_model;
	std::string m_color;
	int m_year;
	int m_countDoors;
	bool m_engineStatus;

	void engineCheck()
	{
		std::cout << "Engine started." << std::endl;
	}

public:
	Car (std::string brand, std::string model, std::string color, int year, int countDoors)
	{
		m_brand = brand;
		m_model = model;
		m_color = color;
		m_year = year;
		m_countDoors = countDoors;
		m_engineStatus = false;
	}
	~Car() {}

	void engineOn()
	{
		engineCheck();
		m_engineStatus = true;
		std::cout << "Engine On." << std::endl;
	}

	void engineOff()
	{
		m_engineStatus = false;
		std::cout << "Engine Off." << std::endl;
	}

	void openDoors()
	{
		std::cout << "Doors Opened." << std::endl;
	}

	void honk()
	{
		std::cout << "Beeeep!" << std::endl;
	}

	void info()
	{
		std::cout << "\nCar Information: " << std::endl;
		std::cout << "Brand: " << m_brand << std::endl;
		std::cout << "Model: " << m_model << std::endl;
		std::cout << "Color: " << m_color << std::endl;
		std::cout << "Year: " << m_year << std::endl;
		std::cout << "Count of Doors: " << m_countDoors << std::endl;
	}
};

int main()
{
	Car car1("Nissan", "Versa", "Gray", 2021, 4);
	car1.engineOn();
	car1.openDoors();
	car1.honk();
	car1.engineOff();
	car1.info();

	return 0;
}
