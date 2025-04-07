#include "phonebook.hpp"

	//void	add(void);
	//void	search(void);
	//void	exit(void);

int	main(void)
{
	// std::cout << "phonebook?" << std::endl;
	
	// std::cout << "First name:" << std::endl;
	// std::cin >> name;
	// std::cout << "Your name is " << name << std::endl;
	// contact a;
	// contact b;

	// b.contact(a);
	// b = a;
	Phonebook	phonebook;
	Contact		new_contact;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int			i = 0;

	//while (i < 8)
	//{
		std::cout << "First name:" << std::endl;
		std::cin >> first_name;
		new_contact.setFirstName(first_name);
		std::cout << "Last name:" << std::endl;
		std::cin >> last_name;
		new_contact.setLastName(last_name);
		std::cout << "Nickname:" << std::endl;
		std::cin >> nickname;
		new_contact.setNickname(nickname);
		std::cout << "Phone number:" << std::endl;
		std::cin >> phone_number;
		new_contact.setPhoneNumber(phone_number);
		std::cout << "Darkest Secret:" << std::endl;
		std::cin >> darkest_secret;
		new_contact.setDarkestSecret(darkest_secret);
		//i++;
	//}
}
