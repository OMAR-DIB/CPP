#include "zombie.hpp"
#include <string>
#include <iostream>

int main()
{
	int N = 5;
    std::string name = "Walker";

    // Create the horde
    Zombie* horde = zombieHorde(N, name);

    delete[] horde;
	return 0;
}