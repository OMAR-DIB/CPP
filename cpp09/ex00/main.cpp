#include "includes/BitcoinExchange.hpp"
#include "includes/Helper.hpp"

void processInputFile(const std::string &filename, const BitcoinExchange &exchange)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		// Skip header line if it exists
		if (firstLine)
		{
			firstLine = false;
			if (line.find("date") != std::string::npos && line.find("value") != std::string::npos)
			{
				continue;
			}
		}

		// Find the pipe separator
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);

		Helper::trim(dateStr);
		Helper::trim(valueStr);

		// Validate date format
		if (!Helper::isValidDate(dateStr))
		{
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		// Validate and parse value
		float value;
		try
		{
			// Check if valueStr is empty or contains only whitespace
			if (valueStr.empty())
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			// Check for invalid characters (except digits, decimal point, and minus)
			bool hasValidChars = true;
			bool hasDecimalPoint = false;
			for (size_t i = 0; i < valueStr.length(); i++)
			{
				char c = valueStr[i];
				if (i == 0 && c == '-')
				{
					continue; // Allow minus at the beginning
				}
				else if (c == '.' && !hasDecimalPoint)
				{
					hasDecimalPoint = true;
				}
				else if (!std::isdigit(c))
				{
					hasValidChars = false;
					break;
				}
			}

			if (!hasValidChars)
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			//float value;
			std::stringstream ss(valueStr);
			if (!(ss >> value))
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			// Check if value is negative
			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}

			// Check if value is too large
			if (value > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
		}
		catch (const std::exception &)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Get exchange rate and calculate result
		try
		{
			float rate = exchange.getExchangeRate(dateStr);
			float result = value * rate;

			std::cout << dateStr << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	file.close();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange exchange;

		// Load the database (assuming it's named "data.csv")
		// You might need to adjust this path based on where your data file is located
		exchange.loadData("db/data.csv");

		// Process the input file
		processInputFile(argv[1], exchange);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}	