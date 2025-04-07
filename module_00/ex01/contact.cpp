#include "contact.hpp"

// constructor method
Contact::Contact() {
    std::cout << "Contact Constructor called." << std::endl;
}

// Destructor method
Contact::~Contact() {
    std::cout << "Contact Destructor called." << std::endl;
}

// getter methods/functions

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