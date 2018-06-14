#pragma once
#include "Piece.h"
class Cheval :
	public Piece
{
public:
	Cheval() {};
	Cheval(bool IsBlack);
	~Cheval();

	// OVERRIDE fonction de déplacement
};

