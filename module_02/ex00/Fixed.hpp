/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:58:05 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/24 14:58:06 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed {

    private:
        int                 fixed_point_value;
        static const int    fractional_bits = 8;

    public:
        Fixed(); // constructor
        Fixed(const Fixed &other); // copy constructor
        Fixed &operator=(const Fixed &other); // copy assignment operator overload
        ~Fixed(); // destructor
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

};

#endif
