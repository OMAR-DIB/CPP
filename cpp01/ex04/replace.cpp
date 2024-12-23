/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:04:35 by odib              #+#    #+#             */
/*   Updated: 2024/12/23 12:26:19 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "replace.hpp"


void myReplace(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (s1.empty()){
		std::cout << "Error: s1 is empty" << std::endl;
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cout << "Error: failed to open file" << std::endl;
	}

	std::ofstream outputFile("replace.txt");
	if (!outputFile.is_open()) {
		std::cout << "Error: failed to create output file" << std::endl;
	}

	std::string line;
	bool firstLine = true; // Flag to handle the newline conditionally
    while (std::getline(inputFile, line)) {
        std::string replacedLine; 
        size_t pos = 0;

        while (true) {
            size_t found = line.find(s1, pos);
            if (found == std::string::npos) {
                replacedLine += line.substr(pos); 
                break;
            }
            replacedLine += line.substr(pos, found - pos);
            replacedLine += s2;                      
            pos = found + s1.length();                    
        }
		
         // Write the replaced line with conditional newline handling
        if (!firstLine) {
            outputFile << '\n'; // Add a newline before writing subsequent lines
        }
        outputFile << replacedLine;
        firstLine = false; // Clear the flag after the first line

    }
}