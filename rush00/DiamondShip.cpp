#include "DiamondShip.hpp"

DiamondShip::DiamondShip() : Enemy(1, 4)
{
	this->height = 8;
	this->width = 8;
	this->score = 20;
	this->health = 5;
}

DiamondShip::DiamondShip(const DiamondShip& DiamondShip) : Enemy(DiamondShip)
{
}

DiamondShip::~DiamondShip()
{
	return;
}

DiamondShip &DiamondShip::operator=(const DiamondShip& diamondShip)
{
	if (this != &diamondShip)
		Enemy::operator=(diamondShip);
	return *this;
}

void DiamondShip::tick()
{
	Enemy::tick();
    attron(COLOR_PAIR(1));
	std::string d1 = "  /o\\";
    std::string d2 = "o\\---/o";
	std::string d3 = "  \\O/";
	mvaddstr(position.getY(), position.getX(), d1.c_str());
	mvaddstr(position.getY() + 1, position.getX(), d2.c_str());
	mvaddstr(position.getY() + 2, position.getX(), d3.c_str());
    attroff(COLOR_PAIR(1));
}

GameEntity * DiamondShip::clone()
{
	return (new DiamondShip(*this));
}