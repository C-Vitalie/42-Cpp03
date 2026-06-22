#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name"), ScavTrap(""), FragTrap(""), name("") {
	this->Hit_point = 100;
	this->Energy_point = 50;
	this->Attack_damage = 30;
	std::cout << "DiamondTrap constructor called for :" << name << std::endl;	
}

DiamondTrap::DiamondTrap(const std::string new_name): ClapTrap(new_name + "_clap_name"),
ScavTrap(new_name), FragTrap(new_name), name(new_name){
	this->Hit_point = 100;
	this->Energy_point = 50;
	this->Attack_damage = 30;
	std::cout << "DiamondTrap constructor called for :" << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src.name + "_clap_name"),
ScavTrap(src.name), FragTrap(src.name), name(src.name){
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	std::cout << "DiamondTrap constructor called for :" << name << std::endl;	
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called for :" << name << std::endl;	
}

DiamondTrap	& DiamondTrap::operator=(DiamondTrap const & src)
{
	this->name = src.name;
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << "DiamondTrap "  << name << " take " << amount << " of damage!" << std::endl;
	if (Hit_point == 0)
		return ;
	if (Hit_point - amount > Hit_point) {
		Hit_point = 0;
		std::cout << "DiamondTrap "  << name << " is out no more Hit_point!" << std::endl;
		return ;
	}
	Hit_point -= amount;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (Energy_point == 0 || Hit_point == 0)
	{
		std::cout << "DiamondTrap " << name << " cannot do anything (no energy or no hit points left)!" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap "  << name << " bieing repared for " << amount
		<< " Hit point!" << std::endl;
	Hit_point += amount;
	if (Energy_point > 0)
		Energy_point--;
	if (Energy_point < 1)
		std::cout << "DiamondTrap"  << name << "is out no more power!" << std::endl;
}

unsigned int	DiamondTrap::get_Ep() const {
	return (this->Energy_point);
}

unsigned int	DiamondTrap::get_Hp() const {
	return (this->Hit_point);
}

unsigned int	DiamondTrap::get_Ad() const {
	return (this->Attack_damage);
}

void	DiamondTrap::whoAmI(){
	std::cout << "Hi i'm " << name << " aka " << ClapTrap::get_name() << std::endl;
}