#pragma once

#include <memory>
#include <vector>
#include <SDL.h>


class Piece	
{
public:
	Piece();
	~Piece();
	void Render(SDL_Surface* gScreenSurface);

	// Ici on doit avoir une VIRTUAL fonction pour le d�placement 
	// On doit aussi avoir un load de png pour render les Piece.


};

