#include "phonebook.hpp"
#include "contact.hpp"

int	main(void)
{
	Phonebook	phonebook;
	Contact		NewContact;
	std::string line;

	while (1)
	{
		phonebook.display_info();
		getline(std::cin, line);
		if (line == "ADD")
		{
			NewContact = phonebook.CreateContact();
			phonebook.add(NewContact);
		}
		else if (line == "SEARCH")
			phonebook.search();
		else if (line == "EXIT") {
			std::system("clear");
			break;
		}
		if (std::cin.eof()) {
        	std::cout << "EOF (Ctrl+D) detected." << std::endl;
            break;
        }
		std::system("clear");
	}
	return (0);
}

