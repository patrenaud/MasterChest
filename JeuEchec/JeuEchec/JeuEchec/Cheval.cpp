#include "Cheval.h"
#include <SDL_image.h>


Cheval::Cheval(bool IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bCavalier.png") : IMG_Load("images/wCavalier.png");
}


Cheval::~Cheval()
{
}
