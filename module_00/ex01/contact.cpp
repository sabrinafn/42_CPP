#include "contact.hpp"

// constructor method
Contact::Contact() {
    std::cout << "Constructor called." << std::endl;
}

// Copy Constructor
Contact::Contact(const Contact& copy) {

}

Contact::Contact& operator=(const Contact& copy); // Copy Assignment Operator
~Contact(); // Destructor

// getter methodsfunctions

int Contact::getIndex() {
    return Index;
}
std::string	Contact::getFirstName() {
    return FirstName;
}

std::string	Contact::getLastName() {
    return LastName;
}

std::string	Contact::getNickname() {
    return Nickname;
}

std::string	Contact::getPhoneNumber() {
    return PhoneNumber;
}

std::string	Contact::getDarkestSecret() {
    return DarkestSecret;
}

// setter methods/functions

void Contact::setIndex(int Index) {
    this->Index = Index;
}

void Contact::setFirstName(const std::string& FirstName) {
    this->FirstName = FirstName;
}

void Contact::setLastName(const std::string& LastName) {
    this->LastName = LastName;
}

void Contact::setNickname(const std::string& Nickname) {
    this->Nickname = Nickname;
}

void Contact::setPhoneNumber(const std::string& PhoneNumber) {
    this->PhoneNumber = PhoneNumber;
}

void Contact::setDarkestSecret(const std::string& DarkestSecret) {
    this->DarkestSecret = DarkestSecret;
}