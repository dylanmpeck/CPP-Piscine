#include "Asteroid.hpp"
#include <curses.h>

Asteroid::Asteroid() : StaticEntity(1)
{
	this->height = 3;
	this->width = 4;
	this->score = 10;
}

Asteroid::Asteroid(const Asteroid& asteroid) : StaticEntity(asteroid)
{
}

Asteroid::~Asteroid()
{
	return;
}

Asteroid &Asteroid::operator=(const Asteroid& asteroid)
{
	if (this != &asteroid)
		StaticEntity::operator=(asteroid);
	return *this;
}

void Asteroid::tick()
{
	StaticEntity::tick();
	std::string a1 = " *";
	std::string a2 = "***";
	mvaddstr(position.getY(), position.getX(), a1.c_str());
	mvaddstr(position.getY() + 1, position.getX(), a2.c_str());
	mvaddstr(position.getY() + 2, position.getX(), a1.c_str());
}

GameEntity * Asteroid::clone()
{
	return (new Asteroid(*this));
}