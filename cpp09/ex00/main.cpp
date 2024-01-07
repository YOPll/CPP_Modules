# include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    try
    {
        BitcoinExchange exchange;
        if (argc != 2)
        {   
            std::cout << "Usage: ./btc [filename]" << std::endl;
            return 1;
        }
        return (exchange.doExchange(argv[1]));
    }
    catch(BitcoinExchange::Error &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}