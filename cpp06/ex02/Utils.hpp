# ifndef UTILS_HPP
#  define UTILS_HPP

#  include <iostream>
#  include <exception>
#  include <string>
#  include <cstdlib>
#  include <ctime>
#  include "Base.hpp"
#  include "A.hpp"
#  include "B.hpp"
#  include "C.hpp"



Base * generate(void);
void identify(Base* p);
void identify(Base& p);
int generateRand(void);

# endif /* ****************************************************** UTILS_H */
