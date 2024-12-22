#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <string>
#include "weapon.hpp"  
class HumanB
{
private:
    std::string name;
    Weapon* weapon;
public:
    HumanB(const std::string& name);
    ~HumanB();

    void setWeapon(Weapon& weapon);
    void attack();
};




#endif