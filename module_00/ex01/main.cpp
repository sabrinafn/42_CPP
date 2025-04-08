#include "phonebook.hpp"
#include "contact.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string line;

	std::cout << "===================================" << std::endl;
	std::cout << "|      Welcome to Phonebook!      |" << std::endl;
	std::cout << "===================================" << std::endl;
	while (1)
	{
		std::system("clear");
		std::cout << "===================================" << std::endl;
		std::cout << "|                                 |" << std::endl;
		std::cout << "| Please select an option:        |" << std::endl;
		std::cout << "|                                 |" << std::endl;
		std::cout << "| ADD: Add a new contact          |" << std::endl;
		std::cout << "| SEARCH: Search for a contact    |" << std::endl;
		std::cout << "| EXIT: Exit the program          |" << std::endl;
		std::cout << "|                                 |" << std::endl;
		std::cout << "===================================" << std::endl;

		getline(std::cin, line);
		if (line == "ADD")
		{
			Contact newContact;
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
			phonebook.add(newContact);
		}
		else if (line == "SEARCH")
		{
			phonebook.search();
		}
		else if (line == "EXIT")
		{
			break;
		}
	}
}

