#ifndef ASTEROID_H
#define ASTEROID_H

#include "StaticEntity.hpp"

class Asteroid : public StaticEntity {
	public:
		Asteroid();
		~Asteroid();
		Asteroid(const Asteroid& f);
		Asteroid &operator=(const Asteroid& f);
		virtual void tick();

		virtual GameEntity *clone();
};

#endif