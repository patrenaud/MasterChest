#include "Tour.h"
#include <SDL_image.h>


Tour::Tour(bool IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bTower.png") : IMG_Load("images/wTower.png");
}


Tour::~Tour()
{
}
