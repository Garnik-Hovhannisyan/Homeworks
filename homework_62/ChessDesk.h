#ifndef CHESSDESK_H
#define CHESSDESK_H

#include "matrix.h"

class ChessDesk : public Matrix
{
public:
	ChessDesk();
	ChessDesk(const ChessDesk& other);
	ChessDesk& operator=(const ChessDesk& other);
	~ChessDesk() override {};

public:
	void print() override;
	void fill() override;
};

#endif // CHESSDESK