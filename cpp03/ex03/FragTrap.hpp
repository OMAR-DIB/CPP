#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		void highFivesGuys(void);
		FragTrap(FragTrap& other);
		FragTrap& operator = (const FragTrap& other);
};

#endif
