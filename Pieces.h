#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Board.h"

enum signedBool { black = -1, white = 1 };

class Piece
{
protected:
	sf::Sprite sprite;
	char x, y;
	
	void resetLocation();
public:
	const signedBool color;

	Piece(unsigned char = 0); // bxxxyyyc

	static void loadTexture(const std::string&);

	virtual void preMove(Board&) = 0;
	virtual void postMove(Board&) = 0;
	
	virtual bool isChecking(const char&, const char&) = 0;

	void mouseMove(sf::RenderWindow&);
	bool move(Board&);

	void draw(sf::RenderWindow&);
};

class King : public Piece 
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	King(unsigned char = 0);

	void preMove(Board&) override;
	void postMove(Board&) override;

	bool isChecking(const char&, const char&) override;

	friend class Piece;
};

class Queen : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Queen(unsigned char = 0);

	void preMove(Board&) override;
	void postMove(Board&) override;

	bool isChecking(const char&, const char&) override;

	friend class Piece;
};

class Rook : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Rook(unsigned char = 0);

	void preMove(Board&) override;
	void postMove(Board&) override;

	bool isChecking(const char&, const char&) override;

	friend class Piece;
	
};

class Bishop : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Bishop(unsigned char = 0);

	void preMove(Board&) override;
	void postMove(Board&) override;

	bool isChecking(const char&, const char&) override;

	friend class Piece;
};

class Knight : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Knight(unsigned char = 0);

	void preMove(Board&) override;
	void postMove(Board&) override;

	bool isChecking(const char&, const char&) override;

	friend class Piece;
};

class Pawn : public Piece
{
private:
	static sf::Texture texture[2];
	static void loadTexture(const std::string&);
public:
	Pawn(unsigned char = 0);

	void preMove(Board&) override;
	void postMove(Board&) override;

	bool isChecking(const char&, const char&) override;

	friend class Piece;
};