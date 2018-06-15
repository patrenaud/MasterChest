#include "Roi.h"
#include <SDL_image.h>


Roi::Roi(bool IsBlack)
	: Piece(isBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bKing.png") : IMG_Load("images/wKing.png");
}


Roi::~Roi()
{
}

std::vector<std::shared_ptr<Vector2>> Roi::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	return vec;
}
