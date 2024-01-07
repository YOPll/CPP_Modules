#include "Harl.hpp"

int main()
{
    Harl obj;
    // invalid level
    obj.complain("LOL");
    // debug level
    obj.complain("DEBUG");
    // info level
    obj.complain("INFO");
    // warning level
    obj.complain("WARNING");
    // error level
    obj.complain("ERROR");

}