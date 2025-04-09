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
#include "contact.hpp"

class Phonebook //the c++ class
{
	private:
		Contact contacts[8]; // using the contact class to create an array
		int			Index; // attribute
		int			Counter;
		int			NextIndex;
    
	public: // access specifier, public means that the atributes and methods are 
			// accessible outside the class
        Phonebook(); // Default Constructor
        ~Phonebook(); // Destructor
		int		getIndex();
		void	setIndex(int Index);
		int		getCounter();
		void	setCounter(int Counter);
		void	add(Contact NewContact); // method/function // set
		void	search(void); // method/function // get
		Contact	CreateContact();
		void	display_info();
};

#endif
