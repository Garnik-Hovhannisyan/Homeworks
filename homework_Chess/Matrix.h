#ifndef MATRIX_H
#define MATRIX_H

template<typename T>

class Matrix
{
protected:
	int m_rows;
	int m_cols;
	T** m_matrix;

public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	Matrix(Matrix&& other);
	Matrix& operator=(Matrix&& other);
	virtual ~Matrix();

public:
	virtual void fill() = 0;
	virtual void print() = 0;

public:
	friend std::ostream& operator << (std::ostream& os, const Matrix<T>& mat);
};

#endif // MATRIX_H