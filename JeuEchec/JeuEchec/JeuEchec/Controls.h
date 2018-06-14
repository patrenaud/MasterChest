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

	void Update(const std::shared_ptr<Board>& board, SDL_Surface* screen);
	const std::shared_ptr<Case> &GetCurrentCase() { return _case; }
private:
	
	// On déclare la variable du board
	std::shared_ptr<Case> _case = nullptr;
	std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();
};

