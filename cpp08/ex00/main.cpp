#include "./includes/easyfind.hpp"

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    std::vector<int> vec(arr1, arr1 + sizeof(arr1)/sizeof(int));

    int arr2[] = {2, 4, 6, 8, 10};
    std::list<int> lst(arr2, arr2 + sizeof(arr2)/sizeof(int));

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 7);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    return 0;
}