#include "Board.h"
#include "Const.h"

Board::Square::Square() : pID(0)
{
}

Board::Board(const std::string& dir, const sf::Color& color)
{
	if (!texture.loadFromFile(dir)) exit(0);
	sprite.setTexture(texture);
	sprite.setColor(color);
	sprite.setPosition(LEFT, TOP);
}

void Board::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}