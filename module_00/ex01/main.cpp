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
			std::cout << "First name:" << std::endl;
			std::cin >> line;
			phonebook.Contact[0].setFirstName(line);
			std::cout << "Last name:" << std::endl;
			std::cin >> line;
			new_contact.setLastName(line);
			std::cout << "Nickname:" << std::endl;
			std::cin >> line;
			new_contact.setNickname(line);
			std::cout << "Phone number:" << std::endl;
			std::cin >> line;
			new_contact.setPhoneNumber(line);
			std::cout << "Darkest Secret:" << std::endl;
			std::cin >> line;
			new_contact.setDarkestSecret(line);
			phonebook.add(new_contact);
		}
		else if (line == "SEARCH")
		{
			phonebook.search();
		}
		else if (line == "EXIT")
		{
			exit(1);
		} 
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
