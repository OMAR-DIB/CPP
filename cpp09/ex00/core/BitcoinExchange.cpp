#include "../includes/BitcoinExchange.hpp"
#include "../includes/Helper.hpp"
BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::~BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->exchangeRates = other.exchangeRates;
	}
	return *this;
}

bool BitcoinExchange::loadData(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return false;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line))
	{
		Helper::trim(line);
		if (line.empty())
			continue;

		// Remove trailing '\r' in case of Windows line endings
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);

		// Skip header if present
		if (firstLine)
		{
			firstLine = false;
			if (line.find("date") != std::string::npos)
				continue;
		}

		// Split by comma
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Warning: bad DB line => " << line << std::endl;
			continue;
		}

		std::string dateStr = line.substr(0, pos);
		std::string priceStr = line.substr(pos + 1);
		Helper::trim(dateStr);
		Helper::trim(priceStr);

		// Validate date
		if (!Helper::isValidDate(dateStr))
		{
			std::cerr << "Warning: bad date in DB => " << line << std::endl;
			continue;
		}

		// Parse price (C++98 way using stringstream)
		double price;
		std::stringstream ss(priceStr);
		if (!(ss >> price) || !(ss.eof()))
		{
			std::cerr << "Warning: bad price in DB => " << line << std::endl;
			continue;
		}

		// Validate price
		if (price < 0)
		{
			std::cerr << "Warning: negative price in DB => " << line << std::endl;
			continue;
		}

		// Insert into map (ignore duplicates)
		if (exchangeRates.find(dateStr) != exchangeRates.end())
		{
			std::cerr << "Warning: duplicate date in DB => " << dateStr << " (ignored)" << std::endl;
			continue;
		}
		exchangeRates[dateStr] = price;
	}

	if (exchangeRates.empty())
	{
		std::cerr << "Error: no valid records found in DB." << std::endl;
		return false;
	}

	return true;
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
	// Try to find exact date first
	std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
	if (it != exchangeRates.end())
	{
		return it->second;
	}

	// Find the closest lower date
	std::map<std::string, double>::const_iterator lower = exchangeRates.lower_bound(date);
	if (lower == exchangeRates.begin())
	{
		// No date before the requested date
		throw std::runtime_error("No exchange rate available for this date or earlier.");
	}

	--lower; // Get the previous (lower) date
	return lower->second;
}