#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>



class ScavTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap();
	void attack(const std::string &target);
	void guardGate();
	ScavTrap(ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
};

#endif