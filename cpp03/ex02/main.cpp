#include "FragTrap.hpp"

int main() {
    // Create a FragTrap object
    FragTrap frag("Fraggy");

    // Test attack method
    frag.attack("Target Dummy");

    // Test taking damage
    frag.takeDamage(30);
    frag.takeDamage(80);  // This should bring hit points to zero

    // Try attacking again with zero hit points
    frag.attack("Target Dummy");

    // Test repairing (energy cost of 1)
    frag.beRepaired(50);

    // Test high fives
    frag.highFivesGuys();
    return 0;
}