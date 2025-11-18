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

    Matrix(const Matrix& other)
    {
        rows = other.rows;
        cols = other.cols;
		matrix = new int* [rows];

        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = other.matrix[i][j];
			}
        }
    }

    Matrix& operator=(const Matrix &other)
    {
        if (this != &other)
        {
            rows = other.rows;
			cols = other.cols;
            matrix = new int* [rows];

            for (int i = 0; i < rows; i++)
            {
                matrix[i] = new int[cols];
                for (int j = 0; j < cols; j++)
                {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
		return *this;
    }

    ~Matrix()
    {
		std::cout << "Base class destructor called." << std::endl;
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

    Matrix mat1(4,5);
    mat1.fill();
    mat1.print();
	std::cout << std::endl;

	Matrix mat2 = mat1;
	mat2.fill();
    mat2.print();

	return 0;
}
