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
	Contact		NewContact;
	std::string name;
	int			i = 0;

	while (i < 8)
	{
		std::cout << "First name:" << std::endl;
		std::cin >> name;
		NewContact.setFirstName(name);
		i++;
	}
}
