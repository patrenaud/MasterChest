#pragma once
#include "Piece.h"
class Tour :
	public Piece
{
public:
	Tour() {}
	Tour(bool IsBlack);
	~Tour();

	virtual void Move() { std::cout << "tour" << std::endl; }	
};

