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

    // Creating a horde of Zombies on the heap
    std::cout << "==================================================" << std::endl;
    std::cout << "|    Creating a horde of Zombies on the Heap:    |" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;
    
    int size = 3;

    Zombie* Zombies = zombieHorde(size, "John");
    for (int i = 0; i < size; i++) {
        Zombies[i].announce();
    }

    std::cout << std::endl;

    // Deleting a horde of Zombies on the heap
    std::cout << "==================================================" << std::endl;
    std::cout << "|    Deleting a horde of Zombies on the Heap:    |" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;
    delete[] Zombies;
    Zombies = NULL;
    std::cout << std::endl;

    return 0;
}
