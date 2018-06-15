#include "Reine.h"
#include <SDL_image.h>


Reine::Reine(bool IsBlack)
	: Piece(isBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bQueen.png") : IMG_Load("images/wQueen.png");
}


Reine::~Reine()
{
}

std::vector<std::shared_ptr<Vector2>> Reine::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	return vec;
}
