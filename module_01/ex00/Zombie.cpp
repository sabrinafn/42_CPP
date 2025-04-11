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
Zombie::Zombie(std::string name) name(name){

}

// destructor
Zombie::~Zombie() {
    std::cout << name << "is dead." << std::endl;
}

void    Zombie::announce( void ) {
    
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name ) {
    
    // creating zombie on the heap
    Zombie* heapZombie = new Zombie(name);
    if (heapZombie) { // checking if allocation was succesful
        heapZombie->announce();
    }
    else {
        std::cerr << "Memory allocation failed." << std::endl;
    }

    return heapZombie;
}

void    randomChump( std::string name ) {
    
    // creating zombie on the stack
    Zombie stackZombie(name);
    
    stackZombie.announce();

}