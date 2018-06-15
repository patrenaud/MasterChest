#include "Controls.h"
#include "Board.h"
#include "Case.h"
#include "Piece.h"
#include "Vector2.h"

Controls Turns;

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
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&y, &x);
			std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);

			if (Turns.m_WhitePlaying)
			{				
				_case = board->GetCase(Pos->GetI(), Pos->GetJ());

				if (_case->GetPiece() != nullptr && _case ->GetPiece()->GetColor() != true)
				{
					availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());
					int b = 0;
				}
			}
			else
			{	
				_case = board->GetCase(Pos->GetI(), Pos->GetJ());

				if (_case->GetPiece() != nullptr && _case->GetPiece()->GetColor())
				{
					availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());
					int b = 0;
				}
			}
		}

		if (e.type == SDL_MOUSEBUTTONUP)
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&y, &x);
			std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);

			for (int i = 0; i < availableMoves.size(); i++)
			{
				if (Pos->GetI() == availableMoves[i]->GetI() &&
					Pos->GetJ() == availableMoves[i]->GetJ())
				{
					Turns.m_WhitePlaying = !Turns.m_WhitePlaying; // Ceci sera pour le turnbased
					board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece() = _case->GetPiece();
					_case->GetPiece() = nullptr;					
				}
			}

			_case->Reset();
			_case = nullptr;
		}
	}
}
