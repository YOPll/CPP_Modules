#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
	void	setfirstName(std::string firstName);
	std::string	getfirstName();
	void	setlastName(std::string lastName);
	std::string	getlastName();
	void	setnickName(std::string nickName);
	std::string	getnickName();
	void	setphoneNumber(std::string phoneNumber);
	std::string	getphoneNumber();
	void	setdarkestSecret(std::string darkestSecret);
	std::string	getdarkestSecret();
	private:
			std::string firstName;
			std::string lastName;
			std::string nickName;
			std::string phoneNumber;
			std::string darkestSecret;
};

#endif