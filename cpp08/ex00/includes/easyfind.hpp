#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>


class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "No occurrence found.";
    }
};

template <typename T>
typename T::iterator easyfind(T& container , int target){
    typename  T::iterator found = find(container.begin(),container.end(),target);
    if (found != container.end())
                return (found);
    throw NotFoundException();  
}


#endif