#include "./includes/A.hpp"
#include "./includes/B.hpp"
#include "./includes/C.hpp"
#include "./includes/Base.hpp"

// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base * generate(void){
    int i = rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new C;
    else
        return new B;
}

// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p){
    if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
    else
        std::cout << "UNKNOWN TYPE" << std::endl;
    
}

// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
void identify(Base& p){
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "\'A" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "\'B" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "\'C" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

int main(){
    Base* b= generate();
    identify(b);
    identify(*b);
    return 0;
}
