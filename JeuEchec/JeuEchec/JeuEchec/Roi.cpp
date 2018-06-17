#include "Roi.h"
#include <SDL_image.h>
#include "Case.h"

Roi::Roi(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bKing.png") : IMG_Load("images/wKing.png");
	m_Type = PieceType::Roi;
}


Roi::~Roi()
{
}

std::vector<std::shared_ptr<Vector2>> Roi::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};

	bool myColor = cases[i][j]->GetPiece()->GetColor();

	if (i >= 1)
	{
		if (cases[i - 1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j, true));
		}
		else
		{
			bool destination = cases[i - 1][j]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 1, j, true));
			}
		}
	}

	if (i >= 1 && j >= 1)
	{
		if (cases[i - 1][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
		}
	}
	else
	{
		bool destination = cases[i - 1][j - 1]->GetPiece()->GetColor();
		if (myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
		}
	}

	if (i >= 1 && j <= 6)
	{
		if (cases[i - 1][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j + 1, true));
		}
		else
		{
			bool destination = cases[i - 1][j + 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 1, j + 1, true));
			}
		}
	}


	if (i <= 6)
	{
		if (cases[i + 1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
		}
		else
		{
			bool destination = cases[i - 1][j]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
			}
		}
	}

	if (i <= 6 && j >= 1)
	{
		if (cases[i + 1][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j - 1, true));
		}
		else
		{
			bool destination = cases[i + 1][j - 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j - 1, true));
			}
		}
	}

	if (i <= 6 && j <= 6)
	{
		if (cases[i + 1][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j + 1, true));
		}
		else
		{
			bool destination = cases[i + 1][j + 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j + 1, true));
			}
		}
	}


	if (j >= 1)
	{
		if (cases[i][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, j - 1, true));
		}
		else
		{
			bool destination = cases[i][j - 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, j - 1, true));
			}
		}
	}

	if (j <= 6)
	{
		if (cases[i][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, j + 1, true));
		}
		else
		{
			bool destination = cases[i][j + 1]->GetPiece()->GetColor();

			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, j + 1, true));
			}
		}
	}

	return vec;
}
