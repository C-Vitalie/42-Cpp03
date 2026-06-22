/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vcucuiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 00:05:52 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 18:53:31 by vcucuiet         ###   ########.fr       */
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
	ClapTrap();
	ClapTrap(std::string new_name);
	ClapTrap(ClapTrap const & src);

	/* Destructor */
	virtual ~ClapTrap();
	
	/* Operator */
	ClapTrap		&operator=(ClapTrap const & src);

	/* Other */

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	unsigned int	get_Ep(void) const ;
	unsigned int	get_Hp(void) const ;
	unsigned int	get_Ad(void) const ;
	std::string		get_name(void) const ;
};


#endif
