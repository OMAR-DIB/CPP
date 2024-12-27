#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return std::cerr << "Usage: ./harlFilter [LEVEL]" << std::endl, 1;

    std::string in = av[1];
    Harl harl;
    harl.complain(in);

    return 0;
}