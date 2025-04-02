#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./interface/ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
private:
    static const int size = 4;
    std::string name;
    AMateria* inventory[size];

public:
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif