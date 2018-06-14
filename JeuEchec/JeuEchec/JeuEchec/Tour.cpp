#include "Tour.h"
#include <SDL_image.h>
#include "Case.h"



Tour::Tour(bool IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bTower.png") : IMG_Load("images/wTower.png");
}


Tour::~Tour()
{
}

std::vector<std::shared_ptr<Vector2>> Tour::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	//if (cases[i][j]->GetPiece == nullptr)
	
	std::vector<std::shared_ptr<Vector2>>vec = {};

	vec.push_back(std::make_shared<Vector2>(0, 1, true));
	vec.push_back(std::make_shared<Vector2>(0, 2, true));
	vec.push_back(std::make_shared<Vector2>(2, 0, true));
	
	return vec;
}
