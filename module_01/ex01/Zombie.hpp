/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:56:41 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/10 19:56:42 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name);
        ~Zombie();
        void    announce( void ) const;
};         

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif