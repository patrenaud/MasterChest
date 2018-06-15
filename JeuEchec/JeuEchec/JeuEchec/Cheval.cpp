#include "Cheval.h"
#include <SDL_image.h>


Cheval::Cheval(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bCavalier.png") : IMG_Load("images/wCavalier.png");
}


Cheval::~Cheval()
{
}

std::vector<std::shared_ptr<Vector2>> Cheval::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	return vec;
}
