#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
	int rows;
	int cols;
	int** matrix;

public:
	Matrix() = default;
	Matrix(int rows, int cols);	
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

public:
	void fill();
	void print();
	Matrix& operator++();
	Matrix operator++(int);
	Matrix operator*(const Matrix& other);
	Matrix rotate90();

public:
	friend std::ostream& operator << (std::ostream& os, const Matrix& mat);
	friend class MatrixLogger;
};

#endif // MATRIX_H