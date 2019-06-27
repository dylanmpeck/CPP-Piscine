#include "GameEntity.hpp"

GameEntity::GameEntity() : alive(true)
{
	return;
}

GameEntity::GameEntity(Vector& pos) : alive(true)
{
	this->position = pos;
}

GameEntity::GameEntity(const GameEntity& gameentity)
{
	*this = gameentity;
}

GameEntity::~GameEntity()
{
	return;
}

GameEntity &GameEntity::operator=(const GameEntity& gameentity)
{
	if (this != &gameentity)
	{
		this->position = gameentity.position;
		this->height = gameentity.height;
		this->width = gameentity.width;
		this->score = gameentity.score;
		this->alive = gameentity.alive;
	}
	return *this;
}

Vector GameEntity::getPos() const
{
	return position;
}

Vector &GameEntity::translate(Vector &v)
{
	this->position += v;
	return this->position;
}

bool GameEntity::colliding(const GameEntity& g)
{
	if (this->getPos() == g.getPos())
		return true;
	else
		return false;
}

void GameEntity::tick()
{
	return;
}

GameEntity *GameEntity::clone()
{
	return (new GameEntity(*this));
}

void GameEntity::setPos(Vector const & position) { this->position = position; }

int GameEntity::getHeight() { return (this->height); }

int GameEntity::getWidth() { return (this->width); }

int GameEntity::getScore() { return (this->score); }