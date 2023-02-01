#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Piece
{
protected:
	sf::Sprite sprite;
	unsigned char x, y;
	
	void resetLocation();
public:
	const bool color;

	Piece(unsigned char = 0); // bxxxyyyc

	static void loadTexture(const std::string&);

	void mouseMove(sf::RenderWindow&);
	virtual void move(sf::RenderWindow&) = 0;

	void draw(sf::RenderWindow&);
};

class King : public Piece 
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	King(unsigned char = 0);

	void move(sf::RenderWindow&) override;

	friend class Piece;
};

class Queen : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Queen(unsigned char = 0);

	void move(sf::RenderWindow&) override;

	friend class Piece;
};

class Rook : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Rook(unsigned char = 0);

	void move(sf::RenderWindow&) override;

	friend class Piece;
	
};

class Bishop : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Bishop(unsigned char = 0);

	void move(sf::RenderWindow&) override;

	friend class Piece;
};

class Knight : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Knight(unsigned char = 0);

	void move(sf::RenderWindow&) override;

	friend class Piece;
};

class Pawn : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Pawn(unsigned char = 0);

	void move(sf::RenderWindow&) override;

	friend class Piece;
};