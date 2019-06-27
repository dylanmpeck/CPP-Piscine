#ifndef STATICENTITY_H
#define STATICENTITY_H

#include "GameEntity.hpp"

#define BASESPEED 2500

class StaticEntity : public GameEntity {
	public:
		StaticEntity(int speed);
		StaticEntity(int speed, Vector & position);
		~StaticEntity();
		StaticEntity(const StaticEntity& f);
		StaticEntity &operator=(const StaticEntity& f);
		void setSpeed(unsigned long speed);
		virtual void tick();

		virtual GameEntity *clone();

	protected:
		unsigned long speed;

	private:
		StaticEntity();
		clock_t lastmove;
};

#endif