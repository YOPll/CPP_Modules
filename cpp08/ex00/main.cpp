# include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    try
    {
        std::cout << easyfind(v, 5) << std::endl;
        std::cout << easyfind(v, 3) << std::endl;
        std::cout << easyfind(v, 9) << std::endl;
        std::cout << easyfind(v, 11) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
