#ifndef DISKSHIP_H
#define DISKSHIP_H

#include "Enemy.hpp"

class DiskShip : public Enemy {
	public:
		DiskShip();
		~DiskShip();
		DiskShip(const DiskShip& f);
		DiskShip &operator=(const DiskShip& f);
		virtual void tick();
		virtual void shoot();

		virtual GameEntity *clone();
};

#endif