#include "Controls.h"
#include "Board.h"
#include "Case.h"
#include "Piece.h"
#include "Vector2.h"
#include "Roi.h"

Controls Turns;
bool KingNeedsToMove = false;

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

			/*if (KingNeedsToMove = false)
			{*/
			if (Turns.m_WhitePlaying) // Ce bool est pour générer le TurnBased du jeu
			{
				_case = board->GetCase(Pos->GetI(), Pos->GetJ());
				// Need to find a Piece and it has to be the right color depending on turn
				if (_case->GetPiece() != nullptr && _case->GetPiece()->GetColor() != true)
				{
					availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());
				}
			}
			else
			{
				_case = board->GetCase(Pos->GetI(), Pos->GetJ());

				if (_case->GetPiece() != nullptr && _case->GetPiece()->GetColor())
				{
					availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());
				}
			}
			/*}
			else
			{
				if (Turns.m_WhitePlaying) // Ce bool est pour générer le TurnBased du jeu
				{
					_case = board->GetCase(Pos->GetI(), Pos->GetJ());
					// Can only move the white King
					if (_case->GetPiece() != nullptr && _case->GetPiece()->GetColor() != true && _case->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());
					}
				}
				else
				{
					// Can only move the black King
					if (_case->GetPiece() != nullptr && _case->GetPiece()->GetColor() && _case->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());
					}
				}
			}*/
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
					Turns.m_WhitePlaying = !Turns.m_WhitePlaying; // When a piece is dropped to another spot, the player's turn is done (bool)
					board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece() = _case->GetPiece();
					if (_case->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						KingNeedsToMove = false;
					}
					_case->GetPiece() = nullptr;
					CheckKingStatus(board);

				}

			}

			_case->Reset();
			_case = nullptr;
		}
	}
}

void CheckKingStatus(const std::shared_ptr<Board>& board)
{
	int x = 0;
	int y = 0;
	SDL_GetMouseState(&y, &x);
	std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
	Controls CheckWin;

	std::vector<std::shared_ptr<Vector2>> CheckDanger = CheckWin.GetCurrentCase()->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());

	for (int i = 0; i < CheckDanger.size(); i++)
	{
		// m_case crée la liste des mouvement de la nouvelle position de la pièce bougée
		std::shared_ptr<Case> m_case = board->GetCase(CheckDanger[i]->GetI(), CheckDanger[i]->GetJ());

		if ((m_case->GetPiece()->GetPieceType() == Piece::PieceType::Roi) && m_case->GetPiece()->GetColor())
		{
			KingNeedsToMove = true;
			break;
		}
		else if ((m_case->GetPiece()->GetPieceType() == Piece::PieceType::Roi) && m_case->GetPiece()->GetColor() == false)
		{
			KingNeedsToMove = true;
			break;
		}
	}
}
