
#include <vector>

#include "Pieces.h"
#include "Const.h"


sf::Vector2f lPos_pos(const char& x, const char& y)
{
	return sf::Vector2f(LEFT + SIZE / 2 + SIZE * x, TOP + SIZE / 2 + SIZE * y);
}

std::pair<char, char> pos_lPos(const sf::Vector2f& pos)
{
	char x = (pos.x - LEFT - SIZE / 2) / SIZE;
	char y = (pos.y - TOP - SIZE / 2) / SIZE;
	if (x < 0 || y < 0 || x > 7 || y > 7) return std::pair<char, char>(-1, -1);
	return std::pair<char, char>(x, y);
}

void Piece::resetLocation()
{
	sprite.setPosition(lPos_pos(x, y));
}

Piece::Piece(unsigned char p) : color((p & 1) ? black : white), x(p >> 4), y((p >> 1)&7)
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

bool Piece::move(Board& board)
{
	bool moved = false;
	std::pair<char, char> lpos = pos_lPos(sprite.getPosition());
	if (lpos.first != -1 && board.square[x][y].moveAble)
	{
		postMove(board);
		x = lpos.first;
		y = lpos.second;
		moved = true;
	}
	resetLocation();
	return moved;
}

void King::preMove(Board& board)
{
	std::vector<char> a, b;
	switch (x)
	{
	case 0:
		a = { 1 };
		break;
	case 7:
		a = { -1 };
		break;
	default:
		a = { -1, 1 };
	}
	switch (y)
	{
	case 0:
		b = { 1 };
		break;
	case 7:
		b = { -1 };
		break;
	default:
		b = { -1, 1 };
	}
	for (char i : a)
	{
		board.square[i][0].moveAble = true;
		for (char j : b) board.square[i][j].moveAble = true;
	}
	for (char j : b) board.square[0][j].moveAble = true;
}

void King::postMove(Board& board)
{
	std::vector<char> a, b;
	switch (x)
	{
	case 0:
		a = { 1 };
		break;
	case 7:
		a = { -1 };
		break;
	default:
		a = { -1, 1 };
	}
	switch (y)
	{
	case 0:
		b = { 1 };
		break;
	case 7:
		b = { -1 };
		break;
	default:
		b = { -1, 1 };
	}
	for (char i : a)
	{
		board.square[i][0].moveAble = false;
		for (char j : b) board.square[i][j].moveAble = false;
	}
	for (char j : b) board.square[0][j].moveAble = false;
}

bool King::isChecking(const char& a, const char& b)
{
	return (abs(a - x) <= 1) && (abs(b - y) <= 1);
}

void Queen::preMove(Board& board)
{
	int i = x, j = y;
	while (++i < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (--i > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (++j < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	j = y;
	while (--j > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (++i < 8 && ++j < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (++i < 8 && --j > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && ++j < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && --j > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
}

void Queen::postMove(Board& board)
{
	int i = x, j = y;
	while (++i < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (--i > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (++j < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	j = y;
	while (--j > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (++i < 8 && ++j < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (++i < 8 && --j > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && ++j < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && --j > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
}

bool Queen::isChecking(const char& a, const char& b)
{
	return (a == x) || (b == y) || (abs(a - x) == abs(b - y));
}

void Rook::preMove(Board& board)
{
	int i = x, j = y;
	while (++i < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (--i > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (++j < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	j = y;
	while (--j > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
}

void Rook::postMove(Board& board)
{
	int i = x, j = y;
	while (++i < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (--i > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x;
	while (++j < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	j = y;
	while (--j > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
}

bool Rook::isChecking(const char& a, const char& b)
{
	return (a == x) || (b == y);
}

void Bishop::preMove(Board& board)
{
	int i = x, j = y;
	while (++i < 8 && ++j < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (++i < 8 && --j > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && ++j < 8)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && --j > 0)
	{
		char temp = board.square[i][j].pID * color;
		if (temp <= 0)
			board.square[i][j].moveAble = true;
		if (temp < 0 || temp > 0) break;
	}
}

void Bishop::postMove(Board& board)
{
	int i = x, j = y;
	while (++i < 8 && ++j < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (++i < 8 && --j > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && ++j < 8)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
	i = x, j = y;
	while (--i > 0 && --j > 0)
	{
		board.square[i][j].moveAble = true;
		char temp = board.square[i][j].pID * color;
		if (temp < 0 || temp > 0) break;
	}
}

bool Bishop::isChecking(const char& a, const char& b)
{
	return abs(a - x) == abs(b - y);
}

void Knight::preMove(Board& board)
{
	if (x + 2 < 8 && y + 1 < 8) board.square[x + 2][y + 1].moveAble = true;
	if (x + 2 < 8 && y - 1 < 8) board.square[x + 2][y - 1].moveAble = true;
	if (x - 2 < 8 && y + 1 < 8) board.square[x - 2][y + 1].moveAble = true;
	if (x - 2 < 8 && y + 1 < 8) board.square[x - 2][y - 1].moveAble = true;
	if (x + 1 < 8 && y + 2 < 8) board.square[x + 1][y + 2].moveAble = true;
	if (x + 1 < 8 && y - 2 < 8) board.square[x + 1][y - 2].moveAble = true;
	if (x - 1 < 8 && y + 2 < 8) board.square[x - 1][y + 2].moveAble = true;
	if (x - 1 < 8 && y - 2 < 8) board.square[x - 1][y - 2].moveAble = true;
}

void Knight::postMove(Board& board)
{
	if (x + 2 < 8 && y + 1 < 8) board.square[x + 2][y + 1].moveAble = false;
	if (x + 2 < 8 && y - 1 < 8) board.square[x + 2][y - 1].moveAble = false;
	if (x - 2 < 8 && y + 1 < 8) board.square[x - 2][y + 1].moveAble = false;
	if (x - 2 < 8 && y + 1 < 8) board.square[x - 2][y - 1].moveAble = false;
	if (x + 1 < 8 && y + 2 < 8) board.square[x + 1][y + 2].moveAble = false;
	if (x + 1 < 8 && y - 2 < 8) board.square[x + 1][y - 2].moveAble = false;
	if (x - 1 < 8 && y + 2 < 8) board.square[x - 1][y + 2].moveAble = false;
	if (x - 1 < 8 && y - 2 < 8) board.square[x - 1][y - 2].moveAble = false;
}

bool Knight::isChecking(const char& a, const char& b)
{
	return ((abs(a - x) == 2 && abs(b - y) == 1) || (abs(a - x) == 1 && abs(b - y) == 2));
}

void Pawn::preMove(Board& board)
{
	char pos = color + y;
	if (board.square[x][pos].pID == 0) board.square[x][pos].moveAble = true;
	for (char i : {-1, 1})
	{
		if (x + i < 0 || x + i > 7) continue;
		if (board.square[x + i][pos].pID * color < 0) board.square[x + i][pos].moveAble = true;
	}
}

void Pawn::postMove(Board& board)
{
	char pos = color + y;
	board.square[x][pos].moveAble = false;
	for (char i : {-1, 1})
	{
		if (x + i < 0 || x + i > 7) continue;
		board.square[x + i][pos].moveAble = false;
	}
}

bool Pawn::isChecking(const char& a, const char& b)
{
	return (abs(a - x) == 1) && (b - y == color);
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