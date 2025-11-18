#include <iostream>
#include <string>
#include <sstream>

#include "matrix_reader.h"
#include "matrix.h"
#include "reader.h"

void MatrixReader::read(Reader& r, Matrix& mat)
{
    std::cout << "MATRIX READER STARTED" << std::endl;

    if (!r.m_file.is_open()) 
    {
        std::cout << "Can't open file" << std::endl;
        return;
    }

    std::string str;
    int i = 0;

    while (std::getline(r.m_file, str) && i < mat.rows)
    {
        std::istringstream iss(str);
        for (int j = 0; j < mat.cols; j++)
        {
            if (!(iss >> mat.matrix[i][j]))
            {
                std::cout << "Reading error! " << std::endl;
                return;
            }
        }
        i++;
    }

    mat.print();
    std::cout << "MATRIX READER FINISHED" << std::endl;
}

Reader& operator>>(Reader& r, Matrix& mat)
{
    MatrixReader::read(r, mat);
    return r;
}