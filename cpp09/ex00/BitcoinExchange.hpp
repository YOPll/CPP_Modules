#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <exception>
# include <fstream>
# include <sstream>
# include <algorithm>



class BitcoinExchange
{
	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange( std::string data);
		~BitcoinExchange();

		std::map<std::string, std::string> getExchange() const;
		int doExchange(char *path);
		void parseData(std::string data);

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

	class NotFoundException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class InvalidDataException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class Error : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	private:
		std::map<std::string, std::string> _exchange;


};


#endif /* ************************************************* BITCOINEXCHANGE_H */