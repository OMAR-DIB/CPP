#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.cpp"
#include "ScavTrap.cpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
private:
	/* data */
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(DiamondTrap& other);
	DiamondTrap& operator = (const DiamondTrap& other);
};
