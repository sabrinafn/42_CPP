/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:09:45 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/09 15:09:47 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include "contact.hpp"

class Phonebook //the c++ class
{
	private: // access specifier, private means that the attributes and methods are 
	// only acessible inside the class
		Contact contacts[8]; // using the contact class to create an array of contacts
		int			Index; // attribute
		int			Counter;
		int			NextIndex;
    
	public: // access specifier, public means that the atributes and methods are 
			// accessible outside the class
        Phonebook(); // Constructor
        ~Phonebook(); // Destructor
		int		getCounter();
		void	setCounter(int Counter);
		void	add(Contact NewContact); // method // setter
		void	search(); // method // getter
		Contact	CreateContact();
		void	display_info();
		void    display_contactlist_header();
		void    search_contact_by_index();
};

#endif
