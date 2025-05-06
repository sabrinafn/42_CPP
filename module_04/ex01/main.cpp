#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {

    std::cout << "====== constructors ======" << std::endl;
    const Animal  array[2];
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "===========================\n" << std::endl;

    std::cout << "========== types ==========" << std::endl;
    std::cout << "dog type is: " << dog->getType() << " " << std::endl;
    std::cout << "cat type is: " << cat->getType() << " " << std::endl;
    std::cout << "===========================\n" << std::endl;

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
