#include <iostream>
#include <ctime>

#include "matrix.h"

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols)
{
    m_matrix = new char* [m_rows];

    for (int i = 0; i < m_rows; i++)
    {
        m_matrix[i] = new char[m_cols];
    }

    fill();
}

Matrix::Matrix(const Matrix& other) : m_rows(other.m_rows), m_cols(other.m_cols)
{   
    m_matrix = new char* [m_rows];

    for (int i = 0; i < m_rows; i++)
    {
        m_matrix[i] = new char[m_cols];
        for (int j = 0; j < m_cols; j++)
        {
            m_matrix[i][j] = other.m_matrix[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        for (int i = 0; i < m_rows; i++)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;

        m_rows = other.m_rows;
        m_cols = other.m_cols;

        m_matrix = new char* [m_rows];

        for (int i = 0; i < m_rows; i++)
        {
            m_matrix[i] = new char[m_cols];
            for (int j = 0; j < m_cols; j++)
            {
                m_matrix[i][j] = other.m_matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix::Matrix(Matrix&& other) : m_rows(other.m_rows), m_cols(other.m_cols), m_matrix(other.m_matrix)
{
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_matrix = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other)
{
    if (this != &other)
    {
        for (int i = 0; i < m_rows; i++)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;

        m_rows = other.m_rows;
        m_cols = other.m_cols;
		m_matrix = other.m_matrix;

        other.m_rows = 0;
        other.m_cols = 0;
		other.m_matrix = nullptr;
    }
    return *this;
}

Matrix::~Matrix()
{
    for (int i = 0; i < m_rows; i++)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

void Matrix::fill()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_matrix[i][j] = ' ';
        }
    }
}

void Matrix::print()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            std::cout << m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::ostream& operator << (std::ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat.m_rows; i++)
    {
        for (int j = 0; j < mat.m_cols; j++)
        {
            os << mat.m_matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}