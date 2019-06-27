#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.hpp"
#include "Bullet.hpp"

class Player : public GameEntity {
	public:
		Player();
		Player(int playerNum);
		~Player();
		Player(const Player& f);
		Player &operator=(const Player& f);
		void handleInput(int ch);
		void shoot();
		void reset();
		void setDefaultPosition();
		virtual void tick(GameEntity ***entityPositionMap);
		bool isAlive();
		virtual int getScore();
		void emptyBullets();

	private:
		bool alive;
		int playerNum;
		int lives;
		int score;
		struct timespec ts;
		std::string gametime;
		std::string gamelives;
		std::string gamescore;

		Bullet *bullets[10];
		int lastshot;

		int curMaxX;
		int curMaxY;
		int checkXresize;
		int checkYresize;

		void tick() { return; } // to make compile flags happy
};

#endif