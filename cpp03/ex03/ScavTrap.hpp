#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
    /* data */
public:
    ~ScavTrap();
    ScavTrap(std::string name);
    void attack(const std::string &target);
    void guardGate();
    ScavTrap(ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
};
