/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:51:57 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/14 17:52:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

    // Creating a Zombie on the heap
    std::cout << "==================================================" << std::endl;
    std::cout << "|       Creating a Zombie on the Heap:           |" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;
    
    Zombie* heapZombie = newZombie("John");
    heapZombie->announce();

    std::cout << std::endl;


    // Creating a Zombie on the stack
    std::cout << "==================================================" << std::endl;
    std::cout << "|  Creating and Deleting a Zombie on the Stack:  |" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;
    randomChump("Mary");

    std::cout << std::endl;

    // Deleting Zombie on the heap
    std::cout << "==================================================" << std::endl;
    std::cout << "|      Deleting the Zombie on the Heap:          |" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;
    delete heapZombie;
    heapZombie = NULL;
    std::cout << std::endl;

    return 0;
}
