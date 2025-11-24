#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
protected:
	int m_rows = 0;
	int m_cols = 0;
	char** m_matrix;

public:
	Matrix() = default;
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	Matrix(Matrix&& other);
	Matrix& operator=(Matrix&& other);
	virtual ~Matrix();

public:
	virtual void fill();
	virtual void print();

public:
	friend std::ostream& operator << (std::ostream& os, const Matrix& mat);
};

#endif // MATRIX_H