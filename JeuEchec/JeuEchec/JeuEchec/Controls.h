#pragma once
#include <memory>
#include <iostream>
#include <SDL.h>
#include <vector>

class Vector2;
class Board;
class Case;

class Controls
{
public:
	Controls();
	~Controls();
	
	const bool GetKingToMove() { return kingNeedToMove; }
	const std::vector<std::vector<std::shared_ptr<Vector2>>> GetEnemiesMoves() { return enemiesMoves; }

	bool m_WhitePlaying = true;
	void Update(const std::shared_ptr<Board>& board, SDL_Surface* screen);
	const std::shared_ptr<Case> &GetCurrentCase() { return _case; }
	//void CheckKingStatus(const std::shared_ptr<Board>& board);
	void SaveMove(std::shared_ptr<Case> _case, std::shared_ptr<Vector2> Pos);

private:
	
	// On déclare la variable du board
	std::shared_ptr<Case> _case = nullptr;

	//dans protected pour tester!
	//std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();

	std::vector<std::shared_ptr<Vector2>> CheckDanger = std::vector<std::shared_ptr<Vector2>>();
	std::vector<std::vector<std::shared_ptr<Vector2>>> enemiesMoves;

protected:
	bool kingNeedToMove = false;
	std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();
};

