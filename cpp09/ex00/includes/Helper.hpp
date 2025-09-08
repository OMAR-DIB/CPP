#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>

class Helper
{
public:
	// implement connonical form
	Helper() {}
	~Helper() {}
	Helper(const Helper &other) { (void)other; }
	Helper &operator=(const Helper &other)
	{
		(void)other;
		return *this;
	}
	static void trim(std::string &str);
	static std::string toLower(const std::string &str);
	static bool isValidDate(const std::string &date);
};

#endif
