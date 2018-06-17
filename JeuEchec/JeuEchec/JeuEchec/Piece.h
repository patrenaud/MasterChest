#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <SDL.h>
#include "Vector2.h"

class Case;


class Piece
{
public:
	enum PieceType
	{
		Pion = 0,
		Tour,
		Cheval,
		Reine,
		Fou,
		Roi

	};

	Piece(bool isBlack);
	Piece() {}
	~Piece();

	void Render(SDL_Surface* gScreenSurface, SDL_Rect* Rect);

	SDL_Surface* m_Texture;

	// Ici on doit avoir une VIRTUAL fonction pour le déplacement 
	const bool GetColor() { return isBlack; }

	const PieceType GetPieceType() { return m_Type; }

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
	{
		return std::vector<std::shared_ptr<Vector2>>();
	}

protected:


	bool isBlack;
	PieceType m_Type;
};

