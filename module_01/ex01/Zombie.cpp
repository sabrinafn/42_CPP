/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:56:28 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/10 19:56:29 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie( void) : name("default") {
    std::cout  << "  " << name << " Constructor called" << std::endl;
}

// destructor
Zombie::~Zombie() {
    std::cout << "  Zombie Destructor called" << std::endl;
    std::cout << "  " << name << " was killed." << std::endl;
}

void    Zombie::announce( void ) const {
    
    std::cout << "  " << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string new_name) {
        name = new_name;
}
