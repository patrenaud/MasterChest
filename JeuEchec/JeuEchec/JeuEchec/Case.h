#pragma once
#include <vector>
#include <SDL_image.h>
#include <memory>
#include "Vector2.h"

class Piece;

class Case
{
public:
	Case(const int x, const int y, std::shared_ptr<Piece> aPiece = nullptr);
	~Case();

	SDL_Rect& GetRect() { return gCase; }
	std::shared_ptr<Piece>& GetPiece() { return gPiece; }
	std::shared_ptr<Vector2> GetOrigin() { return std::make_shared<Vector2>(XPos, YPos); }
	
	void Render(SDL_Surface* gScreenSurface);

	void Reset();
	
private:
	SDL_Rect gCase;
	int XPos;
	int YPos;

	std::shared_ptr<Piece> gPiece;

	

};

