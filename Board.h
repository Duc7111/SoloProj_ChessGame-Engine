#pragma once

#include<SFML/Graphics.hpp>
#include <string>


class Board
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	class Square
	{
	public:
		char pID;
		bool moveAble;
		Square();
	}square[8][8];

	Board(const std::string&, const sf::Color& = sf::Color::White);

	void draw(sf::RenderWindow&);
};

