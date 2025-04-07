#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact //the c++ class
{
	private:
		int			Index; // attribute
		std::string	FirstName; // attribute
		std::string	LastName; // attribute
		std::string Nickname; // attribute
		std::string PhoneNumber; // attribute
		std::string	DarkestSecret; // attribute
    
	public: // access specifier, public means that the atributes and methods are 
			// acessible outside the class
        Contact(); // Default Constructor
        Contact(const Contact& copy); // Copy Constructor
        Contact& operator=(const Contact& copy); // Copy Assignment Operator
        ~Contact(); // Destructor
		// Contact&: referência a alguma estância da classe

		// declaration of getter functions
		int	getIndex();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

		// declaration of setter functions
		void	setIndex(int Index);
		void	setFirstName(const std::string& FirstName);
		void	setLastName(const std::string& LastName);
		void	setNickname(const std::string& Nickname);
		void	setPhoneNumber(const std::string& PhoneNumber);
		void	setDarkestSecret(const std::string& DarkestSecret);
};

#endif