
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string		name;
public:
	/* Constructor */
	DiamondTrap();
	DiamondTrap(std::string new_name);
	DiamondTrap(DiamondTrap const & src);

	/* Destructor */
	~DiamondTrap();
	
	/* Operator */
	DiamondTrap		&operator=(DiamondTrap const & src);

	/* Other */
	using			ScavTrap::attack;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	unsigned int	get_Ep() const ;
	unsigned int	get_Hp() const ;
	unsigned int	get_Ad() const ;
	void 			whoAmI();
};

#endif
