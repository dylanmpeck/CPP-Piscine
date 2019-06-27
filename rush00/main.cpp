#include "GameEntity.hpp"
#include <iostream>
#include <curses.h>
#include <unistd.h>
#include "Player.hpp"
#include "EnemyFactory.hpp"
#include "Asteroid.hpp"

/*
** noecho doesn't print keys we press to screen
** curs_set(0) makes cursor invisible
** nodelay(...) makes getch non-blocking
** keypad(...) allows "complex" key presses, such as arrows
*/
void init_curses()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	nodelay(stdscr, true);

	//colors get stored in pairs which are called later by their number
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
}

void handle_winch(int sig)
{
	(void)sig;
	endwin();
	refresh();
	clear();

}

int main(int argc, char **argv)
{
	init_curses();
	srand(time(0));

	bool mp = false;
	int spawnThresh = 500;

	(void)argv;
	if (argc > 1)
		mp = true;
	Player *p;
	Player *p2;
	if (mp)
	{
		p = new Player(1);
		p2 = new Player(2);
	}
	else
	{
		p = new Player();
	}
	EnemyFactory *factory = new EnemyFactory();
	while (p->isAlive() || p2->isAlive())
	{
		usleep(10000); // this is a random number, anything much smaller and you get flashing screen
		clear();
		factory->tick();
		int ch = getch();
		signal(SIGWINCH, handle_winch);
		if (p->getScore() / spawnThresh > 0)
		{
			spawnThresh += spawnThresh;
			factory->spawnBoss();
		}
		if (p->isAlive())
		{
			p->handleInput(ch);
			p->tick(factory->getEntityPositionMap());
		}
		if (mp && p2->isAlive())
		{
			p2->handleInput(ch);
			p2->tick(factory->getEntityPositionMap());
		}

		refresh();
	}
	endwin();
	
	std::cout << "Game over" << std::endl;
	std::cout << "Player 1: " << p->getScore() << std::endl;
	if (mp)
		std::cout << "Player 2: " << p2->getScore() << std::endl;

	delete factory;
	delete p;
	if (mp)
		delete p2;
}