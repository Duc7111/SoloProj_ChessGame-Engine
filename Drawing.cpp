#include<SFML/Graphics.hpp>

#include "Drawing.h"
#include "Const.h" 


void Drawing::getBoardDrawing(const std::string& dir)
{
	sf::RenderTexture texture;
	texture.create(SIZE * 8, SIZE * 8);
	texture.clear();
	sf::RectangleShape square(sf::Vector2f(SIZE, SIZE));
	for(int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
		{
			if ((i + j) & 1)
				square.setFillColor(sf::Color(LSQUARE));
			else
				square.setFillColor(sf::Color(DSQUARE));
			square.setPosition(SIZE * j, SIZE * i);
			texture.draw(square);
		}
	texture.display();
	texture.getTexture().copyToImage().saveToFile(dir);
}

void Drawing::getPiecesDrawing(const std::string& dir)
{

}