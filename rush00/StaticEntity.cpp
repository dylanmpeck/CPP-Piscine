#include "StaticEntity.hpp"

StaticEntity::StaticEntity()
{
	this->speed = 1;
	lastmove = 0;
}

StaticEntity::StaticEntity(int speed)
{
	this->speed = speed;
	lastmove = 0;
}

StaticEntity::StaticEntity(int speed, Vector & position)
{
	this->speed = speed;
	this->position = position;
}

StaticEntity::StaticEntity(const StaticEntity& staticentity)
{
	*this = staticentity;
}

StaticEntity::~StaticEntity()
{
	return;
}

StaticEntity &StaticEntity::operator=(const StaticEntity& staticentity)
{
	if (this != & staticentity)
	{
		GameEntity::operator=(staticentity);
		this->lastmove = staticentity.lastmove;
		this->speed = staticentity.speed;
	}
	return *this;
}

void StaticEntity::tick()
{
	if (clock() - lastmove > BASESPEED / speed)
	{
		lastmove = clock();
		this->position += Vector(0, 1);
	}
}

GameEntity * StaticEntity::clone()
{
	return (new StaticEntity(*this));
}

void StaticEntity::setSpeed(unsigned long speed) { this->speed = speed; }