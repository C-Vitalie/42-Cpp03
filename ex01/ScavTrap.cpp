/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:28:08 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 22:33:32 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("") {
	this->Hit_point = 100;
	this->Energy_point = 50;
	this->Attack_damage = 20;
	this->gate_kepper = false;
	std::cout << "ScavTrap constructor called for :" << name << std::endl;	
}

ScavTrap::ScavTrap(const std::string new_name): ClapTrap(new_name) {
	this->Hit_point = 100;
	this->Energy_point = 50;
	this->Attack_damage = 20;
	this->gate_kepper = false;
	std::cout << "ScavTrap constructor called for :" << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src.name) {
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	std::cout << "ScavTrap constructor called for :" << name << std::endl;	
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called for :" << name << std::endl;	
}

ScavTrap	& ScavTrap::operator=(ScavTrap const & src)
{
	this->name = src.name;
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (Energy_point == 0 || Hit_point == 0)
	{
		std::cout << "ScavTrap " << name << " try to attack " << target << " but cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap "  << name << " attacks " << target << " , causing "
		<< Attack_damage << " points of damage!" << std::endl;
	if (Energy_point > 0)
		Energy_point--;
	if (Energy_point < 1)
		std::cout << "ScavTrap "  << name << " is out no more power!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap "  << name << " take " << amount << " of damage!" << std::endl;
	if (Hit_point == 0)
		return ;
	if (Hit_point - amount > Hit_point) {
		Hit_point = 0;
		std::cout << "ScavTrap "  << name << " is out no more Hit_point!" << std::endl;
		return ;
	}
	Hit_point -= amount;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (Energy_point == 0 || Hit_point == 0)
	{
		std::cout << "ScavTrap " << name << " cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap "  << name << " bieing repared for " << amount
		<< " Hit point!" << std::endl;
	Hit_point += amount;
	if (Energy_point > 0)
		Energy_point--;
	if (Energy_point < 1)
		std::cout << "ScavTrap "  << name << " is out no more power!" << std::endl;
}

unsigned int	ScavTrap::get_Ep(void) const {
	return (this->Energy_point);
}
unsigned int	ScavTrap::get_Hp(void) const {
	return (this->Hit_point);
}
unsigned int	ScavTrap::get_Ad(void) const {
	return (this->Attack_damage);
}

void	ScavTrap::guardGate() {
	if(!Hit_point || !Energy_point)
	{
		std::cout << "ScavTrap "<< name << " try to change his Gate keeper statut but can't (no energy or no hit points left)!" << std::endl;
		return ;
	}
	if (!gate_kepper) {
		std::cout << " ScavTrap " << name << " Gate keeper mode activated." << std::endl;
		gate_kepper = true;
	}
	else
	{
		std::cout << " ScavTrap " << name << " Gate keeper mode desactivated." << std::endl;
		gate_kepper = false;
	}
}
