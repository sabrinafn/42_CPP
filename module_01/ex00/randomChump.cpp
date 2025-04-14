/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:56:17 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/10 19:56:19 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    randomChump( std::string name ) {
    
    // STACK: stores local variables - not allocated
    // creating zombie on the stack
    Zombie stackZombie(name);
    stackZombie.announce();
}