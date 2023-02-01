#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

#include "Const.h"
#include "Drawing.h"
#include "Game.h"

sf::Texture King::texture[2];
sf::Texture Queen::texture[2];
sf::Texture Rook::texture[2];
sf::Texture Bishop::texture[2];
sf::Texture Knight::texture[2];
sf::Texture Pawn::texture[2];

int main()
{   
    Game game;
    sf::RenderWindow window(sf::VideoMode(SIZE*10, SIZE*10), "Chess");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            default:
                break;
            }
        }
        window.clear();
        game.draw(window);
        window.display();
    }
    return 0;
}