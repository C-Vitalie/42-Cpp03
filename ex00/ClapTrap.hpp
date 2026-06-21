/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 00:05:52 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 01:29:49 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	Hit_point;
	unsigned int	Energy_point;
	unsigned int	Attack_damage;
public:
	/* Constructor */
	ClapTrap(void);
	ClapTrap(std::string new_name);
	ClapTrap(ClapTrap const & src);

	/* Destructor */
	~ClapTrap();
	
	/* Operator */
	ClapTrap		&operator=(ClapTrap const & src);

	/* Other */

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	unsigned int	get_Ep(void) const ;
	unsigned int	get_Hp(void) const ;
	unsigned int	get_Ad(void) const ;
};


#endif
