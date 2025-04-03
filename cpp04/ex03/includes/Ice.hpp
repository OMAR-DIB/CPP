#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        virtual ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
};

#endif