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
Phonebook::Phonebook() : Index(0), Counter(0), NextIndex(0) {
    return ;
}

// Destructor method
Phonebook::~Phonebook() {
    return ;
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

    if (NewContact.getFirstName().empty() || NewContact.getLastName().empty() ||
        NewContact.getNickname().empty() || NewContact.getPhoneNumber().empty() ||
        NewContact.getDarkestSecret().empty()) {
        std::cerr << "Error: A contact can't have empty fields. Try again." << std::endl;
        std::string line;
        getline(std::cin, line);
        return;
    }
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

void    Phonebook::display_contactlist_header(void) {

    std::cout << std::setw(10); // set 10 spaces before the output
    std::cout << std::right << "Index" << "|"; //  set text to the right
    std::cout << std::setw(10);
    std::cout << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
}

void    Phonebook::search_contact_by_index(void) {

    std::string line;
    int index;
    Contact ContactIndexed;

    std::cout << "Enter index to display contact: ";
    getline(std::cin, line);

    std::stringstream ss(line);
    ss >> index;
    if (ss.fail())
        index = 0;

    // display full contact information and handle errors
    if (index >= 1 && index <= Counter)
    {
        ContactIndexed = contacts[index - 1]; // Adjust index for array (index is from 1 to 8)
        std::cout << "First Name: " << ContactIndexed.getFirstName() << std::endl;
        std::cout << "Last Name: " << ContactIndexed.getLastName() << std::endl;
        std::cout << "Nickname: " << ContactIndexed.getNickname() << std::endl;
        std::cout << "Phone Number: " << ContactIndexed.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << ContactIndexed.getDarkestSecret() << std::endl;
    }
    else
        std::cerr << "Invalid index." << std::endl;

    std::cout << "Enter anything to continue..." << std::endl;
    getline(std::cin, line);
}

void	Phonebook::search(void) {

    display_contactlist_header();
    
    for (int i = 0; i < Counter; ++i)
    {
        std::string FirstName = contacts[i].getFirstName();
        std::string LastName = contacts[i].getLastName();
        std::string Nickname = contacts[i].getNickname();

        // If the text is longer than the column, it must be truncated and
        // the last displayable character must be replaced by a dot (’.’).
        if (FirstName.length() > 10)
            FirstName = FirstName.substr(0, 9) + "."; // create a substring that starts at pos 0
        if (LastName.length() > 10)                   // and has length 9, then add a '.'
            LastName = LastName.substr(0, 9) + ".";
        if (Nickname.length() > 10)
            Nickname = Nickname.substr(0, 9) + ".";

        // Display index starting from 1
        std::cout << std::setw(10); // sets the minimum width of the next output field to 10 characters
        // if output is shorter than 10, it will be padded with spaces on the left (because of std::right later)
        std::cout << std::right; //sets the alignment of the output to the right 
        
        std::cout << i + 1 << "|";
        std::cout << std::setw(10);
        std::cout << std::right << FirstName << "|";
        std::cout << std::setw(10);
        std::cout << std::right << LastName << "|";
        std::cout << std::setw(10);
        std::cout << std::right << Nickname << std::endl;
    }

    search_contact_by_index();
}

void    Phonebook::display_info(void) {
    std::cout << "=======================================" << std::endl;
    std::cout << "|        This is your phonebook       |" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|  How to use:                        |" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|  ADD: Add a new contact             |" << std::endl;
    std::cout << "|  SEARCH: Search for a contact       |" << std::endl;
    std::cout << "|  EXIT: Exit the program             |" << std::endl;
    std::cout << "|                                     |" << std::endl;
    std::cout << "|           Phonebook capacity: [" << Counter << "/8] |" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Command: ";
}
