#ifndef MATRIX_H
#define MATRIX_H

#include "Car.h"

class Matrix
{
private:
	int rows;
	int cols;
	Car** matrix;

public:
	Matrix() = default;
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Car* operator[](int index);
	friend std::ostream& operator << (std::ostream& os, const Matrix& mat);
};
#endif // MATRIX_H