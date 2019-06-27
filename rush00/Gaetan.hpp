#ifndef GAETAN_HPP
# define GAETAN_HPP

#include "Enemy.hpp"

class Gaetan : public Enemy {

public:
	Gaetan();
	~Gaetan();
	Gaetan(const Gaetan& f);
	Gaetan &operator=(const Gaetan& f);
    void tick();

	virtual GameEntity *clone();

};

#endif