/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:56:11 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/10 19:56:13 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
    
    // HEAP: dynamic memory to be allocated
    // creating zombie on the heap
    Zombie* heapZombie = new Zombie(name);
    if (!heapZombie) {
        std::cerr << "Memory allocation failed." << std::endl;
    }
    return heapZombie;
}