# include <iostream>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR;
    stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "The memory address of the string variable -> " << &s << std::endl;
    std::cout << "The memory address held by stringPTR -> " << &stringPTR << std::endl;
    std::cout << "The memory address held by stringREF -> " << &stringREF << std::endl;

    std::cout << "The memory address of the string variable -> " << s << std::endl;
    std::cout << "The memory address held by stringPTR -> " << *stringPTR << std::endl;
    std::cout << "The memory address held by stringREF -> " << stringREF << std::endl;
}