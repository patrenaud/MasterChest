#include "Tour.h"
#include <SDL_image.h>
#include "Case.h"


Tour::Tour(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bTower.png") : IMG_Load("images/wTower.png");
}


Tour::~Tour()
{
}

std::vector<std::shared_ptr<Vector2>> Tour::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{	
	std::vector<std::shared_ptr<Vector2>>vec = {};
	for (int w = i-1; w >= 0; w--)
	{

		if (cases[w][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(w, j, true));
		}
		else 
		{
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[w][j]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(w, j, true));
				break;
			}
		}
	}
	for (int w = i+1; w <= 7; w++)
	{
		if (cases[w][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(w, j, true));
		}
		else
		{
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[w][j]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(w, j, true));
				break;
			}
		}
	}
	for (int w = j - 1; w >= 0; w--)
	{
		if (cases[i][w]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, w, true));
		}
		else
		{
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[i][w]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, w, true));
				break;
			}
		}
	}
	for (int w = j + 1; w <= 7; w++)
	{
		if (cases[i][w]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, w, true));
		}
		else
		{
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[i][w]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, w, true));
				break;
			}
		}
	}

	return vec;
}
