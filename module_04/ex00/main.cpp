#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

    std::cout << "====== constructors ======" << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    const WrongCat* only_wrong_cat = new WrongCat();
    std::cout << "===========================\n" << std::endl;

    std::cout << "========== types ==========" << std::endl;
    std::cout << "animal type is: " << animal->getType() << " " << std::endl;
    std::cout << "dog type is: " << dog->getType() << " " << std::endl;
    std::cout << "cat type is: " << cat->getType() << " " << std::endl;

    std::cout << "wrong_animal type is: " << wrong_animal->getType() << " " << std::endl;
    std::cout << "wrong_cat type is: " << wrong_cat->getType() << " " << std::endl;
    std::cout << "only_wrong_cat type is: " << only_wrong_cat->getType() << " " << std::endl;
    std::cout << "===========================\n" << std::endl;

    std::cout << "========== sounds =========" << std::endl;
    std::cout << "Animal sound is: ";
    animal->makeSound();
    std::cout << "Cat sound is: ";
    cat->makeSound();
    std::cout << "Dog sound is: ";
    dog->makeSound();

    std::cout << "wrong_animal sound is: ";
    wrong_animal->makeSound();
    std::cout << "wrong_cat sound is: ";
    wrong_cat->makeSound();
    std::cout << "only_wrong_cat sound is: ";
    only_wrong_cat->makeSound();
    std::cout << "===========================\n" << std::endl;

    std::cout << "======= destructors =======" << std::endl;
    delete(dog);
    delete(cat);
    delete(animal);

    delete(wrong_animal);
    delete(wrong_cat);
    delete(only_wrong_cat);
    std::cout << "===========================\n" << std::endl;

    return 0;
}
