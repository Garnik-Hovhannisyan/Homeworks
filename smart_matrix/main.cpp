#include <iostream>
#include <ctime>

#include "smart_matrix.h"

int main()
{
	srand(time(0));

    try
    {
        SmartMatrix<int> mat(5, 8);
        mat.fillRandom();
        std::cout << "Matrix:" << std::endl;
        mat.print();

        SmartMatrix<int> emptyMat;
        emptyMat.print(); 
		std::cout << mat(8, 5) << std::endl; 
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    catch (const char* text)
    {
        std::cout << "Error: " << text << std::endl;
	}
    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
	}
    return 0;
}
