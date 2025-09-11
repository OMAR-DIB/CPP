#include "../includes/Helper.hpp"
#include <stdlib.h>
void Helper::trim(std::string &str){
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	if (first == std::string::npos || last == std::string::npos) {
		str = "";
	} else {
		str = str.substr(first, (last - first + 1));
	}
}

std::string Helper::toLower(const std::string &str){
	std::string lowerStr = str;
	// use another way instead of for_each and ::tolower to be compatible with C++98
	for (size_t i = 0; i < lowerStr.length(); ++i) {
		lowerStr[i] = std::tolower(static_cast<unsigned char>(lowerStr[i]));
	}
	
	return lowerStr;
}

bool Helper::isValidDate(const std::string &date){
	// the date should be in the format YYYY-MM-DD
	// check the length
	if (date.length() != 10)
		return false;
	// check the positions of the dashes
	if (date[4] != '-' || date[7] != '-')
		return false;
	// check if the year, month, and day are digits
	for (size_t i = 0; i < date.length(); ++i){
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	// Extract year, month, day
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    // Basic validation
    if (year < 1000 || year > 9999) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // More detailed month/day validation
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[1] = 29;	
    }
    
    if (day > daysInMonth[month - 1]) {
        return false;
    }
    
    return true;
}