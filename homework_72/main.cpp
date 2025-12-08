#include <iostream>

void print()
{
    std::cout << "End!!! \n";
}

template <typename T1, typename ... T2>
void print(T1 first, T2 ... last)
{
    std::cout << first << std::endl;
    print(last...);
}

int main()
{
    print(1, "Hi", '=', 0.99);

    return 0;
}