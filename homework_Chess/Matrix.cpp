#include <iostream>
#include <ctime>

#include "matrix.h"

template<typename T>
Matrix<T>::Matrix() : m_rows(0), m_cols(0), m_matrix(nullptr)  {}

template<typename T>
Matrix<T>::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols)
{
    m_matrix = new T* [m_rows];

    for (int i = 0; i < m_rows; i++)
    {
        m_matrix[i] = new T[m_cols];
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) : m_rows(other.m_rows), m_cols(other.m_cols)
{   
    m_matrix = new T* [m_rows];

    for (int i = 0; i < m_rows; i++)
    {
        m_matrix[i] = new T[m_cols];
        for (int j = 0; j < m_cols; j++)
        {
            m_matrix[i][j] = other.m_matrix[i][j];
        }
    }
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
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

        m_matrix = new T* [m_rows];

        for (int i = 0; i < m_rows; i++)
        {
            m_matrix[i] = new T[m_cols];
            for (int j = 0; j < m_cols; j++)
            {
                m_matrix[i][j] = other.m_matrix[i][j];
            }
        }
    }
    return *this;
}

template<typename T>
Matrix<T>::Matrix(Matrix&& other) : m_rows(other.m_rows), m_cols(other.m_cols), m_matrix(other.m_matrix)
{
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_matrix = nullptr;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other)
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

template<typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < m_rows; i++)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Matrix<T>& mat)
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

template class Matrix<char>;