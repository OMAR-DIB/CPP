#include "humanB.hpp"
HumanB::HumanB(const std::string& name): name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& nweapon){
    weapon = &nweapon;
}
void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with their " << std::endl;
}