#include <iostream>
#include <ctime>

class Matrix
{
private:
    int rows;
    int cols;
    int** matrix;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
		matrix = new int* [rows];

        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
		}
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
		delete[] matrix;
    }

    void fill()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
				matrix[i][j] = rand() % 10;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
	}
};

int main()
{
    srand(time(0));

    Matrix mat(4,5);
    mat.fill();
    mat.print();

	return 0;
}
