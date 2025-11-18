#include <iostream>
#include <ctime>

void my_malloc(size_t size, void** ptr)
{
	*ptr = malloc(size);
}

void* operator new[](size_t size)
{
	if (size == 0) size = 1;
	void* ptr = nullptr;
	my_malloc(size, &ptr);

	return ptr;
}

void operator delete[](void* ptr)
{	
	free(ptr);
}

int** ppmatrix(int x, int y)
{
	int** matrix = new int* [x];
	for (int i = 0; i < x; i++)
	{
		matrix[i] = new int[y];
	}
	return matrix;
}

void fillMatrix(int** matrix, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void printMatrix(int** arr, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

void deleteMatrix(int** matrix, int x)
{
	for (int i = 0; i < x; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main(int argc, char* argv[])
{
	srand(time(0));

	if(argc != 3)
	{
		std::cout << "Enter 2 arguments X Y!" << std::endl;
		return 1;
	}

	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	if (x <= 0 || y <= 0)
	{
		if (x <= 0)
		{
			std::cout << "X must be positive!" << std::endl;
		}
		if (y <= 0)
		{
			std::cout << "Y must be positive!" << std::endl;
		}		
		return 1;
	}

	int** matrix = ppmatrix(x, y);

	fillMatrix(matrix, x, y);
	printMatrix(matrix, x, y);
	deleteMatrix(matrix, x);

	return 0;
}