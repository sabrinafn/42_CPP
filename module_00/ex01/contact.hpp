#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>

class Contact //the c++ class
{
	private:
		std::string	FirstName; // attribute
		std::string	LastName; // attribute
		std::string Nickname; // attribute
		std::string PhoneNumber; // attribute
		std::string	DarkestSecret; // attribute
    
	public: // access specifier, public means that the atributes and methods are 
			// acessible outside the class
        Contact(); // Constructor
        ~Contact(); // Destructor

		// declaration of getter functions
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

		// declaration of setter functions
		void	setFirstName(const std::string& FirstName);
		void	setLastName(const std::string& LastName);
		void	setNickname(const std::string& Nickname);
		void	setPhoneNumber(const std::string& PhoneNumber);
		void	setDarkestSecret(const std::string& DarkestSecret);
};

#endif