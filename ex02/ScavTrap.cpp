#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(), m_inGateKeeperMode(false) {
	std::cout << "Default ScavTrap Constructor called" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name), m_inGateKeeperMode(false) {
	std::cout << "ScavTrap Constructor called with name: " << name << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const& other)
	: ClapTrap(other), m_inGateKeeperMode(other.isInGateKeeperMode()) {
	std::cout << "ScavTrap Copy Constructor called: Creating ScavTrap Copy"
	<< std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called: "
	<< getName() << " shutdown" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	this->m_inGateKeeperMode = other.isInGateKeeperMode();
	return *this;
}

bool	ScavTrap::isInGateKeeperMode(void) const {
	return m_inGateKeeperMode;
}

void	ScavTrap::printStatus(void) const {
	ClapTrap::printStatus();
	std::cout
	<< "ScavTrap("
	<< "inGateKeeperMode=" << m_inGateKeeperMode << ")"
	<< std::endl;
}

void	ScavTrap::attack(std::string const& target) {
	if (!this->canAttack(target)) {
		return ;
	}
	if (this->m_inGateKeeperMode) {
		std::cout << "Guarding gates is fun. ";
	}
	std::cout
	<< "ScavTrap " << this->getName() << " attacks " << target << ", causing "
	<< this->getAttackDamage() << " points of damage!"
	<< std::endl;
	this->setEneryPoints(this->getEneryPoints() - 1);
}

void	ScavTrap::guardGate(void) {
	if (this->m_inGateKeeperMode) {
		std::cout
		<< "ScavTrap " << this->getName() << " already guards the gate"
		<< std::endl;
		return ;
	}
	std::cout
	<< "ScavTrap " << this->getName() << " now guards the gate"
	<< std::endl;
	this->m_inGateKeeperMode = true;
}
