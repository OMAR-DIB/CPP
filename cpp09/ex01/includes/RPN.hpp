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
	RPN(/* args */);
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	int evaluate(const std::string &expression);
};

#endif