#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
private:
	T* m_data;
	size_t m_size;

public:
	Vector() : m_data(nullptr), m_size(0)	{};

	Vector(int s) : m_size(s)
	{
		m_data = new T[s];
	}

	Vector(const Vector& other) : m_size(other.m_size)
	{
		m_data = new T[m_size];

		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
	}

	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			delete[] m_data;

			m_size = other.m_size;
			m_data = new T[m_size];
			
			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = other.m_data[i];
			}
		}
		return *this;
	}

	Vector(Vector&& other) : m_data(other.m_data), m_size(other.m_size)
	{
		other.m_data = nullptr;
		other.m_size = 0;
	}

	Vector& operator=(Vector&& other)
	{
		if (this != &other)
		{
			delete[] m_data;

			m_data = other.m_data;
			m_size = other.m_size;

			other.m_data = nullptr;
			other.m_size = 0;
		}
		return *this;
	}

	~Vector()
	{
		delete[] m_data;
	}
	
public:
	T& operator[](int index)
	{
		return m_data[index];
	}

	size_t size() const
	{
		return m_size;
	}
};

#endif // VECTOR_H