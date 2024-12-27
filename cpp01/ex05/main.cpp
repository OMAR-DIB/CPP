#include "harl.hpp"

int main(int ac, char **av)
{
    if (av[1])
    {
        std::string in = av[1];
        Harl harl;

        harl.complain(in);
       
    }
    (void)ac;

    return 0;
}