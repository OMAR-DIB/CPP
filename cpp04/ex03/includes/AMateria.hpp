#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "./interface/ICharacter.hpp"
#include <string>
#include <iostream>

// ✅ Forward declaration
class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
    AMateria(std::string const & type);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual ~AMateria();
    virtual void use(ICharacter& target);
};

#endif