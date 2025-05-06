#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

    std::cout << "====== Testing Array of Animals ======\n" << std::endl;
    int size = 4;
    Animal*  array[size];

    std::cout << "====== Constructors ======" << std::endl;
    // setting brain ideas and initializing the array
    for (int i = 0; i < size; i++) {
        if (i < size / 2) {
            Dog* dog = new Dog();
            for (int j = 0; j < 100; j++) {
                dog->setBrainIdea(j, "Catch a ball in the park");
            }
            array[i] = dog;
        } else {
            Cat* cat = new Cat();
            for (int j = 0; j < 100; j++) {
                cat->setBrainIdea(j, "Hunt a bird in the garden");
            }
            array[i] = cat;
        } 
    }
    std::cout << std::endl;
    std::cout << "====== Destructors ======" << std::endl;

    // deleting array of animals
    for (int i = 0; i < size; i++) {
        delete array[i];
    }

    std::cout << "===================================\n" << std::endl;

    std::cout << "====== Testing Shallow and Deep Copies ======\n" << std::endl;

    std::cout << "====== Deep Copy ======" << std::endl;

    // Deep Copy
    Dog* one = new Dog();
    for (int i = 0; i < 100; i++) {
        one->setBrainIdea(i, "I'm a dog");
    }
    Dog *copy = new Dog(*one);

    std::cout << "Dog one's idea: " << one->getIdea(0) << std::endl;
    std::cout << "Dog Copy's idea: " << copy->getIdea(0) << std::endl;

    copy->setBrainIdea(0, "I'm a dog, but different");
    std::cout << "Changing copy's idea to 'I'm a dog, but different'" << std::endl;

    std::cout << "Dog one's idea: " << one->getIdea(0) << std::endl;
    std::cout << "Dog Copy's idea: " << copy->getIdea(0) << std::endl;
    
    std::cout << std::endl;
    std::cout << "====== Shallow Copy ======" << std::endl;
    
    delete(one);
    delete(copy);

    // Shallow Copy
    Cat* two = new Cat();
    for (int i = 0; i < 100; i++) {
        two->setBrainIdea(i, "I'm a Cat");
    }
    Cat *copy_two = two;

    std::cout << "Cat two's idea: " << two->getIdea(0) << std::endl;
    std::cout << "Cat copy_two's idea: " << copy_two->getIdea(0) << std::endl;

    copy_two->setBrainIdea(0, "I'm a Cat, but different");
    std::cout << "Changing copy_two's idea to 'I'm a Cat, but different'" << std::endl;

    std::cout << "Cat two's idea: " << two->getIdea(0) << std::endl;
    std::cout << "Cat copy_two's idea: " << copy_two->getIdea(0) << std::endl;

    delete(two);
    return 0;
}
