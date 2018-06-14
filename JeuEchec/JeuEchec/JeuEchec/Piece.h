#pragma once

#include <memory>
#include <vector>
#include <SDL.h>


class Piece	
{
public:
	Piece() {}
	Piece(bool IsBlack);
	~Piece();

	void Render(SDL_Surface* gScreenSurface, SDL_Rect* Rect);

	SDL_Surface* m_Texture;

	// Ici on doit avoir une VIRTUAL fonction pour le déplacement 
	// On doit aussi avoir un load de png pour render les Piece.


};

