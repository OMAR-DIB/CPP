#include "ScavTrap.hpp"
#include <iostream>

int main() {
    // Test 1: Basic ScavTrap creation and destruction
    std::cout << "\n--- Test 1: ScavTrap Creation/Destruction ---\n";
    ScavTrap scav1("Rusty");

    // Test 2: ScavTrap attack
    std::cout << "\n--- Test 2: ScavTrap Attack ---\n";
    ClapTrap clap1("Target"); // Create a ClapTrap to be attacked
    scav1.attack("Target");
    clap1.takeDamage(20); // ScavTrap attack damage is 20

    // Test 3: ClapTrap attack (to show the difference)
    std::cout << "\n--- Test 3: ClapTrap Attack ---\n";
    ClapTrap clap2("AnotherTarget");
    clap2.attack("AnotherTarget"); // ClapTrap's attack message

    // Test 4: ScavTrap take damage
    std::cout << "\n--- Test 4: ScavTrap Take Damage ---\n";
    scav1.takeDamage(30);
    scav1.takeDamage(80); // Damage exceeds hit points (100)

    // Test 5: ScavTrap be repaired
    std::cout << "\n--- Test 5: ScavTrap Be Repaired ---\n";
    scav1.beRepaired(20);
    scav1.beRepaired(100); // Try to repair above max hit points (100)
    scav1.takeDamage(100);
    scav1.beRepaired(50); // Repair at 0 HP

    // Test 6: ScavTrap guardGate
    std::cout << "\n--- Test 6: ScavTrap Guard Gate ---\n";
    scav1.guardGate();

    // Test 7: ScavTrap copy constructor
    // std::cout << "\n--- Test 7: ScavTrap Copy Constructor ---\n";
    // ScavTrap scav2 = scav1;
    // scav2.attack("CopyTarget");

    // Test 8: ScavTrap copy assignment operator
    std::cout << "\n--- Test 8: ScavTrap Copy Assignment ---\n";
    ScavTrap scav3("Original");
    ScavTrap scav4("Destination");
    scav4 = scav3;
    scav4.attack("CopyAssignTarget");

    // Test 9: ScavTrap self-assignment
    std::cout << "\n--- Test 9: ScavTrap Self-Assignment ---\n";
    scav1 = scav1; // Should do nothing

    // Test 10: ScavTrap energy depletion
    std::cout << "\n--- Test 10: ScavTrap Energy Depletion ---\n";
    for (int i = 0; i < 50; ++i) { // ScavTrap energy is 50
        scav1.attack("someone");
    }
    scav1.attack("someone"); // No energy left

    return 0;
}