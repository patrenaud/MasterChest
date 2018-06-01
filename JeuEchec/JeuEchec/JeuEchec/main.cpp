/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>

//Screen dimension constants
const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 750;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

SDL_Rect gBoard = { 50, 50, 650, 650 };

std::vector<std::vector<SDL_Rect>> gCase;

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//TO JETÉ
SDL_Surface* gPNGSurfaceTEST = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;
std::vector<std::vector<SDL_Surface*>> gPNGSurfacePiece;

bool init()
{
	int XPos = 50;
	int YPos = 50;
	for (int i = 0; i < 8; i++)
	{		
		gCase.push_back(std::vector<SDL_Rect>());		

		for (int j = 0; j < 8; j++)
		{
			gCase[i].push_back ({ XPos, YPos, 650/8, 650/8 });
			YPos += (650 / 8);
			if (YPos >= 700)
				YPos = 50;
		}
		XPos += (650 / 8);
	}

	//for (int i = 0; i < 8; i++)
	//{
	//	gPNGSurfacePiece[i].push_back;
	//	for (int j = 0; j < 8; j++)
	//	{
	//		//SDL_RenderDrawRect(renderer, &gCase[i][j]);
	//		gPNGSurfacePiece[i][j];
	//	}
	//}
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

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface("Chest2.png");
	if (gPNGSurface == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}
	gPNGSurfaceTEST = loadSurface("piecenoire.png");
	if (gPNGSurfaceTEST == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}
	
	//for (int i = 0; i < 8; i++)
	//{
	//	for (int j = 0; j < 8; j++)
	//	{
	//		//SDL_RenderDrawRect(renderer, &gCase[i][j]);
	//		SDL_BlitSurface(gPNGSurfacePiece, NULL, gScreenSurface, &gCase[i][j]);
	//	}
	//}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

//for (int i = 0; i < 8; i++)
//{
//	for (int j = 0; j < 8; j++)
//	{
//		//SDL_RenderDrawRect(renderer, &gCase[i][j]);
//		SDL_BlitSurface(gPNGSurfacePiece, NULL, gScreenSurface, &gCase[i][j]);
//	}
//}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

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
				}

				//Apply the PNG image
				SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, &gBoard);
				SDL_BlitSurface(gPNGSurfaceTEST, NULL, gScreenSurface, &gCase[0][0]);
			
				//for (int i = 0; i < 8; i++)
				//{
				//	for (int j = 0; j < 8; j++)
				//	{
				//		//SDL_RenderDrawRect(renderer, &gCase[i][j]);
				//		SDL_BlitSurface(gPNGSurfacePiece, NULL, gScreenSurface, &gCase[i][j]);
				//	}
				//}

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	system("pause");
	//Free resources and close SDL
	close();

	return 0;
}