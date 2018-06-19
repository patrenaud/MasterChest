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
	std::shared_ptr<Piece>& GetPiece() { return gPiece; }
	void SetHighlight(bool IsHighlight) { m_Highlight = IsHighlight; }

	void Render(SDL_Surface* gScreenSurface);

	void Reset();

private:
	SDL_Rect gCase;
	SDL_Surface* gContours;
	int XPos;
	int YPos;
	bool m_Highlight;
	std::shared_ptr<Piece> gPiece;

	

};

