#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Phonebook //the c++ class
{
	private:
		std::string contacts[8];
		void	add(void);
		void	search(void);
		void	exit(void); // method/function
    
	public: // access specifier, public means that the atributes and methods are 
			// acessible outside the class
        Phonebook(); // Default Constructor
        Phonebook(const Phonebook& copy); // Copy Constructor
        Phonebook& operator=(const Phonebook& copy); // Copy Assignment Operator
        ~Phonebook(); // Destructor

		// Phonebook&: referência a alguma estância da classe
};

#endif
