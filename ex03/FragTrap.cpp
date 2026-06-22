/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcucuiet <vita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:28:08 by vcucuiet          #+#    #+#             */
/*   Updated: 2026/06/22 22:35:17 by vcucuiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("") {
	this->Hit_point = 100;
	this->Energy_point = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap constructor called for :" << name << std::endl;	
}

FragTrap::FragTrap(const std::string new_name): ClapTrap(new_name) {
	this->Hit_point = 100;
	this->Energy_point = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap constructor called for :" << name << std::endl;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src.name) {
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	std::cout << "FragTrap constructor called for :" << name << std::endl;	
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called for :" << name << std::endl;	
}

FragTrap	& FragTrap::operator=(FragTrap const & src)
{
	this->name = src.name;
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (Energy_point == 0 || Hit_point == 0)
	{
		std::cout << "FragTrap " << name << " try to attack " << target << " but cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "FragTrap "  << name << " attacks " << target << " , causing "
		<< Attack_damage << " points of damage!" << std::endl;
	if (Energy_point > 0)
		Energy_point--;
	if (Energy_point < 1)
		std::cout << "FragTrap "  << name << " is out no more power!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap "  << name << " take " << amount << " of damage!" << std::endl;
	if (Hit_point == 0)
		return ;
	if (Hit_point - amount > Hit_point) {
		Hit_point = 0;
		std::cout << "FragTrap "  << name << " is out no more Hit_point!" << std::endl;
		return ;
	}
	Hit_point -= amount;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (Energy_point == 0 || Hit_point == 0)
	{
		std::cout << "FragTrap " << name << " cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "FragTrap "  << name << " bieing repared for " << amount
		<< " Hit point!" << std::endl;
	Hit_point += amount;
	if (Energy_point > 0)
		Energy_point--;
	if (Energy_point < 1)
		std::cout << "FragTrap "  << name << " is out no more power!" << std::endl;
}

unsigned int	FragTrap::get_Ep() const {
	return (this->Energy_point);
}
unsigned int	FragTrap::get_Hp() const {
	return (this->Hit_point);
}
unsigned int	FragTrap::get_Ad() const {
	return (this->Attack_damage);
}

void	FragTrap::highFivesGuys(void) {
	if(!Hit_point || !Energy_point)
	{
		std::cout << "FragTrap try to high fives but cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " and other CrapTrap make an high fives !!!" << std::endl;
}
