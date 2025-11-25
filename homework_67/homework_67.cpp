#include <iostream>

class A
{
private:
    static int count;

public:
    A()
    {
        std::cout << "Call default constructor. " << std::endl;
        count++;
    }

    A(const A& other)
    {
        std::cout << "Call copy constructor. " << std::endl;
        count++;
    }
    A& operator=(const A& other) = default;

    ~A()
    {
        count--;
        std::cout << "Destructur called, Class A type objects - " << count << std::endl;
    }

    static int getCount()
    {
        return count;
    }
};

int A::count = 0;

int main()
{
    A obj;
    std::cout << "Class A type objects - " << A::getCount() << std::endl;
    A obj2;
    std::cout << "Class A type objects - " << A::getCount() << std::endl;
    A obj3;
    std::cout << "Class A type objects - " << A::getCount() << std::endl;

    return 0;
}