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

	void fill();
	void print();

	Matrix& operator++();
	Matrix operator++(int);
	Matrix operator*(const Matrix& other);
	Matrix rotate90();

	friend std::ostream& operator << (std::ostream& os, const Matrix& mat);
};

#endif // MATRIX_H