#pragma once
#include <vector>
#include <SDL_image.h>

class Cases
{
public:
	std::vector<std::vector<SDL_Rect>> gCase;
	std::vector<std::vector<SDL_Surface*>> gPNGSurfacePiece;
	int XPos = 100;
	int YPos = 100;

	void Render(SDL_Surface* gScreenSurface);

	Cases();

	~Cases();
};

