#include "Case.h"
#include "Piece.h"



Case::Case(const int x, const int y, std::shared_ptr<Piece> aPiece)
{
	gCase = { x, y, 100, 100 };
	gPiece = aPiece;
}


Case::~Case()
{
}

void Case::Render(SDL_Surface* gScreenSurface)
{
	if (gPiece != nullptr)
	{
		gPiece->Render(gScreenSurface, &gCase);
	}
}
