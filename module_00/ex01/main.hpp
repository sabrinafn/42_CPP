#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

class PhoneBook
{
	public:
		std::string contacts[8];
		void	add(void);
		void	search(void);
		void	exit(void); // method/function
};

class Contact
{
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string nickname;
	int			phone_number;
	std::string	darkest_secret;
};

#endif
