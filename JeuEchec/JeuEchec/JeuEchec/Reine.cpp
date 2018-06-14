#include "Reine.h"
#include <SDL_image.h>


Reine::Reine(bool IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bQueen.png") : IMG_Load("images/wQueen.png");
}


Reine::~Reine()
{
}
