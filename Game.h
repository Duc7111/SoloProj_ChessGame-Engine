#pragma once

#include "Board.h"
#include "Pieces.h"

class Game
{
private:
	Board board;
	bool side;
	Piece* piece[2][16];
public:
	Game();
	~Game();

	void play(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
};

