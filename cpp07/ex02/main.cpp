# include "Utils.hpp"

int main(void)
{
    Base    *ptr_b = generate();
    identify(ptr_b);


    //Base    &ref_b = *(generate());
    identify(*ptr_b);
   
    delete ptr_b; 
    //delete ref_b; 
    
    return (0);
}