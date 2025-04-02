#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
private:
    /* data */
public:
    Cure(/* args */);
    virtual ~Cure();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
