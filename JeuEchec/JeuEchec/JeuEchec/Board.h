#pragma once
#include <memory>
#include <vector>
#include <SDL.h>

class Piece;


class Board
{
public:
	Board();
	~Board();
	void Render(SDL_Surface* gScreenSurface);

private:
	std::vector<std::shared_ptr<Piece>> Piece;
	// Main window
	SDL_Rect gBoard;
	//The surface contained by the window
	SDL_Surface* gPNGSurface = NULL;

};

