/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vcucuiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 00:11:46 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 12:24:42 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), Hit_point(10),
Energy_point(10), Attack_damage(0) {
	std::cout << "ClapTrap constructor called for :" << name << std::endl;	
}

ClapTrap::ClapTrap(std::string new_name): name(new_name), Hit_point(10),
Energy_point(10), Attack_damage(0) {
	std::cout << "ClapTrap constructor called for :" << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src): name(src.name), Hit_point(src.Hit_point),
Energy_point(src.Energy_point), Attack_damage(src.Attack_damage) {
	std::cout << "ClapTrap constructor called for :" << name << std::endl;	
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called for :" << name << std::endl;	
}

ClapTrap	& ClapTrap::operator=(ClapTrap const & src)
{
	this->name = src.name;
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (Energy_point == 0 || Hit_point == 0)
	{
		std::cout << "ClapTrap " << name << " try to attack " << target << " but cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap "  << name << " attacks " << target << " , causing "
		<< Attack_damage << " points of damage!" << std::endl;
	if (Energy_point > 0)
		Energy_point--;
	if (Energy_point < 1)
		std::cout << "ClapTrap "  << name << " is out no more power!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap "  << name << " take " << amount << " of damage!" << std::endl;
	if (Hit_point == 0)
		return ;
	if (Hit_point - amount > Hit_point) {
		Hit_point = 0;
		std::cout << "ClapTrap "  << name << " is out no more Hit_point!" << std::endl;
		return ;
	}
	Hit_point -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_point == 0 || Hit_point == 0)
	{
		std::cout << "ClapTrap " << name << " cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap "  << name << " bieing repared for " << amount
		<< " Hit point!" << std::endl;
	Hit_point += amount;
	if (Energy_point > 0)
		Energy_point--;
	if (Energy_point < 1)
		std::cout << "ClapTrap "  << name << " is out no more power!" << std::endl;
}

unsigned int	ClapTrap::get_Ep(void) const {
	return (this->Energy_point);
}
unsigned int	ClapTrap::get_Hp(void) const {
	return (this->Hit_point);
}
unsigned int	ClapTrap::get_Ad(void) const {
	return (this->Attack_damage);
}
