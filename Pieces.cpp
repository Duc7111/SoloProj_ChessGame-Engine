#include "Pieces.h"
#include "Const.h"

sf::Vector2f lPos_pos(const unsigned char& x, const unsigned char& y)
{
	return sf::Vector2f(LEFT + SIZE / 2 + SIZE * x, TOP + SIZE / 2 + SIZE * y);
}

std::pair<unsigned char, unsigned char> pos_lPos(const sf::Vector2f& pos)
{
	unsigned x = (pos.x - LEFT - SIZE / 2) / SIZE;
	unsigned y = (pos.y - TOP - SIZE / 2) / SIZE;
	if (x > 7 || y > 7) return std::pair<unsigned char, unsigned char>(8, 8);
	return std::pair<unsigned char, unsigned char>(x, y);
}

void Piece::resetLocation()
{
	sprite.setPosition(lPos_pos(x, y));
}

Piece::Piece(unsigned char p) : color(p & 1), x(p >> 4), y((p >> 1)&7)
{
	sprite.setOrigin(SIZE/2, SIZE/2);
	sprite.setPosition(lPos_pos(x, y));
}

void Piece::loadTexture(const std::string& dir)
{
	King::loadTexture(dir);
	Queen::loadTexture(dir);
	Rook::loadTexture(dir);
	Bishop::loadTexture(dir);
	Knight::loadTexture(dir);
	Pawn::loadTexture(dir);
}

void Piece::mouseMove(sf::RenderWindow& window)
{
	sprite.setPosition((sf::Vector2f)sf::Mouse::getPosition(window));
}

void Piece::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void King::move(sf::RenderWindow& window)
{
	std::pair<unsigned char, unsigned char> lpos = pos_lPos(sprite.getPosition());
	if (lpos.first < 8 && (abs(lpos.first - x) == 1 || abs(lpos.second - x) == 1))
	{
		
	}
	resetLocation();
}

#define INIT (unsigned char c) : Piece(c)\
{sprite.setTexture(texture[color]);}

King::King INIT

Queen::Queen INIT

Rook::Rook INIT

Bishop::Bishop INIT

Knight::Knight INIT

Pawn::Pawn INIT

void King::loadTexture(const std::string& dir)
{
	for (int i = 0; i < 2; ++i)
		texture[i].loadFromFile(dir, sf::IntRect(0, i * SIZE, SIZE, SIZE));
}

void Queen::loadTexture(const std::string& dir)
{
	for (int i = 0; i < 2; ++i)
		texture[i].loadFromFile(dir, sf::IntRect(SIZE, i * SIZE, SIZE, SIZE));
}

void Rook::loadTexture(const std::string& dir)
{
	for (int i = 0; i < 2; ++i)
		texture[i].loadFromFile(dir, sf::IntRect(SIZE * 4, i * SIZE, SIZE, SIZE));
}

void Bishop::loadTexture(const std::string& dir)
{
	for (int i = 0; i < 2; ++i)
		texture[i].loadFromFile(dir, sf::IntRect(SIZE * 2, i * SIZE, SIZE, SIZE));
}

void Knight::loadTexture(const std::string& dir)
{
	for (int i = 0; i < 2; ++i)
		texture[i].loadFromFile(dir, sf::IntRect(SIZE * 3, i * SIZE, SIZE, SIZE));
}

void Pawn::loadTexture(const std::string& dir)
{
	for (int i = 0; i < 2; ++i)
		texture[i].loadFromFile(dir, sf::IntRect(SIZE * 5, i * SIZE, SIZE, SIZE));
}