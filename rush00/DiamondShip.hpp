#ifndef DIAMONDSHIP_HPP
# define DIAMONDSHIP_HPP

#include "Enemy.hpp"

class DiamondShip : public Enemy {

public:
	DiamondShip();
	~DiamondShip();
	DiamondShip(const DiamondShip& f);
	DiamondShip &operator=(const DiamondShip& f);
    void tick();

	virtual GameEntity *clone();

};

#endif