#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <string>
#include <iomanip>

class ScalarConverter
{

	public:
		static void convert(std::string str);
		static void convertTc(std::string str);
		static void convertTi(std::string str);
		static void convertTf(std::string str);
		static void convertTd(std::string str);

};

#endif /* ************************************************* SCALARCONVERTER_H */