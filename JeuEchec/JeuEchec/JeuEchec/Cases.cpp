#include "Cases.h"



Cases::Cases()
{

	for (int i = 0; i < 8; i++)
	{
		gCase.push_back(std::vector<SDL_Rect>());
		gPNGSurfacePiece.push_back(std::vector<SDL_Surface*>());
		for (int j = 0; j < 8; j++)
		{
			gPNGSurfacePiece[i].push_back(IMG_Load("images/bPion.png")); // Ceci est la seule ligne importante pour appeler le load de la pièce.
			gCase[i].push_back({ XPos, YPos, static_cast<int>(100), static_cast<int>(100) });
			YPos += (100);
		}
		YPos = 100;
		XPos += (100);
	}
}


Cases::~Cases()
{
}

void Cases::Render(SDL_Surface* gScreenSurface)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//SDL_RenderDrawRect(renderer, &gCase[i][j]);
			SDL_BlitSurface(gPNGSurfacePiece[i][j], NULL, gScreenSurface, &gCase[i][j]);
		}
	}
}
