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
Zombie::Zombie() {

}

// destructor
Zombie::~Zombie() {

}

void    Zombie::announce( void ) {
    
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie( std::string name ) {
    
    // creating zombie on the heap
    Zombie* heapJohn = new Zombie();
    if (heapJohn) { // checking if allocation was succesful
        heapJohn->announce();
    }
    else {
        std::cerr << "Memory allocation failed." << std::endl;
    }

    return heapJohn;
}

void    Zombie::randomChump( std::string name ) {
    
    // creating zombie on the stack
    Zombie* stackMary = Zombie;

}