#include <iostream>

#include "matrix_logger.h"
#include "matrix.h"
#include "logger.h"

void MatrixLogger::write(Logger& log, Matrix& mat)
{
    for (int i = 0; i < mat.rows; ++i)
    {
        for (int j = 0; j < mat.cols - 1; ++j)
        {
            log << mat.matrix[i][j] << " ";
        }
        log << mat.matrix[i][mat.cols - 1];
        log << '\n';
    }
}

Logger& operator<<(Logger& log, Matrix& mat)
{
    MatrixLogger::write(log, mat);
    return log;
}