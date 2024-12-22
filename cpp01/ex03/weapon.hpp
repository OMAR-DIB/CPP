#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
private:
    std::string type;
public: 
    Weapon(const std::string& type);
    ~Weapon();
    
    void setType(const std::string& type);
    std::string& getType();
};




#endif