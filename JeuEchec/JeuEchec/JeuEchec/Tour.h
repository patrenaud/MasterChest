#pragma once
#include "Piece.h"
class Tour :
	public Piece
{
public:
	Tour() {}
	Tour(bool IsBlack);
	~Tour();


	// OVERRIDE fonction de déplacement
};

