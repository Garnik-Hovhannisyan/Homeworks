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

		fill();
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
            for (int i = 0; i < this->rows; i++)
            {
                delete[] matrix[i];
            }
			delete[] matrix;

            this->rows = other.rows;
			this->cols = other.cols;

            this->matrix = new int* [this->rows];

            for (int i = 0; i < this->rows; i++)
            {
                this->matrix[i] = new int[this->cols];
                for (int j = 0; j < this->cols; j++)
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

    Matrix rotate90()
    {
		Matrix rotated(this->cols, this->rows);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                rotated.matrix[j][this->rows - i - 1] = this->matrix[i][j];
            }
        }
		return rotated;
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

    Matrix operator++(int)
    {
        Matrix temp = *this;
		++(*this);
		return temp;
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

    friend std::ostream& operator << (std::ostream& os, const Matrix& mat);
};

std::ostream& operator << (std::ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            os << mat.matrix[i][j] << " ";
        }
		os << std::endl;
    }
    return os;
}

int main()
{
    srand((unsigned int)time(0));

    Matrix mat1(3,5);
	Matrix mat2 = mat1;
	
    std::cout << "Matrix:\n" << mat1 <<std::endl;
    std::cout << "Matrix after pre increment:\n" << ++mat2 << std::endl;
    mat2++;
    std::cout << "Matrix after post increment:\n" << mat2 << std::endl;
	std::cout << "Matrix rotated 90 degrees:\n" << mat2.rotate90() << std::endl;
	std::cout << "Matrix multiplication:\n" << mat1 * mat2.rotate90() << std::endl;

	return 0;
}
