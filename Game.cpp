#include "Game.h"

Game::Game() : board("board.png"), side(true)
{
	Piece::loadTexture("Pieces_64.png");

	for (unsigned char i = 0; i < 8; ++i)
	{
		piece[0][i] = new Pawn((1 << 4) + (i << 1));
		piece[1][i] = new Pawn((6 << 4) + (i << 1) + 1);
	}

	piece[0][8] = new Rook(0);
	piece[0][15] = new Rook(7 << 1);
	piece[1][8] = new Rook((7 << 4) + 1);
	piece[1][15] = new Rook((7 << 4) + (7 << 1) + 1);

	piece[0][9] = new Knight(1 << 1);
	piece[0][14] = new Knight(6 << 1);
	piece[1][9] = new Knight((7 << 4) + (1 << 1) + 1);
	piece[1][14] = new Knight((7 << 4) + (6 << 1) + 1);

	piece[0][10] = new Bishop(2 << 1);
	piece[0][13] = new Bishop((5 << 1));
	piece[1][10] = new Bishop((7 << 4) + (2 << 1) + 1);
	piece[1][13] = new Bishop((7 << 4) + (5 << 1) + 1);

	piece[0][11] = new Queen(3 << 1);
	piece[0][12] = new King((4 << 1));
	piece[1][11] = new Queen((7 << 4) + (3 << 1) + 1);
	piece[1][12] = new King((7 << 4) + (4 << 1) + 1);
}

Game::~Game()
{
	for (unsigned char i = 0; i < 16; ++i)
	{
		delete piece[0][i], piece[1][i];
	}
}

void Game::play(sf::RenderWindow& window)
{
	while (window.isOpen())
	{

	}
}

void Game::draw(sf::RenderWindow& window)
{
	board.draw(window);
	for (unsigned char i = 0; i < 16; ++i)
	{
		piece[0][i]->draw(window);
		piece[1][i]->draw(window);
	}
}