#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	std::cout << "Default FragTrap Constructor called" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap Constructor called with name: " << name << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const& other): ClapTrap(other) {
	std::cout << "FragTrap Copy Constructor called: Creating FragTrap Copy"
	<< std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called: "
	<< getName() << " shutdown" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const& other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

void	FragTrap::printStatus(void) const {
	ClapTrap::printStatus();
	std::cout << "FragTrap()" << std::endl;
}

void	FragTrap::attack(std::string const& target) {
	if (!this->canAttack(target)) {
		return ;
	}
	std::cout
	<< "FragTrap " << this->getName() << " attacks " << target << ", causing "
	<< this->getAttackDamage() << " points of damage!"
	<< std::endl;
	this->setEneryPoints(this->getEneryPoints() - 1);
}

void	FragTrap::highFiveGuys(void) {
	std::cout << "FragTrap " << this->getName() << " is offering a high five."
	<< std::endl;
	this->setEneryPoints(this->getEneryPoints() + 1);
}
