#include <iostream>

template <typename unsigned int T>
class Fibonacci
{
public:
    static const unsigned long long val = Fibonacci<T - 1>::val + Fibonacci<T - 2>::val;
};

template <>
class Fibonacci<0>
{
public:
	static const unsigned long long val = 0;
};

template <>
class Fibonacci<1>
{
public:
    static const unsigned long long val = 1;
};


int main()
{
    std::cout << "Fibonacci 10: " << Fibonacci<10>::val << std::endl;
}