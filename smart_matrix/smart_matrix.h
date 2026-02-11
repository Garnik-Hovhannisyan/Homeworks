#ifndef SMART_MATRIX_H
#define SMART_MATRIX_H

#include <memory>

template<typename T>
class SmartMatrix
{
private:
	std::unique_ptr<std::unique_ptr<T[]>[]> m_data;
	size_t m_rows;
	size_t m_cols;

public:
	SmartMatrix() : m_data(nullptr), m_rows(0), m_cols(0) {}

	SmartMatrix(size_t row, size_t col) : m_data(std::make_unique<std::unique_ptr<T[]>[]>(row)), m_rows(row), m_cols(col)
	{
		for (size_t i = 0; i < row; i++)
		{
			m_data[i] = std::make_unique<T[]>(col);
		}
	}

	SmartMatrix(const SmartMatrix& other) = delete;
	SmartMatrix& operator=(const SmartMatrix& other) = delete;

	SmartMatrix(SmartMatrix&& other) noexcept : m_data(std::move(other.m_data)), m_rows(other.m_rows), m_cols(other.m_cols) 
	{
		other.m_rows = 0;
		other.m_cols = 0;
	}

	SmartMatrix& operator= (SmartMatrix&& other) noexcept
	{
		if (this != & other)
		{
			m_data = std::move(other.m_data);
			m_rows = other.m_rows;
			m_cols = other.m_cols;

			other.m_rows = 0;
			other.m_cols = 0;
		}

		return *this;
	}

	~SmartMatrix() = default;

public:
	size_t rows() const { return m_rows; }
	size_t cols() const { return m_cols; }
	
	T& operator()(size_t x, size_t y)
	{
		if (x >= m_rows || y >= m_cols) throw std::exception("Index Error");
		return m_data[x][y];
	}

	const T& operator()(size_t x, size_t y) const
	{
		if (x >= m_rows || y >= m_cols) throw std::exception("Index Error");
		return m_data[x][y];
	}

	void print() const
	{
		if (!m_data) throw "Matrix is empty, print()";

		for (size_t i = 0; i < m_rows; ++i)
		{
			for (size_t j = 0; j < m_cols; ++j)
			{
				std::cout << m_data[i][j] << " ";
			}

			std::cout << std::endl;
		}
	}

	void fillRandom()
	{
		if (!m_data) throw "Matrix is empty, fillRandom()";

		for (size_t i = 0; i < m_rows; ++i)
		{
			for (size_t j = 0; j < m_cols; ++j)
			{
				m_data[i][j] = rand() % 10;
			}
		}
	}
};


#endif // SMART_MATRIX_H