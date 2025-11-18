#ifndef READER_H
#define READER_H

#include <fstream>

class Reader
{
private:
	std::ifstream m_file;

public:
	Reader() = delete;
	Reader(const std::string& name);
	Reader(const Reader& other) = delete;
	Reader operator=(const Reader& other) = delete;
	~Reader();

	std::string read();
	friend class MatrixReader;
};

#endif // READER