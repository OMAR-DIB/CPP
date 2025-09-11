#include "../includes/RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}
RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

int RPN::evaluate(const std::string &expression)
{
	std::stack<int> stk;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) // >> reads characters from the stream until it encounters whitespace
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stk.size() < 2)
			{
				throw std::runtime_error("Error: insufficient values in the expression.");
			}
			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();
			int result;

			if (token == "+")
			{
				result = a + b;
			}
			else if (token == "-")
			{
				result = a - b;
			}
			else if (token == "*")
			{
				result = a * b;
			}
			else if (token == "/")
			{
				if (b == 0)
				{
					throw std::runtime_error("Error: division by zero.");
				}
				result = a / b;
			}
			stk.push(result);
		}
		else
		{
			// Try to convert token to an integer
			try
			{
				int value = atoi(token.c_str());
				if (value == 0 && token != "0")
				{
					throw std::runtime_error("Error: invalid token '" + token + "'.");
				}
				stk.push(value);
			}
			catch (const std::invalid_argument &)
			{
				throw std::runtime_error("Error: invalid token '" + token + "'.");
			}
			catch (const std::out_of_range &)
			{
				throw std::runtime_error("Error: number out of range '" + token + "'.");
			}
		}
	}

	if (stk.size() != 1)
	{
		throw std::runtime_error("Error: the user input has too many values.");
	}

	return stk.top();
}