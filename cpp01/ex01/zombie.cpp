#include "zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
}
Zombie::Zombie() : name("")
{
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed." << std::endl;
}
