#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
	try
	{
		parseData("data.csv");
	}
	catch(const BitcoinExchange::NotFoundException& e)
	{
		std::cerr << e.what() << std::endl;
		throw BitcoinExchange::Error();
	}
	catch(BitcoinExchange::InvalidDataException &e)
	{
		std::cerr << e.what() << std::endl;
		throw BitcoinExchange::Error();
	}
}

BitcoinExchange::BitcoinExchange( std::string data)
{
	try
	{
		parseData(data);
	}
	catch(const BitcoinExchange::NotFoundException & e)
	{
		std::cerr << e.what() << std::endl;
		throw BitcoinExchange::Error();
	}
	catch(BitcoinExchange::InvalidDataException &e)
	{
		std::cerr << e.what() << std::endl;
		throw BitcoinExchange::Error();
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->_exchange = rhs.getExchange();
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

static bool isNumbers(std::string str)
{
  bool hasDecimal = false;
  size_t size = str.length();

  for (size_t i = 0; i < size; i++)
  {
    if (!isdigit(str[i]))
    {
      if (str[i] == '-' || str[i] == '+')
      {
        if (i != 0)
          return false;
      }
      else if (str[i] == '.')
      {
        if (hasDecimal || i == size - 1)
          return false;
        hasDecimal = true;
      }
      else
        return false;
    }
  }
  return true;
}

bool parsedate(std::string data)
{
    std::string year;
    std::string month;
    std::string day;
    size_t i = 0;
    size_t j = 0;

    if (data.length() != 10)
        return false;
    if ((data[4] != '-' || !isdigit(data[5])) || (data[7] != '-' || !isdigit(data[8])))
        return false;
    year = data.substr(0, 4);
    month = data.substr(5, 2);
    day = data.substr(8, 2);
    if (!isNumbers(year) || !isNumbers(month) || !isNumbers(day))
        return false;
    i = std::atoi(year.c_str());
    j = std::atoi(month.c_str());
    if (j < 1 || j > 12)
        return false;
    if (j == 2 && std::atoi(day.c_str()) > 29)
        return false;
    if (j == 4 || j == 6 || j == 9 || j == 11)
    {
        if (std::atoi(day.c_str()) > 30)
            return false;
    }
    else
    {
        if (std::atoi(day.c_str()) > 31)
            return false;
    }
    return true;
}

std::string getFile(std::string data)
{
	std::ifstream file(data);
	std::string str;
	std::string ret;
	if (!file.is_open() || data.find(".csv") == std::string::npos)
		ret = "";
	else
	{
		while (std::getline(file, str))
			{
				if (file.eof())
					break;

				ret += str;
				ret += "\n";
			}
			ret += str;
	}
	file.close();
	return ret;
}

void BitcoinExchange::parseData(std::string data)
{
	std::string file = getFile(data);
	std::string line;
	std::string key;
	std::string value;
	size_t i = 0;
	size_t j = 0;

	if (file.empty())
		throw NotFoundException();
	j = file.find("\n");
	file.erase(0, j + 1);

	while ((j = file.find("\n")) != std::string::npos)
	{
		line = file.substr(0, j);
		file.erase(0, j + 1);
		i = line.find(",");
		if (line.empty())
			throw InvalidDataException();
		key = line.substr(0, i);
		value = line.substr(i + 1, line.length());
		if (key.empty() || value.empty())
			throw InvalidDataException();
		this->_exchange[key] = value;
	}
}

int	BitcoinExchange::doExchange(char *path)
{
	int i = 0;
	FILE *fp= fopen(path, "r");
	float f;
	char date[100] , value[100];

	if (fp == NULL)
	{
		std::cout << "Error: File not found" << std::endl;
		return 1;
	}
	i = fscanf(fp, "%s | %s", date, value);
	if (strcmp(date, "date") || strcmp(value, "value") || i != 2)
	{
		std::cout << "Error: bad Header" << std::endl;
		// fclose(fp);
		// return (1);
	}
	while ((i = (fscanf(fp, "%s | %s\n", date, value))) != -1)
	{
		if (i != 2)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (parsedate(date) == false)
		{
			std::cout << "Error: bad date format" << std::endl;
			continue;
		}
		if (isNumbers(value) == false)
		{
			std::cout << "Error: Value has to be only digits" << std::endl;
			continue;
		}
		std::map<std::string, std::string>::iterator it = _exchange.lower_bound(date);

		if (std::atof(value) < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (std::atof(value) > 1000)
		{
			std::cout << "Error: Value is to Large" << std::endl;
			continue;
		}
		if (it != _exchange.begin() && it == _exchange.end())
		{
			--it;
			//std::cout << std::atof(it->second.c_str()) << " * " << it->second << std::endl;
			f = std::atof(value) * std::atof(it->second.c_str());
			std::cout << date << " => " << value << " = " << f << std::endl;
			//std::cout << date << " => " << value << " = " << f << std::endl;
		}
		else if (it == _exchange.end())
		{
			f = std::atof(value) * std::atof(it->second.c_str());
			std::cout << date << " => " << value << " = " << f << std::endl;
		}
		else 
		{
			f = std::atof(value) * std::atof(it->second.c_str());
			std::cout << date << " => " << value << " = " << f << std::endl;
		}
		memset(date, 0, 100);
		memset(value, 0, 100);
	}
	// std::map<std::string, std::string>::iterator yopi;
	// for (yopi = _exchange.begin(); yopi != _exchange.end(); yopi++) {
    //     std::cout << yopi->first << " : " << yopi->second << std::endl;
	// }

	fclose(fp);
	return 0;
}

const  char *BitcoinExchange::NotFoundException::what() const throw()
{
	return "Error: Data.csv not found";
}

const  char *BitcoinExchange::InvalidDataException::what() const throw()
{
	return "Error: Invalid data";
}

const  char *BitcoinExchange::Error::what() const throw()
{
	return "Program Has Stopped";
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::map<std::string, std::string> BitcoinExchange::getExchange() const
{
	return this->_exchange;
}


/* ************************************************************************** */