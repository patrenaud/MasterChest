#include "Pion.h"
#include <SDL_image.h>


Pion::Pion(bool IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bPion.png") : IMG_Load("images/wPion.png");
}


Pion::~Pion()
{
}
