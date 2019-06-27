#include "DiskShip.hpp"

DiskShip::DiskShip() : Enemy(1, 6)
{
	this->width = 8;
	this->height = 4;
	this->score = 25;
	this->health = 1;
}

DiskShip::DiskShip(const DiskShip& diskship) : Enemy(diskship)
{
}

DiskShip::~DiskShip()
{
	return;
}

DiskShip &DiskShip::operator=(const DiskShip& diskship)
{
	Enemy::operator=(diskship);
	return *this;
}

void DiskShip::tick()
{
	Enemy::tick();
	attron(COLOR_PAIR(1));
	std::string d1 = "  /-\\";
    std::string d2 = "O\\___/O";
	mvaddstr(position.getY(), position.getX(), d1.c_str());
	mvaddstr(position.getY() + 1, position.getX(), d2.c_str());
    attroff(COLOR_PAIR(1));
}

void DiskShip::shoot()
{
	lastShot = clock();
	int bulletsshot = -1;
	for (int i = 0; i < maxbullets; i++)
	{
		if (bullets[i] == nullptr)
		{
			// for bigger enemies it's nicer if bullet starts around the center rather than top left
			int bulletStartX = this->position.getX() + this->width / 2;
			int bulletStartY = this->position.getY() + this->height / 2;
			Vector dir(bulletsshot, 1);
			// pos, dir, speed, foreground color, background color
			bullets[i] = new Bullet(Vector(bulletStartX, bulletStartY), dir, 10000, false, COLOR_RED, COLOR_BLACK);
			bulletsshot++;
		}
		if (bulletsshot == 2)
			break;
	}
}

GameEntity * DiskShip::clone()
{
	return (new DiskShip(*this));
}