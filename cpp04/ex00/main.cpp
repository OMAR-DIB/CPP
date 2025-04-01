#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"
#include "./includes/WrongCat.hpp"
int main() {
    std::cout << "=== Animal ===" << std::endl;
    Animal* animal = new Animal();
    animal->makeSound();
    delete animal;
    
    std::cout << "\n=== Dog ===" << std::endl;
    Animal* dog = new Dog();
    dog->makeSound();
    delete dog;

    std::cout << "\n=== Cat ===" << std::endl;
    Animal* cat = new Cat();
    cat->makeSound();
    delete cat;

    std::cout << "\n=== WrongAnimal ===" << std::endl;
    WrongAnimal* wrong_animal = new WrongAnimal();
    wrong_animal->makeSound();
    delete wrong_animal;

    std::cout << "\n=== WrongCat ===" << std::endl;
    WrongAnimal* wrong_cat = new WrongCat();
    wrong_cat->makeSound();
    delete wrong_cat;
    return 0;
}