#pragma once
#include "Piece.h"
class Roi :
	public Piece
{
public:
	Roi() {}
	Roi(bool IsBlack);
	~Roi();

	// OVERRIDE fonction de déplacement
};

