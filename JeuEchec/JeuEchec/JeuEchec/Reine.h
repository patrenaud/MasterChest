#pragma once
#include "Piece.h"
class Reine :
	public Piece
{
public:
	Reine() {}
	Reine(bool IsBlack);
	~Reine();

	// OVERRIDE fonction de déplacement
};

