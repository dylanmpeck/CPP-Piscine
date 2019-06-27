#include "Player.hpp"
#include <curses.h>
#include <sstream>

#define MAXBULLETS 10

Player::Player()
{
	getmaxyx(stdscr, curMaxY, curMaxX);
	playerNum = 0;
	setDefaultPosition();
	this->lives = 5;
	this->alive = true;
	this->score = 0;
	clock_gettime(CLOCK_REALTIME, &ts);
	for (int i = 0; i < MAXBULLETS; i++)
	{
		bullets[i] = nullptr;
	}
}

Player::Player(int player)
{
	this->lives = 5;
	this->alive = true;
	this->score = 0;
	playerNum = player;
	clock_gettime(CLOCK_REALTIME, &ts);
	for (int i = 0; i < MAXBULLETS; i++)
	{
		bullets[i] = nullptr;
	}
	setDefaultPosition();
}

Player::Player(const Player& player)
{
	*this = player;
}

Player::~Player()
{
	for (int i = 0; i < MAXBULLETS; i++)
	{
		if (bullets[i])
		{
			delete bullets[i];
			bullets[i] = nullptr;
		}
	}
}

Player &Player::operator=(const Player& player)
{
	if (this != &player)
	{
		GameEntity::operator=(player);
		this->alive = player.alive;
		this->playerNum = player.playerNum;
		this->score = player.score;
		this->lives = player.lives;
		this->ts = player.ts;
		this->gamelives = player.gamelives;
		this->gametime = player.gametime;
		this->gamescore = player.gamescore;
		this->lastshot = player.lastshot;

		//dont want to copy bullets. new instance would create its own
		for (int i = 0; i < MAXBULLETS; i++)
			this->bullets[i] = nullptr;
	}
	return *this;
}

void Player::handleInput(int ch)
{
	if (ch != -1)
	{
		if (playerNum == 0 || playerNum == 1)
		{
			if (ch == 's')
				position += Vector(0, 1);
			if (ch == 'w')
				position += Vector(0, -1);
			if (ch == 'a')
				position += Vector(-1, 0);
			if (ch == 'd')
				position += Vector(1, 0);
			if (ch == ' ')
				shoot();
		}
		if (playerNum == 0 || playerNum == 2)
		{
			if (ch == KEY_DOWN)
				position += Vector(0, 1);
			if (ch == KEY_UP)
				position += Vector(0, -1);
			if (ch == KEY_LEFT)
				position += Vector(-1, 0);
			if (ch == KEY_RIGHT)
				position += Vector(1, 0);
			if (ch == '\n')
				shoot();
		}
		if (playerNum == 0)
		{
			if (ch == ' ')
				shoot();
		}
		position.clamp(Vector(0, 0), Vector(getmaxx(stdscr) - 1, getmaxy(stdscr) - 2));
	}
}

void Player::tick(GameEntity ***entityPositionMap)
{
	getmaxyx(stdscr, checkYresize, checkXresize);

	if (checkYresize != curMaxY || checkXresize != curMaxX)
	{
		double scaleYFactor = (double)checkYresize / (double)curMaxY;
		double scaleXFactor = (double)checkXresize / (double)curMaxX;
		int x = this->getPos().getX();
		int y = this->getPos().getY();
		this->setPos(Vector(x * scaleXFactor, y * scaleYFactor));
		curMaxX = checkXresize;
		curMaxY = checkYresize;
		this->emptyBullets();
	}

	char c = A_CHARTEXT & mvinch(position.getY(), position.getX());
	if (c != ' ')
		reset();

	if (playerNum == 2)
		attron(COLOR_PAIR(4));
	else
		attron(COLOR_PAIR(3));
	mvaddch(position.getY(), position.getX(), 'I');
	attroff(COLOR_PAIR(3));
	std::stringstream ss;
	struct timespec newtime;
	clock_gettime(CLOCK_REALTIME, &newtime);
	int secs = (newtime.tv_sec - ts.tv_sec);
	ss << "Lives: " << lives << " | ";
	ss << "Score: " << score << " | ";
	ss << "Time: " << secs / 60 << "m" << secs % 60 << "s" << std::endl;
	if (playerNum == 1 || playerNum == 0)
		mvaddstr(getmaxy(stdscr) - 1, 0, ss.str().c_str());
	else
		mvaddstr(getmaxy(stdscr) - 1, getmaxx(stdscr) - strlen(ss.str().c_str()), ss.str().c_str());
	for (int i = 0; i < MAXBULLETS; i++)
	{
		if (bullets[i])
		{
			if (!bullets[i]->isAlive())
			{
				if (bullets[i]->isScore())
					this->score += bullets[i]->getScore();
				delete bullets[i];
				bullets[i] = nullptr;
			}
			else
			{
				bullets[i]->tick(entityPositionMap);
			}
		}

	}
}

void Player::shoot()
{
	lastshot = time(0);
	for (int i = 0; i < MAXBULLETS; i++)
	{
		if (!bullets[i])
		{
			// pos, dir, speed, foreground color, background color
			bullets[i] = new Bullet(this->position, Vector(0, -1), 5000, true, COLOR_CYAN, COLOR_BLACK);
			break ;
		}
	}
}

void Player::setDefaultPosition()
{
	int h, w;
	getmaxyx(stdscr, h, w);
	if (playerNum == 0)
	{
		this->position = Vector(w / 2, h * .9);
	}
	else if (playerNum == 1)
	{
		this->position = Vector(w * .25, h * .9);
	}
	else if (playerNum == 2)
	{
		this->position = Vector(w * .75, h * .9);
	}
}

bool Player::isAlive()
{
	return alive;
}

void Player::reset()
{
	lives--;
	if (lives == 0)
	{
		alive = false;
	}
	else
	{
		setDefaultPosition();
	}
}

int Player::getScore()
{
	return score;
}

void Player::emptyBullets()
{
	for (int i = 0; i < MAXBULLETS; i++)
	{
		if (bullets[i])
		{
			delete bullets[i];
			bullets[i] = nullptr;
		}
	}
}
