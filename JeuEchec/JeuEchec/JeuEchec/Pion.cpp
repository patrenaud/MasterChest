#include "Pion.h"
#include <SDL_image.h>
#include "Case.h"

Pion::Pion(bool IsBlack)
	: Piece(isBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bPion.png") : IMG_Load("images/wPion.png");
}


Pion::~Pion()
{
}

std::vector<std::shared_ptr<Vector2>> Pion::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};

	bool isBlack = cases[i][j]->GetPiece()->GetColor();
	bool destination;

	if (!isBlack)
	{
		if (cases[i+1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i+1, j, true));
		}
		if (cases[i+1][j+1]->GetPiece() != nullptr)
		{
			destination = cases[i+1][j+1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i+1, j+1, true));
			}
		}
		if (cases[i+1][j-1]->GetPiece() != nullptr)
		{
			destination = cases[i+1][j-1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i+1, j-1, true));
			}
		}
	}
	if (isBlack)
	{
		if (cases[i-1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
		}
		if (cases[i-1][j-1]->GetPiece() != nullptr)
		{
			destination = cases[i-1][j-1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i-1, j-1 , true));
			}
		}
		if (cases[i-1][j+1]->GetPiece() != nullptr)
		{
			destination = cases[i-1][j+1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i-1, j+1, true));
			}
		}
	}

	return vec;
}
