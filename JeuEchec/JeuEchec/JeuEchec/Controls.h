#pragma once
#include <memory>
#include <iostream>
#include <SDL.h>

class Board;
class Case;

class Controls
{
public:
	Controls();
	~Controls();

	void Update(const std::shared_ptr<Board>& board);

private:
	
	// On déclare la variable du board
	std::shared_ptr<Case> _case = nullptr;
};

