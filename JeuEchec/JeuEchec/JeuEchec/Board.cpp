#include "Board.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>



Board::Board()
{
	//Load PNG surface

	gPNGSurface = IMG_Load("images/ChestBoard.png");
	gBoard = { 100, 100, 1000, 1000 };

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