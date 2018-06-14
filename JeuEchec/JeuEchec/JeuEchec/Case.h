#pragma once
#include <vector>
#include <SDL_image.h>
#include <memory>

class Piece;

class Case
{
public:
	SDL_Rect gCase;
	int XPos = 100;
	int YPos = 100;


	std::shared_ptr<Piece> gPiece;

	void Render(SDL_Surface* gScreenSurface);

	Case(const int x,const int y, std::shared_ptr<Piece> aPiece = nullptr);

	~Case();
};

