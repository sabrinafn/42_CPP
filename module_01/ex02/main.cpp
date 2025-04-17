/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:48:25 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/15 14:48:27 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void) {

    // Initializing variables
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "=================================================================================" << std::endl;
    std::cout << "| " << std::left << std::setw(23) << "Identifier"
              << "| " << std::left << std::setw(21) << "Memory Address"
              << "| " << std::left << std::setw(30) << "Value Pointed to by Variable" << "|" << std::endl;
    std::cout << "=================================================================================" << std::endl;

    std::cout << "| " << std::left << std::setw(23) << "stringVariable"
              << "| " << std::left << std::setw(21) << &str
              << "| " << std::left << std::setw(30) << str << "|" << std::endl;
    std::cout << "=================================================================================" << std::endl;
    
    std::cout << "| " << std::left << std::setw(23) << "stringPTR"
              << "| " << std::left << std::setw(21) << &stringPTR
              << "| " << std::left << std::setw(30) << stringPTR << "|" << std::endl;
    std::cout << "=================================================================================" << std::endl;
    
    std::cout << "| " << std::left << std::setw(23) << "stringREF"
              << "| " << std::left << std::setw(21) << &stringREF
              << "| " << std::left << std::setw(30) << stringREF << "|" << std::endl;
    std::cout << "=================================================================================" << std::endl;
     
    return 0;
}
