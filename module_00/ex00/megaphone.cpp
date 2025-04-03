#include <iostream>
#include <string>
#include <cctype>

void	to_upper(std::string str)
{
	int	i;
	char	upper;

	for (i = 0; i < str.length(); i++)
	{
		upper = (char)std::toupper(str[i]);
		std::cout << upper;

	}
}

int	main(int ac, char **av)
{
	int i = 1;
	if (ac > 1)
	{
		while (av[i] != NULL)
		{
			to_upper(av[i]);
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
