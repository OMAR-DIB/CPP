#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Clappy");

    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.attack("Another Enemy");
    robot.takeDamage(8);
    robot.beRepaired(5);

    return 0;
}