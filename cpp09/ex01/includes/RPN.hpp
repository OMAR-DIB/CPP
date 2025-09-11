#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdlib.h>

class RPN
{
private:
	/* data */
public:
	RPN() {}
	~RPN() {}
	RPN(const RPN &other) { (void)other; }
	RPN &operator=(const RPN &other)
	{
		(void)other;
		return *this;
	}
	int evaluate(const std::string &expression);
};

#endif