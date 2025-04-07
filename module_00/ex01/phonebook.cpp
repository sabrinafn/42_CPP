#include "phonebook.hpp"
#include "contact.hpp"

// constructor method
Phonebook::Phonebook() {
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
    std::cout << std::setw(10) << std::right << "Index" << "|"
        << std::setw(10) << std::right << "First Name" << "|"
        << std::setw(10) << std::right << "Last Name" << "|"
        << std::setw(10) << std::right << "Nickname" << std::endl;
}

void	Phonebook::exit(void) {

}