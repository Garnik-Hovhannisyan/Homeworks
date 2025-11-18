#ifndef MATRIXREADER_H
#define MATRIXREADER_H

#include "matrix.h"
#include "reader.h"

class MatrixReader
{
public:
	static void read(Reader& r, Matrix& mat);
};

Reader& operator>>(Reader& r, Matrix& mat);

#endif // MATRIXREADER