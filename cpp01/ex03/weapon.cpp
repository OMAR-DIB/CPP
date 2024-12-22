#include "weapon.hpp"

Weapon::Weapon(const std::string& type): type(type)
{
}

Weapon::~Weapon()
{
}
std::string& Weapon::getType()  {
        return type;
}

void Weapon::setType(const std::string& newtype){
    type = newtype;
}