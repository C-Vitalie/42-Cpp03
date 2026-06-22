/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vcucuiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:28:26 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 16:05:03 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	std::string		name;
	unsigned int	Hit_point;
	unsigned int	Energy_point;
	unsigned int	Attack_damage;
public:
	/* Constructor */
	FragTrap();
	FragTrap(std::string new_name);
	FragTrap(FragTrap const & src);

	/* Destructor */
	~FragTrap();
	
	/* Operator */
	FragTrap		&operator=(FragTrap const & src);

	/* Other */

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	unsigned int	get_Ep() const ;
	unsigned int	get_Hp() const ;
	unsigned int	get_Ad() const ;
	void			highFivesGuys(void);
};

#endif
