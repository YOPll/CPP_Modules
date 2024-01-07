#include "Contact.hpp"

void	Contact::setfirstName(std::string firstName)
{
	this->firstName = firstName;
}

std::string	Contact::getfirstName()
{
	return this->firstName;
}

void	Contact::setlastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string	Contact::getlastName()
{
	return this->lastName;
}

void	Contact::setnickName(std::string nickName)
{
	this->nickName = nickName;
}

std::string	Contact::getnickName()
{
	return this->nickName;
}

void	Contact::setphoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string	Contact::getphoneNumber()
{
	return this->phoneNumber;
}

void	Contact::setdarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getdarkestSecret()
{
	return this->darkestSecret;
}
