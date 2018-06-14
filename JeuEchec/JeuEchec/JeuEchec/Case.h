#pragma once
#include <vector>
#include <SDL_image.h>
#include <memory>

class Piece;

class Case
{
public:
	Case(const int x, const int y, std::shared_ptr<Piece> aPiece = nullptr);
	~Case();

	SDL_Rect& GetRect() { return gCase; }
	void Render(SDL_Surface* gScreenSurface);

	void Reset();

private:
	SDL_Rect gCase;
	int XPos;
	int YPos;

	std::shared_ptr<Piece> gPiece;

	

};

