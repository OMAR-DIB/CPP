#include "ClapTrap.hpp"


int main() {
    // Test 1: Basic creation and destruction
    ClapTrap clap1("Bob");
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;
    // Test 2: Attack
    ClapTrap clap2("Alice");
    clap1.attack("Alice");
    clap2.takeDamage(10); // Assuming attack_damage is 10
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;

    // Test 3: Take damage
    ClapTrap clap3("Charlie");
    clap3.takeDamage(5);
    clap3.takeDamage(10); // Damage exceeds hit points
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;

    // Test 4: Be repaired
    ClapTrap clap4("David");
    clap4.beRepaired(5);
    clap4.beRepaired(10); // Repair when HP is too low
    clap4.takeDamage(20);
    clap4.beRepaired(10); // Repair when HP is zero
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;

    // Test 5: Energy points depletion
    ClapTrap clap5("Eve");
    for (int i = 0; i < 10; ++i) { // Assuming initial energy is 10
        clap5.attack("someone");
    }
    clap5.attack("someone"); // No energy left
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;

    // Test 6: Copy constructor
    ClapTrap clap6 = clap1; // Copy constructor
    clap6.attack("Copy");
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;

    // Test 7: Copy assignment operator
    ClapTrap clap7("Original");
    ClapTrap clap8("Destination");
    clap8 = clap7; // Copy assignment
    clap8.attack("Copy Assign");
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;

    // Test 8: Self-assignment
    ClapTrap clap9("Self");
    clap9 = clap9;  // Should do nothing
    std::cout << ">-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>"<< std::endl;

    return 0;
}