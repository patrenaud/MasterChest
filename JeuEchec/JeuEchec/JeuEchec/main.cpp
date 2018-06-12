/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Board.h"

//Screen dimension constants
const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 750;

//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

SDL_Rect gBoard = { 50, 50, 665, 665 };

std::vector<std::vector<SDL_Rect>> gCase;
std::vector<std::vector<SDL_Surface*>> gPNGSurfacePiece;

std::shared_ptr<Board> board;


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}

	int XPos = 50;
	int YPos = 50;
	for (int i = 0; i < 8; i++)
	{
		gCase.push_back(std::vector<SDL_Rect>());
		gPNGSurfacePiece.push_back(std::vector<SDL_Surface*>());
		for (int j = 0; j < 8; j++)
		{
			gPNGSurfacePiece[i].push_back(IMG_Load("pokemon.png"));
			gCase[i].push_back({ XPos, YPos, static_cast<int>(665 / 8), static_cast<int>(665 / 8) });
			YPos += (665 / 8);
		}
		YPos = 50;
		XPos += (665 / 8);
	}

	return success;
}



void close()
{


	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{

		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		// On déclare la variable du board
		board = std::make_shared<Board>();

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				if (e.type == SDL_MOUSEMOTION)
				{
					int x = 0;
					int y = 0;
					SDL_GetMouseState(&x, &y);
					std::cout << "x: " << x << "y: " << y << std::endl;
				}
			}

			board->Render(gScreenSurface);

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					//SDL_RenderDrawRect(renderer, &gCase[i][j]);
					SDL_BlitSurface(gPNGSurfacePiece[i][j], NULL, gScreenSurface, &gCase[i][j]);
				}
			}

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

		}
	}
	system("pause");
	//Free resources and close SDL
	close();

	return 0;
}