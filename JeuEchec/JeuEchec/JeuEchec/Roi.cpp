#include "Roi.h"
#include <SDL_image.h>


Roi::Roi(bool IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bKing.png") : IMG_Load("images/wKing.png");
}


Roi::~Roi()
{
}
