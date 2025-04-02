#include "./includes/MateriaSource.hpp"
#include "./includes/Ice.hpp"
#include "./includes/Cure.hpp"
#include "./includes/Character.hpp"

int main() {
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character hero("Hero");
    Character enemy("Enemy");

    AMateria *ice1 = source.createMateria("ice");
    AMateria *cure1 = source.createMateria("cure");

    hero.equip(ice1);
    hero.equip(cure1);
    
    hero.use(0, enemy); // * shoots an ice bolt at Enemy *
    hero.use(1, hero);  // * heals Hero's wounds *

    hero.unequip(0);
    hero.use(0, enemy); // Nothing happens

    return 0;
}