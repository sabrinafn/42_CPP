/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:09:22 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/09 15:09:23 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <csignal>

void signalHandler(int signal) {
    if (signal == SIGINT) {
        std::cerr << " Signal interrupt (Ctrl+C) detected." << std::endl;
        _exit(0);
    }
}

int	main(void)
{
	Phonebook	phonebook;
	Contact		NewContact;
	std::string line;

	std::signal(SIGINT, signalHandler);
	while (1)
	{
		phonebook.display_info();
		getline(std::cin, line);
		if (line == "ADD")
		{
			NewContact = phonebook.CreateContact();
			phonebook.add(NewContact);
		}
		else if (line == "SEARCH")
			phonebook.search();
		else if (line == "EXIT") {
			std::cout << "\033[2J\033[1;1H";
			break;
		}
		if (std::cin.eof()) {
        	std::cerr << "EOF (Ctrl+D) detected." << std::endl;
            break;
        }
		std::cout << "\033[2J\033[1;1H";
	}
	return (0);
}

