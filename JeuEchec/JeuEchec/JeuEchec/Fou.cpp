#include "Fou.h"
#include <SDL_image.h>


Fou::Fou(bool IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bFou.png") : IMG_Load("images/wFou.png");
}


Fou::~Fou()
{
}
