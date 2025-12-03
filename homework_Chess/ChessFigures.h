#ifndef CHESSFIGURES_H
#define CHESSFIGURES_H

// BASE CLASS
class ChessFigures
{
protected:
	char m_figure;

public:
	ChessFigures() = default;
	ChessFigures(char figure);
	virtual ~ChessFigures() = default;

public:
	virtual char getFigure() const = 0;
};

// Pawn
class Pawn : public ChessFigures
{
public:
	Pawn(char figure);
	char getFigure() const override;
};

// Bishop
class Bishop : public ChessFigures
{
public:
	Bishop(char figure);
	char getFigure() const override;
};

// Knight
class Knight : public ChessFigures
{
public:
	Knight(char figure);
	char getFigure() const override;
};

// Rook
class Rook : public ChessFigures
{
public:
	Rook(char figure);
	char getFigure() const override;
};

// Queen
class Queen : public ChessFigures
{
public:
	Queen(char figure);
	char getFigure() const override;
};

// King
class King : public ChessFigures
{
public:
	King(char figure);
	char getFigure() const override;
};
#endif // CHESSFIGURES_H