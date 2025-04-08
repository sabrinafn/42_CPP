#include "phonebook.hpp"
#include "contact.hpp"

// constructor method
Phonebook::Phonebook() : Index(0), Counter(0){
    std::cout << "Phonebook Constructor called." << std::endl;
}

// Destructor method
Phonebook::~Phonebook() {
    std::cout << "Phonebook Destructor called." << std::endl;
}

// getter functions 
int Phonebook::getIndex() {
    return Index;
}

// int Phonebook::getCounter() {
//     return Counter;
// }

// setter functions

void Phonebook::setIndex(int Index) {
    this->Index = Index;
}

// void Phonebook::setCounter(int Counter) {
//     this->Counter = Counter;
// }

void	Phonebook::add(Contact NewContact) {

    std::cout << "here" << std::endl;
    std::cout << "Current Counter value: " << Counter << std::endl;
    if (Counter < 8)
    {
        contacts[Counter] = NewContact;
        Counter++;
    }
    else
    {
        contacts[NextIndex] = NewContact;
        NextIndex = (NextIndex + 1) % 8;
    }
       
}

void	Phonebook::search(void) {
    std::cout << "searching..." << std::endl;
}

void	Phonebook::exit(void) {

}