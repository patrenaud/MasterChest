#include "Board.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>





Board::Board()
{
	//Load PNG surface
	gPNGSurface = IMG_Load("Chest2.png");
	gBoard = { 50, 50, 665, 665 };
}


Board::~Board()
{
	//Free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;
}

void Board::Render(SDL_Surface* gScreenSurface)
{
	//Apply the PNG image
	SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, &gBoard);
}