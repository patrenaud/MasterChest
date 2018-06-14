#pragma once
#include "Piece.h"
class Fou :
	public Piece
{
public:
	Fou() {}
	Fou(bool IsBlack);
	~Fou();

	// OVERRIDE fonction de déplacement
};

