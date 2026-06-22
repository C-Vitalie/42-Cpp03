/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vcucuiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 00:37:06 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 12:42:59 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Rakel("Rakel");
	ScavTrap	Alberto("Alberto");
	int			Previous_rakel_Ep = Rakel.get_Ep();

	std::cout << "\n|| Welcome to the ACC (Amazing ScavTrap Combat) ||\n" << std::endl;
	Rakel.guardGate();
	for (int i = 0; i < 22; i++)
	{
		std::cout << "\n~~!!!Round " << i + 1 << " Started!!!~~\n" << std::endl;
		Rakel.attack("Alberto");
		if (Previous_rakel_Ep != 0)
			Alberto.takeDamage(Rakel.get_Ad());
		Previous_rakel_Ep = Rakel.get_Ep();
		if (i % 2)
			Alberto.beRepaired(1);
		std::cout << "\n~~!!!Round " << i + 1 << " Finished!!!~~\n" << std::endl;
	}
	std::cout << "\n|| See you next time at the ACC ||\n" << std::endl;

	return (0);
}