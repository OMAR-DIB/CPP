#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	// std::string toLower(std::string& str);
public:
	Harl(/* args */);
	~Harl();
	void complain( std::string level );
};



#endif