/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vcucuiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:28:26 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 18:24:12 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	std::string		name;
	unsigned int	Hit_point;
	unsigned int	Energy_point;
	unsigned int	Attack_damage;
	bool			gate_kepper;
public:
	/* Constructor */
	ScavTrap();
	ScavTrap(std::string new_name);
	ScavTrap(ScavTrap const & src);

	/* Destructor */
	virtual ~ScavTrap();
	
	/* Operator */
	ScavTrap		&operator=(ScavTrap const & src);

	/* Other */

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	unsigned int	get_Ep(void) const ;
	unsigned int	get_Hp(void) const ;
	unsigned int	get_Ad(void) const ;
	void			guardGate();
};



#endif
