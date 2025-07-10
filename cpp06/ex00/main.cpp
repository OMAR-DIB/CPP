#include <iostream>

#include "./includes/ScalarConverter.hpp"
#include <cstdio>
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

    // int main() {
    //     std::string myString = "Hello, C++!";
    //     printf("Using c_str(): %s\n", myString.c_str());
    //     return 0;
    // }