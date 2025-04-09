/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:09:29 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/09 15:09:31 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

// constructor method
Phonebook::Phonebook() : Index(0), Counter(0), NextIndex(0){
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

Contact Phonebook::CreateContact(void) {
    Contact newContact;
	std::string line;

    std::cout << "First name:";
    getline(std::cin, line);
    newContact.setFirstName(line);
    std::cout << "Last name:";
    getline(std::cin, line);
    newContact.setLastName(line);
    std::cout << "Nickname:";
    getline(std::cin, line);
    newContact.setNickname(line);
    std::cout << "Phone number:";
    getline(std::cin, line);
    newContact.setPhoneNumber(line);
    std::cout << "Darkest Secret:";
    getline(std::cin, line);
    newContact.setDarkestSecret(line);

    return (newContact);
}

void	Phonebook::add(Contact NewContact) {
    std::cout << "counter = " << Counter << std::endl;
    if (Counter < 8)
    {
        contacts[Counter] = NewContact;
        Counter++;
    }
    else if (Counter == 8)
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
    std::string line;
    int index;
    std::cout << "Enter index to display contact: ";
    getline(std::cin, line);
    try {
        index = std::stoi(line);
    } catch (const std::invalid_argument& e) {
    }
    // 3. Display Full Contact Information and 4. Handle Errors
    if (!isdigit(index) && index >= 1 && index <= Counter) { // Check for valid index
        Contact& ContactIndexed = contacts[index - 1]; // Adjust index for array access
        std::cout << "First Name: " << ContactIndexed.getFirstName() << std::endl;
        std::cout << "Last Name: " << ContactIndexed.getLastName() << std::endl;
        std::cout << "Nickname: " << ContactIndexed.getNickname() << std::endl;
        std::cout << "Phone Number: " << ContactIndexed.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << ContactIndexed.getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;

    std::cout << "Enter anything to continue..." << std::endl;
    getline(std::cin, line); // Wait for Enter
  
}

void    Phonebook::display_info(void) {
    std::cout << "===================================" << std::endl;
    std::cout << "|      This is your phonebook     |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "|  How to use:                    |" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "|  ADD: Add a new contact         |" << std::endl;
    std::cout << "|  SEARCH: Search for a contact   |" << std::endl;
    std::cout << "|  EXIT: Exit the program         |" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Command: ";
}
