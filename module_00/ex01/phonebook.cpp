#include "phonebook.hpp"
#include "contact.hpp"

// constructor method
Phonebook::Phonebook() : Index(0), Counter(0){
}

// Destructor method
Phonebook::~Phonebook() {
}

// getter functions 
int Phonebook::getIndex() {
    return Index;
}

// setter functions

void Phonebook::setIndex(int Index) {
    this->Index = Index;
}

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

    // 1. Display Contact List
    std::cout << std::setw(10); // set 10 spaces before the output
    std::cout << std::right << "Index" << "|"; //  set text to the right
    std::cout << std::setw(10);
    std::cout << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

    // Use Counter for the number of contacts
    for (int i = 0; i < Counter; ++i)
    {
        std::string FirstName = contacts[i].getFirstName();
        std::string LastName = contacts[i].getLastName();
        std::string Nickname = contacts[i].getNickname();

    // Truncate strings if necessary
        if (FirstName.length() > 10)
            FirstName = FirstName.substr(0, 9) + "."; // create a substring that starts at pos 0
        if (LastName.length() > 10)                   // and has length 9, then add a '.'
            LastName = LastName.substr(0, 9) + ".";
        if (Nickname.length() > 10)
            Nickname = Nickname.substr(0, 9) + ".";

        // Display index starting from 1
        std::cout << std::setw(10);
        std::cout << std::right << i + 1 << "|";
        std::cout << std::setw(10);
        std::cout << std::right << FirstName << "|";
        std::cout << std::setw(10);
        std::cout << std::right << LastName << "|";
        std::cout << std::setw(10);
        std::cout << std::right << Nickname << std::endl;
    }

    // 2. Prompt for Index
    int index;
    std::cout << "Enter index to display contact: ";
    std::cin >> index;

    // 3. Display Full Contact Information and 4. Handle Errors
    if (index >= 1 && index <= Counter) { // Check for valid index
        Contact& selectedContact = contacts[index - 1]; // Adjust index for array access

        std::cout << "First Name: " << selectedContact.getFirstName() << std::endl;
        std::cout << "Last Name: " << selectedContact.getLastName() << std::endl;
        std::cout << "Nickname: " << selectedContact.getNickname() << std::endl;
        std::cout << "Phone Number: " << selectedContact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << selectedContact.getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
}