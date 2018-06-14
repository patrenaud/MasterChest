#pragma once
#include "Piece.h"
class Pion :
	public Piece
{
public:
	Pion() {}
	Pion(bool IsBlack);
	~Pion();

	// OVERRIDE fonction de déplacement
};

