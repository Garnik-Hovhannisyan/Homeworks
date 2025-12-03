#ifndef CHESSDESK_H
#define CHESSDESK_H

#include "matrix.h"

class ChessDesk : public Matrix<char>
{
public:
	ChessDesk();
	ChessDesk(const ChessDesk& other);
	ChessDesk& operator=(const ChessDesk& other);
	ChessDesk(ChessDesk&& other);
	ChessDesk& operator=(ChessDesk&& other);
	~ChessDesk() override {};

public:
	void print() override;
	void fill() override;
};

#endif // CHESSDESK_H