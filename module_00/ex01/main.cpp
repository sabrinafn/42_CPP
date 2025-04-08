#include "phonebook.hpp"
#include "contact.hpp"

	//void	add(void);
	//void	search(void);
	//void	exit(void);

int	main(void)
{
	Phonebook	phonebook;
	std::string line;

	while (1)
	{
		getline(std::cin, line);
		if (line == "ADD")
		{
			Contact newContact;
			std::cout << "First name:";
			std::cin >> line;
			newContact.setFirstName(line);
			std::cout << "Last name:";
			std::cin >> line;
			newContact.setLastName(line);
			std::cout << "Nickname:";
			std::cin >> line;
			newContact.setNickname(line);
			std::cout << "Phone number:";
			std::cin >> line;
			newContact.setPhoneNumber(line);
			std::cout << "Darkest Secret:";
			std::cin >> line;
			newContact.setDarkestSecret(line);
			phonebook.add(newContact);
		}
		else if (line == "SEARCH")
		{
			phonebook.search();
		}
		else if (line == "EXIT")
		{
			exit(1);
		}
		else
			std::cout << "ADD || SEARCH || EXIT" << std::endl;
	}
}

	//std::cout << "First name:" << std::endl;
	//std::cin >> first_name;
	//new_contact.setFirstName(first_name);
	//std::cout << "Last name:" << std::endl;
	//std::cin >> last_name;
	//new_contact.setLastName(last_name);
	//std::cout << "Nickname:" << std::endl;
	//std::cin >> nickname;
	//new_contact.setNickname(nickname);
	//std::cout << "Phone number:" << std::endl;
	//std::cin >> phone_number;
	//new_contact.setPhoneNumber(phone_number);
	//std::cout << "Darkest Secret:" << std::endl;
	//std::cin >> darkest_secret;
	//new_contact.setDarkestSecret(darkest_secret);
	//phonebook.add(new_contact);
