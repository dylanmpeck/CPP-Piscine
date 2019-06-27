#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "Vector.hpp"

class GameEntity {
	public:
		GameEntity();
		GameEntity(Vector& pos);
		virtual ~GameEntity();
		GameEntity(const GameEntity& g);
		GameEntity &operator=(const GameEntity& rhs);
		Vector getPos() const;
		void setPos(Vector const &);
		Vector &translate(Vector &v);
		bool colliding(const GameEntity& g);
		virtual void tick();

		virtual GameEntity *clone();
		
		bool isAlive();
		bool alive;

		int getHeight();
		int getWidth();
		virtual int getScore();

	protected:
		int height;
		int width;
		int score;
		Vector position;

};

#endif