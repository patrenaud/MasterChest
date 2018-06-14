#include "Controls.h"
#include "Board.h"
#include "Case.h"



Controls::Controls()
{
}

Controls::~Controls()
{
}

void Controls::Update(const std::shared_ptr<Board>& board)
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;


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
				_case->GetRect().x = x;
				_case->GetRect().y = y;
			}

			//std::cout << "x: " << x << "y: " << y << std::endl;
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);

			_case = board->GetCase((x - 100) / 100, (y - 100) / 100);
			std::cout << x / 100 << "  " << y / 100 << std::endl;

			//Case->GetRect().x = 0;
			//Case->GetRect().y = 0;
		}

		if (e.type == SDL_MOUSEBUTTONUP)
		{
			_case->Reset();
			_case = nullptr;
		}
	}
}
