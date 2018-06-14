#include "Piece.h"
#include <SDL_image.h>



Piece::Piece(bool IsBlack)
{	
	m_Texture = IsBlack ? IMG_Load("images/bPion.png") : IMG_Load("images/wPion.png");
}


Piece::~Piece()
{
}

void Piece::Render(SDL_Surface* gScreenSurface, SDL_Rect* Rect)
{
	SDL_BlitSurface(m_Texture, NULL, gScreenSurface, Rect);
}
