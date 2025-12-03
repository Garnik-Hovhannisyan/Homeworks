#include <iostream>

#include "ChessDesk.h"

const int deskCols = 8;
const int deskRows = 8;

ChessDesk::ChessDesk() : Matrix(deskRows, deskCols) {}

ChessDesk::ChessDesk(const ChessDesk& other) : Matrix (other) {}

ChessDesk& ChessDesk::operator=(const ChessDesk& other)
{
    if (this != &other)
    {
        Matrix::operator=(other);
    }
    return *this;
}

ChessDesk::ChessDesk(ChessDesk&& other) : Matrix (std::move(other)) {}

ChessDesk& ChessDesk::operator=(ChessDesk&& other)
{
    if (this != &other)
    {
		Matrix::operator=(std::move(other));   
    }
    return *this;
}

void ChessDesk::print()
{
    for (int i = 0; i < deskRows; i++)
    {
        std::cout << deskRows - i << " ";
        for (int j = 0; j < deskCols; j++)
        {
            std::cout << m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "  ";
    
    for (int i = 0; i < deskRows; i++)
    {
        std::cout << char('a' + i) << " ";
    }
}

void ChessDesk::fill()
{
    for (int i = 0; i < deskRows; i++)
    {
        for (int j = 0; j < deskCols; j++)
        {
            m_matrix[i][j] = '_';
        }
    }
}