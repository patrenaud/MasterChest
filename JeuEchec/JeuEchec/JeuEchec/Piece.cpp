#include "Piece.h"
#include <SDL_image.h>



Piece::Piece()
{	
}


Piece::~Piece()
{
	//Free loaded image
	SDL_FreeSurface(m_Texture);
	m_Texture = NULL;
}

void Piece::Render(SDL_Surface* gScreenSurface, SDL_Rect* Rect)
{
	SDL_BlitSurface(m_Texture, NULL, gScreenSurface, Rect);
}
