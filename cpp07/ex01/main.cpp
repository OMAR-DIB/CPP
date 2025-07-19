#include "./includes/Iter.hpp"


void times_ten(int &i)
{
	i *= 10;
}

void print_int(const int &i)
{
    std::cout << i << " ";
}

int main(){

    int arr[] = {0,10,2,1};
    const int const_arr[] = {5, 6, 7, 8};

    // Non-const: modifies array
    iter(arr, 4, times_ten);
    iter(arr, 4, print_int); // prints: 0 100 20 10
    std::cout << std::endl;

    // Const: only reads array
    iter(const_arr, 4, print_int); // prints: 5 6 7 8
    std::cout << std::endl;

    return 0;
}