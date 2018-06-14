#include "Piece.h"
#include <SDL_image.h>



Piece::Piece()
{	
}


Piece::~Piece()
{
}

void Piece::Render(SDL_Surface* gScreenSurface, SDL_Rect* Rect)
{
	SDL_BlitSurface(m_Texture, NULL, gScreenSurface, Rect);
}
