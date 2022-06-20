#include <string>
#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap() {
	std::cout << "Default DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name", 100, 50, 30),
	FragTrap(name),
	ScavTrap(name),
	m_name(name) {
	std::cout << "DiamondTrap Constructor called with name: " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other):
	ClapTrap(other.getName() + "_clap_name", 100, 50, 30),
	FragTrap(other.getName()),
	ScavTrap(other.getName()),
	m_name(other.getName()) {
	std::cout << "DiamondTrap Copy Constructor called: Creating DiamondTrap Copy"
	<< std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called: "
	<< m_name << " shutdown" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	DiamondTrap();
	this->m_name = other.getName();
	return *this;
}

DiamondTrap&	DiamondTrap::operator=(ClapTrap const& other) {
	std::cout << "DiamondTrap copy assignment operator called with a ClapTrap" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

void	DiamondTrap::printStatus(void) const {
	ClapTrap::printStatus();
	std::cout << "DiamondTrap("
	<< "name=" << m_name << ")"
	<< std::endl;
}

void	DiamondTrap::attack(std::string const& target) {
	if (!this->canAttack(target)) {
		return ;
	}
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My DiamondTrap name is " << this->m_name
	<< " and my ClapTrap name is " << ClapTrap::getName() << "."
	<< std::endl;
}
