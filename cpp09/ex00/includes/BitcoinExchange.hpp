#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>

class BitcoinExchange {
	private:
    	std::map<std::string, double> exchangeRates;
	public:
    	BitcoinExchange();
    	~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

    	bool loadData(const std::string& filename);
    	double getExchangeRate(const std::string& date) const;
		void processInputFile(const std::string& filename, const BitcoinExchange& exchange);
};

#endif
