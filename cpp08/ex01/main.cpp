#include "includes/Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
int main()
{

    const unsigned int COUNT = 10000;
    Span sp(COUNT);

    // prepare 0..COUNT-1
    std::vector<int> nums;
    nums.reserve(COUNT);
    for (unsigned int i = 0; i < COUNT; ++i)
        nums.push_back(static_cast<int>(i));
    // // shuffle them (C++98)
    // std::srand(static_cast<unsigned int>(std::time(NULL)));
    // std::random_shuffle(nums.begin(), nums.end());
    sp.addNumber(nums.begin(), nums.end());

    std::cout << sp.shortestSpan() <<std::endl;
    std::cout << sp.longestSpan() <<std::endl;

    return 0;
}