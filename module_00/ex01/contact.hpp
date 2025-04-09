/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:09:36 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/09 15:09:37 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>

class Contact //the c++ class
{
	private:// access specifier, private means that the attributes and methods are 
			// only acessible inside the class
		std::string	FirstName; // attribute
		std::string	LastName; // attribute
		std::string Nickname; // attribute
		std::string PhoneNumber; // attribute
		std::string	DarkestSecret; // attribute
    
	public: // access specifier, public means that the attributes and methods are 
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
