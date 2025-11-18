#ifndef MATRIX_LOGGER_H
#define MATRIX_LOGGER_H

#include "matrix.h"
#include "logger.h"

class MatrixLogger
{
public:
	static void write(Logger& log, Matrix& mat);
};

Logger& operator<<(Logger& log, Matrix& mat);

#endif // MATRIX_LOGGER