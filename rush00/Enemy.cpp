#include "Enemy.hpp"
#include <iostream>
#include <fstream>
#define BASESPEED 50000

Enemy::Enemy()
{
	this->health = 1;
	this->speed = 2;
	this->lastMove = clock();
	this->lastShot = clock();
	this->maxbullets = 10;

	for (int i = 0; i < maxbullets; i++)
		bullets[i] = nullptr;
}

Enemy::Enemy(int speed)
{
	this->health = 1;
	this->speed = speed * 2;
	this->lastMove = clock();
	this->lastShot = clock();
	this->maxbullets = 10;

	for (int i = 0; i < maxbullets; i++)
		bullets[i] = nullptr;
}

Enemy::Enemy(int speed, int maxbullets)
{
	this->health = 1;
	this->speed = speed * 2;
	this->lastMove = clock();
	this->lastShot = clock();
	this->maxbullets = maxbullets;

	for (int i = 0; i < maxbullets; i++)
		bullets[i] = nullptr;
}


Enemy::Enemy(const Enemy& enemy)
{
	*this = enemy;
}

Enemy::~Enemy()
{
	for (int i = 0; i < maxbullets; i++)
	{
		if (bullets[i])
		{
			delete bullets[i];
			bullets[i] = nullptr;
		}
	}
}

Enemy &Enemy::operator=(const Enemy& enemy)
{
	if (this != &enemy)
	{
		GameEntity::operator=(enemy);
		this->health = enemy.health;
		this->maxbullets = enemy.maxbullets;
		this->speed = enemy.speed;
		this->lastMove = enemy.lastMove;
		this->lastShot = enemy.lastShot;

		//don't want to copy bullets. new instance will begin creating its own bullets
		for (int i = 0; i < maxbullets; i++)
			bullets[i] = nullptr;
	}
	return *this;
}

void Enemy::tick()
{
	if (clock() - lastMove > BASESPEED / speed)
	{
		lastMove = clock();
		this->position += Vector(0, 1);
	}

	if (lastShot - clock() > BASESPEED * 2)
	{
		shoot();
	}
}

void Enemy::shoot()
{
	lastShot = clock();
	for (int i = 0; i < maxbullets; i++)
	{
		if (bullets[i] == nullptr)
		{
			// for bigger enemies it's nicer if bullet starts around the center rather than top left
			int bulletStartX = this->position.getX() + this->width / 2;
			int bulletStartY = this->position.getY() + this->height / 2;
			// pos, dir, speed, foreground color, background color
			bullets[i] = new Bullet(Vector(bulletStartX, bulletStartY), Vector(0, 1), 10000, false, COLOR_RED, COLOR_BLACK);
			break;
		}
	}
}

void Enemy::tickBullets(GameEntity ***entityPositionMap)
{
	for (int i = 0; i < maxbullets; i++)
	{
		if (bullets[i])
		{
			if (!bullets[i]->isAlive())
			{
				delete bullets[i];
				bullets[i] = nullptr;
			}
			else
			{
				bullets[i]->tick(entityPositionMap);
			}
		}
	}
}

void Enemy::takeDamage()
{
	this->health--;
	if (health <= 0)
		this->alive = false;
}

GameEntity * Enemy::clone()
{
	return (new Enemy(*this));
}

void Enemy::emptyBullets()
{
	for (int i = 0; i < maxbullets; i++)
	{
		if (bullets[i])
		{
			delete bullets[i];
			bullets[i] = nullptr;
		}
	}
}