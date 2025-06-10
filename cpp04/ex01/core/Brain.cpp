
#include "../includes/Brain.hpp"

Brain::Brain(/* args */)
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "destructor Brain called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}