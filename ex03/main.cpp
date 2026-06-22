/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 00:37:06 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 22:53:55 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	FragTrap	Rakel("Rakel");
	ScavTrap	Alberto("Alberto");
	DiamondTrap	Franklin(" Franklin");
	int			Previous_rakel_Ep = Rakel.get_Ep();

	Franklin.whoAmI();
	Franklin.attack("aaaaaaaaaaaa");
	std::cout << "\n|| Welcome to the ACC (Amazing CrapTrap Combat) ||\n" << std::endl;
	Alberto.guardGate();
	Rakel.highFivesGuys();
	for (int i = 0; i < 22; i++)
	{
		std::cout << "\n~~!!!Round " << i + 1 << " Started!!!~~\n" << std::endl;
		Rakel.attack("Alberto");
		if (Previous_rakel_Ep != 0)
			Alberto.takeDamage(Rakel.get_Ad());
		Previous_rakel_Ep = Rakel.get_Ep();
		if (i % 2)
			Alberto.beRepaired(1);
		Franklin.attack("AAAAAAAAAA");
		std::cout << "\n~~!!!Round " << i + 1 << " Finished!!!~~\n" << std::endl;
	}
	std::cout << "\n|| See you next time at the ACC ||\n" << std::endl;

	return (0);
}