#ifndef ENEMY_H
#define ENEMY_H

#include "GameEntity.hpp"
#include "Bullet.hpp"
#include <curses.h>

class Enemy : public GameEntity {
	public:
		Enemy();
		Enemy(int speed);
		Enemy(int speed, int maxbullets);
		~Enemy();
		Enemy(const Enemy& f);
		Enemy &operator=(const Enemy& f);
		virtual void tick();
		virtual void shoot();
		virtual void takeDamage();

		virtual GameEntity *clone();

		void tickBullets(GameEntity ***);
		void emptyBullets();

	protected:
		int health;
		int maxbullets;
		unsigned long speed;
		clock_t lastMove;
		clock_t lastShot;
		Bullet *bullets[13];
};

#endif