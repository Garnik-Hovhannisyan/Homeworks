#include <iostream>

int main()
{
    auto f = [] (int x) 
    {
		return [x](int y)
        {
			return x * y;
        };
    };

    auto res = f(5)(6);
    std::cout << res << std::endl;

    return 0;
}