#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

    std::cout << "====== constructors ===========" << std::endl;
    //AAnimal animal;
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << "================================\n" << std::endl;

    std::cout << "========== sounds =========" << std::endl;
    std::cout << "Cat sound is: ";
    cat->makeSound();
    std::cout << "Dog sound is: ";
    dog->makeSound();

    std::cout << "===========================\n" << std::endl;

    std::cout << "======= destructors =======" << std::endl;
    delete(dog);
    delete(cat);
    
    std::cout << "===========================\n" << std::endl;

    return 0;
}
