#include <iostream>
#include "matrix.h"

Matrix::Matrix(int rows, int cols)
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

Matrix::Matrix(const Matrix& other)
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

Matrix& Matrix::operator=(const Matrix& other)
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

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::fill()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

void Matrix::print()
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

Matrix& Matrix::operator++()
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

Matrix Matrix::operator++(int)
{
    Matrix temp = *this;
    ++(*this);
    return temp;
}

Matrix Matrix::operator*(const Matrix& other)
{
    Matrix temp(0, 0);

    if (this->cols == other.rows)
    {
        temp = Matrix(this->rows, other.cols);

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

Matrix Matrix::rotate90()
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