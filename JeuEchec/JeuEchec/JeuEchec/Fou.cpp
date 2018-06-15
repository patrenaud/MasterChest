#include "Fou.h"
#include <SDL_image.h>


Fou::Fou(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bFou.png") : IMG_Load("images/wFou.png");
}


Fou::~Fou()
{
}

std::vector<std::shared_ptr<Vector2>> Fou::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	return vec;
}
