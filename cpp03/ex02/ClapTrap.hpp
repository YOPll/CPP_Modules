#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define MAX_UNSIGNED_INT 4294967295

# include <iostream>
# include <string>

class ClapTrap
{

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();
		ClapTrap &		operator=( ClapTrap const & rhs );


		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string 	name;
		unsigned int	Hit_points;
		unsigned int	Energy_points;
		unsigned int	Attack_damage;

};

#endif /* ******************************************************** CLAPTRAP_H */