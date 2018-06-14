#include "Controls.h"
#include "Board.h"
#include "Case.h"
#include "Piece.h"


Controls::Controls()
{
}

Controls::~Controls()
{
}

void Controls::Update(const std::shared_ptr<Board>& board, SDL_Surface* screen)
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	if (_case != nullptr)
	{
		_case->Render(screen);
	}

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{

		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}

		//Control -> Update()

		if (e.type == SDL_MOUSEMOTION)
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);

			if (_case != nullptr)
			{
				_case->GetRect().x = x - 50;
				_case->GetRect().y = y - 50;
				_case->GetPiece()->Move();
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&y, &x);

			_case = board->GetCase((x - 100) / 100, (y - 100) / 100);
			std::cout << x / 100 << "  " << y / 100 << std::endl;
		}

		if (e.type == SDL_MOUSEBUTTONUP)
		{
			_case->Reset();
			_case = nullptr;
		}
	}
}
