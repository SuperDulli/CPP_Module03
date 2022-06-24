#include <string>
#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("_clap_name"), FragTrap(), ScavTrap() {
	std::cout << "Default DiamondTrap Constructor called" << std::endl;
	m_hitPoints = FragTrap::getHitPoints();
	m_energyPoints = ScavTrap::getEneryPoints();
	m_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	FragTrap(),
	ScavTrap(),
	m_name(name) {
	std::cout << "DiamondTrap Constructor called with name: " << name << std::endl;
	m_hitPoints = FragTrap::getHitPoints();
	m_energyPoints = ScavTrap::getEneryPoints();
	m_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(DiamondTrap const& other):
	ClapTrap(other),
	FragTrap(other),
	ScavTrap(other),
	m_name(other.m_name) {
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
	this->m_name = other.m_name;
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
	std::string toBe = " is ";
	if (!this->isAlive()) {
		toBe = " was ";
	}
	std::cout << "My DiamondTrap name" << toBe << this->m_name
	<< " and my ClapTrap name" << toBe << ClapTrap::m_name << "."
	<< std::endl;
}
