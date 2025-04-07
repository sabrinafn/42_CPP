#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "contact.hpp"

class Phonebook //the c++ class
{
	private:
		Contact contacts[8]; // using the contact class to create an array
		int			Index; // attribute
		int			Counter;
		int			NextIndex;
    
	public: // access specifier, public means that the atributes and methods are 
			// acessible outside the class
        Phonebook(); // Default Constructor
        ~Phonebook(); // Destructor
		int		getIndex();
		void	setIndex(int Index);
		int		getCounter();
		void	setCounter(int Counter);
		void	add(Contact NewContact); // method/function
		void	search(void); // method/function
		void	exit(void); // method/function
};

#endif
