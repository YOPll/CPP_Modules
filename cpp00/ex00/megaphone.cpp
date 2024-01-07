#include <iostream>

int	main(int ac, char**av)
{
	int i = 0;
	int j = -1;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (av[++i])
		{
			j = -1;
			while(av[i][++j])
			{
				av[i][j] = toupper(av[i][j]);
			}
			std::cout << av[i];
		}
	}
	return (0);
}