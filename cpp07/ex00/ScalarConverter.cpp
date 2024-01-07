#include "ScalarConverter.hpp"

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScalarConverter::convert(std::string str)
{
	convertTc(str);
	convertTi(str);
	convertTf(str);
	convertTd(str);
}

void ScalarConverter::convertTc(std::string str)
{
	char c = 0;
	int i = 0;
	std::istringstream S(str);

	if (S >> i)
	{
		c = static_cast<char>(i);
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		if (str.length() == 1 && !isdigit(str[0]))
		{
			c = str[0];
			if (isprint(c))
				std::cout << "char: '" << c << "'"<< std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::convertTi(std::string str)
{
	int i;
	std::istringstream S(str);
	if (S >> i)
		std::cout << "int: " << i << std::endl;
	else
	{
		if (str.length() == 1 && !isdigit(str[0]))
		{
			i = static_cast<int>(str[0]);
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		}
		else
			std::cout << "int: impossible" << std::endl;
	}
}

void	ScalarConverter::convertTf(std::string str)
{
	int i;
	float f;
	std::istringstream S(str);

	if (str.length() == 1 && !isdigit(str[0]))
	{
		i = static_cast<int>(str[0]);
		f = static_cast<float>(i);
	}
	else
		f = static_cast<float>(atof(str.c_str()));
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" <<  std::endl;
}

void ScalarConverter::convertTd(std::string str)
{
	int i;
	float f;
	std::istringstream S(str);

	if (str.length() == 1 && !isdigit(str[0]))
	{
		i = static_cast<int>(str[0]);
		f = static_cast<float>(i);
	}
	else
		f = static_cast<float>(atof(str.c_str()));
	double d = static_cast<double>(f);
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}


/* ************************************************************************** */