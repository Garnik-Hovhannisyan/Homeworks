#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix = new Car* [rows];

    for (int i = 0; i < rows; i++)
    {
        this->matrix[i] = new Car[cols];
    }
}

Matrix::Matrix(const Matrix& other)
{
    this->rows = other.rows;
    this->cols = other.cols;
    this->matrix = new Car* [rows];

    for (int i = 0; i < rows; i++)
    {
        this->matrix[i] = new Car[cols];
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

        this->matrix = new Car* [this->rows];

        for (int i = 0; i < this->rows; i++)
        {
            this->matrix[i] = new Car[this->cols];
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

Car* Matrix::operator[](int index)
{
    return matrix[index];
}

std::ostream& operator << (std::ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            os << "Car info: ";
            os << mat.matrix[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}