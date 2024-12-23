#include "replace.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    try {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        myReplace(filename, s1, s2);
        std::cout << "Replacement completed. Output file: " << filename << ".replace" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}