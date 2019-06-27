#ifndef BULLET_H
#define BULLET_H

#include "GameEntity.hpp"

class Bullet : public GameEntity {
	public:
		Bullet(Vector pos, Vector dir, unsigned long speed, bool bPlayer, int color1, int color2);
		virtual ~Bullet();
		Bullet(const Bullet& f);
		Bullet &operator=(const Bullet& f);
		void tick(GameEntity ***entityPositionMap);
		bool isAlive() const;
		bool isScore() const;

	private:
		Bullet();
		void tick() { return; } // to make compile flags happy
		Vector dir;
		clock_t lastmove;
		bool alive;
		bool bScore;
		bool bPlayer;
		int maxy;
		int maxx;
		unsigned long shootSpeed;

		int foregroundColor;
		int backgroundColor;
		int checkXresize;
		int checkYresize;
};

#endif