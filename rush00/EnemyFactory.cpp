#include "EnemyFactory.hpp"
#include "Asteroid.hpp"
#include "DiskShip.hpp"
#include "Gaetan.hpp"
#include "DiamondShip.hpp"

EnemyFactory::EnemyFactory()
{
	bBoss = false;
	lastFrame = clock();

	for (int i = 0; i < MAXENTITIES; i++)
	{
		createdEntities[i] = nullptr;
	}

	getmaxyx(stdscr, winHeight, winWidth);

	entityPositionMap = new GameEntity**[winHeight];
	for (int i = 0; i < winHeight; i++)
	{
		entityPositionMap[i] = new GameEntity*[winWidth];
		for (int j = 0; j < winWidth; j++)
			entityPositionMap[i][j] = nullptr;
	}

	colChecks = new bool[winWidth];
	for (int i = 0; i < winWidth; i++)
		colChecks[i] = false;
}

EnemyFactory::EnemyFactory(const EnemyFactory& enemyfactory)
{
	*this = enemyfactory;
}

EnemyFactory::~EnemyFactory()
{
	for (int i = 0; i < MAXENTITIES; i++)
	{
		if (createdEntities[i])
		{
			delete createdEntities[i];
			createdEntities[i] = nullptr;
		}
	}

	for (int i = 0; i < winHeight; i++)
		delete [] entityPositionMap[i];
	delete [] entityPositionMap;
	delete [] colChecks;
}

EnemyFactory &EnemyFactory::operator=(const EnemyFactory& enemyfactory)
{
	if (this != &enemyfactory)
	{
		this->winHeight = enemyfactory.winHeight;
		this->winWidth = enemyfactory.winWidth;
		this->lastFrame = enemyfactory.lastFrame;
		this->bBoss = enemyfactory.bBoss;

		for (int i = 0; i < MAXENTITIES; i++)
		{
			if (enemyfactory.createdEntities[i])
				this->createdEntities[i] = enemyfactory.createdEntities[i]->clone();
			else
				createdEntities[i] = nullptr;
		}

		entityPositionMapDeepCopy(enemyfactory);

		colChecks = new bool[winWidth];
		for (int i = 0; i < winWidth; i++)
			colChecks[i] = enemyfactory.colChecks[i];
	}
	return *this;
}

void EnemyFactory::entityPositionMapDeepCopy(const EnemyFactory & enemyfactory)
{
	// double loop to create 2d array of pointers
	this->entityPositionMap = new GameEntity**[winHeight];
	for (int i = 0; i < winHeight; i++)
	{
		this->entityPositionMap[i] = new GameEntity*[winWidth];
		for (int j = 0; j < winWidth; j++)
		{
			if (enemyfactory.entityPositionMap[i][j])
			{
				// 3rd loop is used to make sure the new factory's map is pointing at its own entities
				for (int k = 0; k < MAXENTITIES; k++)
				{
					if (enemyfactory.createdEntities[k] == enemyfactory.entityPositionMap[i][j])
					{
						this->entityPositionMap[i][j] = this->createdEntities[k];
					}
				}
			}
			else
				entityPositionMap[i][j] = nullptr;
		}
	}
}

void EnemyFactory::tick()
{
	getmaxyx(stdscr, checkYresize, checkXresize);

	if (winHeight != checkYresize || winWidth != checkXresize)
		this->resizeEntityPositionMap();

	// maybe should be set after entities have ticked/moved?
	this->setEntityPositionMap();

	for (int i = 0; i < MAXENTITIES; i++)
	{
		if (createdEntities[i])
		{
			if (createdEntities[i]->getPos().getX() >= winWidth - 1 || createdEntities[i]->getPos().getY() >= winHeight - 1
				|| createdEntities[i]->alive == false)
			{
				int col = createdEntities[i]->getPos().getX();
				for (; col < winWidth && col < createdEntities[i]->getPos().getX() + createdEntities[i]->getWidth(); col++)
					colChecks[col] = false;
				delete createdEntities[i];
				createdEntities[i] = nullptr;
				if (bBoss)
					bBoss = false;
			}
			else
			{
				if (Enemy *enemy = dynamic_cast<Enemy *>(createdEntities[i])) // will return a null ptr/fail if not able to cast to enemy
					enemy->tickBullets(this->entityPositionMap);
			}
		}
		else if (clock() - lastFrame > 8000 && !bBoss)
		{
			lastFrame = clock();
			createdEntities[i] = createEntity();
		}
	}
	for (int i = 0; i < MAXENTITIES; i++)
	{
		if (createdEntities[i])
			createdEntities[i]->tick();
	}
}

GameEntity *EnemyFactory::createEntity()
{
	GameEntity *entity;
	int randEntity = rand() % 3;
	if (randEntity == 0)
		entity = new Asteroid;
	else if (randEntity == 1)
		entity = new DiamondShip;
	else
		entity = new DiskShip;
	
	int x = rand() % winWidth;
	int y = 0;

	entity->setPos(Vector(x, y).clamp(Vector(0, 0), Vector(winWidth, 0)));

	if (!colIsClear(x, entity->getWidth()))
	{
		delete entity;
		return (nullptr);
	}

	for (int i = x; i < winWidth && i < x + entity->getWidth(); i++)
		colChecks[i] = true;

	return entity;
}

void EnemyFactory::spawnBoss()
{
	bBoss = true;
	for (int i = 0; i < MAXENTITIES; i++)
	{
		if (createdEntities[i])
		{
			delete createdEntities[i];
			createdEntities[i] = nullptr;
		}
	}
	createdEntities[0] = new Gaetan();
	createdEntities[0]->setPos(Vector(0, 0));
}

void EnemyFactory::setEntityPositionMap()
{
	for (int i = 0; i < winHeight; i++)
	{
		for (int j = 0; j < winWidth; j++)
			entityPositionMap[i][j] = nullptr;	
	}

	for (int i = 0; i < MAXENTITIES; i++)
	{
		if (createdEntities[i] != NULL)
		{
			int y = createdEntities[i]->getPos().getY();
			int x = createdEntities[i]->getPos().getX();
			int heightBounds = createdEntities[i]->getHeight() + y;
			int widthBounds = createdEntities[i]->getWidth() + x;
			for (; y < heightBounds && y < winHeight - 1; y++)
			{
				for (; x < widthBounds && x < winWidth - 1; x++)
					entityPositionMap[y][x] = createdEntities[i];
			}
		}
	}
}

void EnemyFactory::resizeEntityPositionMap()
{
	for (int i = 0; i < winHeight; i++)
		delete [] entityPositionMap[i];
	delete [] entityPositionMap;

	double scaleXFactor = (double)checkXresize / (double)winWidth;
	double scaleYfactor = (double)checkYresize / (double)winHeight;

	getmaxyx(stdscr, winHeight, winWidth);

	entityPositionMap = new GameEntity**[winHeight];
	for (int i = 0; i < winHeight; i++)
	{
		entityPositionMap[i] = new GameEntity*[winWidth];
		for (int j = 0; j < winWidth; j++)
			entityPositionMap[i][j] = nullptr;
	}

	for (int i = 0; i < MAXENTITIES; i++)
	{
		if (createdEntities[i])
		{
			if (Enemy *e = dynamic_cast<Enemy *>(createdEntities[i]))
				e->emptyBullets();

			int y = createdEntities[i]->getPos().getY() * scaleYfactor;
			int x = createdEntities[i]->getPos().getX() * scaleXFactor;
			if (x < 0 || x > winWidth - 1 || y < 0 || y > winHeight - 1)
			{
				delete createdEntities[i];
				createdEntities[i] = nullptr;
			}
			else
			{
				createdEntities[i]->setPos(Vector(x, y));
				entityPositionMap[y][x] = createdEntities[i];
			}
		}
	}
}

GameEntity *** EnemyFactory::getEntityPositionMap() { return (this->entityPositionMap); }

bool EnemyFactory::colIsClear(int col, int width)
{
	for (int i = col; i < winWidth - 1 && i < col + width; i++)
	{
		if (colChecks[i] == true)
			return (false);
	}
	return (true);
}