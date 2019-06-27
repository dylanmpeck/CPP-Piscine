#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.hpp"
#include <curses.h>

//#define MAXENEMIES 50
#define MAXENTITIES 15

class EnemyFactory {
	public:
		EnemyFactory();
		~EnemyFactory();
		EnemyFactory(const EnemyFactory& f);
		EnemyFactory &operator=(const EnemyFactory& f);
		void tick();

		void setEntityPositionMap(); // refreshes array to current positions. called in tick
		void resizeEntityPositionMap(); // array must be deleted and resized in case of terminal resize
		GameEntity ***getEntityPositionMap();
		bool colIsClear(int col, int width);
		void spawnBoss();

		void entityPositionMapDeepCopy(const EnemyFactory &);

	private:
		//Enemy *createEnemy();

		//using entities rather than enemies to include objects and player as well.
		GameEntity ***entityPositionMap;
		GameEntity *createdEntities[MAXENTITIES];
		bool *colChecks;
		bool bBoss;

		GameEntity *createEntity();

		int checkYresize;
		int checkXresize;
		int winHeight;
		int winWidth;
		clock_t lastFrame;

		//Enemy *enemies[MAXENEMIES];
};

#endif