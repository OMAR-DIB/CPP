#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "===== Testing ClapTrap =====\n";
    ClapTrap clap("Clappy");
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\n===== Testing ScavTrap =====\n";
    ScavTrap scav("Scavvy");
    scav.attack("Intruder");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n===== Destruction Order =====\n";
    return 0;
}
