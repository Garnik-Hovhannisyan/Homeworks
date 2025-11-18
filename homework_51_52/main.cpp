#include <iostream>
#include <ctime>

class Matrix
{
private:
    int rows;
    int cols;
    int** matrix;

public:
    Matrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
		this->matrix = new int* [rows];
		
        for (int i = 0; i < rows; i++)
        {
            this->matrix[i] = new int[cols];
		}
    }

    Matrix(const Matrix& other)
    {
        this->rows = other.rows;
        this->cols = other.cols;
		this->matrix = new int* [rows];

        for (int i = 0; i < rows; i++)
        {
            this->matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                this->matrix[i][j] = other.matrix[i][j];
			}
        }
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] matrix[i];
            }
			delete[] matrix;

            this->rows = other.rows;
			this->cols = other.cols;
            this->matrix = new int* [rows];

            for (int i = 0; i < rows; i++)
            {
                this->matrix[i] = new int[cols];
                for (int j = 0; j < cols; j++)
                {
                    this->matrix[i][j] = other.matrix[i][j];
                }
            }
        }
		return *this;
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

    void rotate90(Matrix* mat)
    {
		int rows = mat->rows;
		int cols = mat->cols;

		int** rotated = new int* [cols];
        for (int i = 0; i < cols; i++)
        {
            rotated[i] = new int[rows];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                rotated[j][rows - i - 1] = mat->matrix[i][j];
            }
        }

        for (int i = 0; i < rows; i++)
        {
            delete[] mat->matrix[i];
        }
		delete[] mat->matrix;

		mat->matrix = rotated;
		mat->cols = rows;
		mat->rows = cols;
    }

    Matrix& operator++()
    {
		
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] += 1;
            }
        }
		return *this;
    }

    Matrix operator*(const Matrix& other)
    {
		Matrix temp(0, 0);

        if (this->cols == other.rows)
        {
            temp = Matrix (this->rows, other.cols);

            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < other.cols; j++)
                {
                    temp.matrix[i][j] = 0;
                    for (int k = 0; k < this->cols; k++)
                    {
                        temp.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
                    }
                }
            }  
        }
        else
        {
            std::cout << "Can't multiply. Sizes don't match!" << std::endl;
        }

		return temp;
    }
};

int main()
{
    srand((unsigned int)time(0));

    Matrix mat1(3,5);
    mat1.fill();
	std::cout << "Matrix:" << std::endl;
    mat1.print();

	Matrix mat2 = mat1;
    ++mat2;
	std::cout << "\nIncrement Matrix:" << std::endl;
	mat2.print();
    
	mat2.rotate90(&mat2);
	std::cout << "\nRotate Matrix:" << std::endl;
	mat2.print();

    Matrix mat3 = mat1 * mat2;
	std::cout << "\nMultiply Matrix:" << std::endl;	
    mat3.print();

	return 0;
}
