#include "ChessFigures.h"

// BASE CLASS CHESSFIGURES
ChessFigures::ChessFigures(char figure) : m_figure(figure)	{}

// Pawn
Pawn::Pawn(char figure) : ChessFigures(figure)	{}

char Pawn::getFigure() const {return m_figure;}

// Bishop
Bishop::Bishop(char figure) : ChessFigures(figure)	{}

char Bishop::getFigure() const { return m_figure;}

// Knight
Knight::Knight(char figure) : ChessFigures(figure) {}

char Knight::getFigure() const { return m_figure; }

// Rook
Rook::Rook(char figure) : ChessFigures(figure) {}

char Rook::getFigure() const { return m_figure; }

// Queen 
Queen::Queen(char figure) : ChessFigures(figure) {}

char Queen::getFigure() const { return m_figure; }

// King
King::King(char figure) : ChessFigures(figure) {}

char King::getFigure() const { return m_figure; }