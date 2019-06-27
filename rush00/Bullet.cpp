#include "Bullet.hpp"
#include "Enemy.hpp"
#include "StaticEntity.hpp"
#include <curses.h>
#include <sstream>

#define WHITE_PAIR 0
#define RED_PAIR 1
#define CYAN_PAIR 2

Bullet::Bullet(Vector pos, Vector dir, unsigned long speed, bool bPlayer, int color1, int color2)
{
	lastmove = 0;
	alive = true;
	this->bPlayer = bPlayer;
	this->position += pos += dir;
	this->dir = dir;
	speed /= 2;
	getmaxyx(stdscr, maxy, maxx);
	this->score = 0;
	this->shootSpeed = speed;
	this->foregroundColor = color1;
	this->backgroundColor = color2;
}

Bullet::Bullet()
{
}

Bullet::Bullet(const Bullet& bullet)
{
	*this = bullet;
}

Bullet::~Bullet()
{
	return;
}

Bullet &Bullet::operator=(const Bullet& bullet)
{
	if (this != &bullet)
	{
		GameEntity::operator=(bullet);
		this->dir = bullet.dir;
		this->position = bullet.position;
		this->score = bullet.score;
		this->shootSpeed = bullet.shootSpeed;
		this->maxx = bullet.maxx;
		this->maxy = bullet.maxy;
		this->foregroundColor = bullet.foregroundColor;
		this->backgroundColor = bullet.backgroundColor;
		this->bPlayer = bullet.bPlayer;
		this->bScore = bullet.bScore;
		this->alive = bullet.alive;
		this->lastmove = bullet.lastmove;
	}
	return *this;
}

void Bullet::tick(GameEntity ***entityPositionMap)
{
	getmaxyx(stdscr, checkYresize, checkXresize);

	if (checkYresize != maxy || checkXresize != maxx)
	{
		maxy = checkYresize;
		maxx = checkXresize;
	}

	if (clock() - lastmove > shootSpeed)
	{
		this->position += dir;
		lastmove = clock();
	}

	int y = position.getY();
	int x = position.getX();

	if (y < 0 || y >= maxy - 1) 
	{
		alive = false;
	}
	else if (x < 0 || x >= maxx - 1)
	{
		alive = false;
	}
	else if (alive && bPlayer && entityPositionMap[y][x])
	{
		bScore = true;
		this->score = entityPositionMap[y][x]->getScore();
		if (Enemy *e = dynamic_cast<Enemy *>(entityPositionMap[y][x]))
		{
			e->takeDamage();
			if (e->alive)
				bScore = false;
		}
		else if (StaticEntity *s = dynamic_cast<StaticEntity *>(entityPositionMap[y][x]))
			s->alive = false;
		this->alive = false;
	}
	else
	{
		int pair;
		if (foregroundColor == COLOR_RED)
			pair = RED_PAIR;
		else if (foregroundColor == COLOR_WHITE)
			pair = WHITE_PAIR;
		else
			pair = CYAN_PAIR;
		
    	attron(COLOR_PAIR(pair));
		mvaddch(y, x, '.');
		attroff(COLOR_PAIR(pair));
	}
}

bool Bullet::isAlive() const
{
	return alive;
}

bool Bullet::isScore() const
{
	return (bScore);
}
