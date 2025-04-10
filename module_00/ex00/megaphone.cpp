/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:08:47 by sabrifer          #+#    #+#             */
/*   Updated: 2025/04/09 15:08:54 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	to_upper(std::string str)
{
	int		i;
	char	upper;

	for (i = 0; i < (int)str.length(); i++)
	{
		upper = (char)std::toupper(str[i]);
		std::cout << upper;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; av[i]; i++)
			to_upper(av[i]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
