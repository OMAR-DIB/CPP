#pragma once
#include <iostream>
#include "ClapTrap.hpp"
#include <string>
class FragTrap : public ClapTrap {
	public:
		~FragTrap();
		FragTrap(std::string name);
		void attack(const std::string& target);
		void highFivesGuys(void);
		FragTrap(FragTrap& other);
		FragTrap& operator = (const FragTrap& other);
};

