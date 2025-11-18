#include <iostream>
#include <fstream>

#include "matrix.h"
#include "logger.h"
#include "reader.h"
#include "matrix_logger.h"
#include "matrix_reader.h"

int main()
{
    Matrix mat(3, 3);
    Logger log(std::string("matrix.txt"));

    log << mat;

    Reader r1("matrix.txt");
    r1 >> mat;
    return 0;
}