#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {
	std::cout << "Default ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0) {
	std::cout << "ClapTrap Constructor called with name: " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other):
	m_name(other.getName()),
	m_hitPoints(other.getHitPoints()),
	m_energyPoints(other.getEneryPoints()),
	m_attackDamage(other.getAttackDamage()) {
	std::cout << "ClapTrap Copy Constructor called: Creating ClapTrap Copy"
	<< std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called: "
	<< getName() << " shutdown" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->m_name = other.getName();
	this->m_hitPoints = other.getHitPoints();
	this->m_energyPoints = other.getEneryPoints();
	this->m_attackDamage = other.getAttackDamage();
	return *this;
}

std::string	ClapTrap::getName(void) const { return m_name; }

unsigned int ClapTrap::getHitPoints(void) const { return m_hitPoints; }

unsigned int ClapTrap::getEneryPoints(void) const { return m_energyPoints; }

unsigned int ClapTrap::getAttackDamage(void) const { return m_attackDamage; }

void	ClapTrap::setName(std::string name) { this->m_name = name; }

void	ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->m_hitPoints = hitPoints;
}

void	ClapTrap::setEneryPoints(unsigned int energyPoints) {
	this->m_energyPoints = energyPoints;
}
void	ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->m_attackDamage = attackDamage;
}

bool	ClapTrap::isAlive(void) const {
	return (m_hitPoints > 0) ? true : false;
}

void	ClapTrap::printStatus(void) const {
	if (!isAlive()) {
		std::cerr << "ClapTrap " << m_name << " is dead." << std::endl;
	} else if (m_energyPoints < 1) {
		std::cerr << "ClapTrap " << m_name << " has no energy." << std::endl;
	}
	std::cout
	<< "ClapTrap("
	<< "name=" << m_name << ", "
	<< "hp=" << m_hitPoints << ", "
	<< "energy=" << m_energyPoints << ", "
	<< "dmg=" << m_attackDamage << ")"
	<< std::endl;
}

void	ClapTrap::attack(std::string const& target) {
	if (!this->canAttack(target)) {
		return ;
	}
	std::cout
	<< "ClapTrap " << this->m_name << " attacks " << target << ", causing "
	<< this->m_attackDamage << " points of damage!"
	<< std::endl;
	this->m_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->canTakeDamage(amount)) {
		return ;
	}
	std::cout
	<< "ClapTrap " << this->m_name << " takes " << amount << " points of damage."
	<< std::endl;
	this->m_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->canBeRepaired()) {
		return ;
	}
	std::cout
	<< "ClapTrap " << this->m_name
	<< " is being repaired and receives" << amount << " health."
	<< std::endl;
	this->m_energyPoints--;
}

bool	ClapTrap::canAttack(std::string const& target) const {
	if (!isAlive() || m_energyPoints < 1) {
		std::cerr << this->m_name << " can't attack " << target << ": ";
		printStatus();
		return false;
	}
	if (target.empty()) {
		std::cerr << m_name << " can't attack: No target" << std::endl;
		return false;
	}
	return true;
}

bool	ClapTrap::canTakeDamage(unsigned int& amount) const {
	if (!isAlive()) {
		std::cerr << m_name << " can't take damage: ";
		printStatus();
		return false;
	}
	if (amount > this->m_hitPoints) {
		unsigned int const	diff = amount - m_hitPoints;
		std::cout << "OVERKILL by " << diff << " points. ";
		amount -= diff;
	}
	return true;
}

bool	ClapTrap::canBeRepaired(void) const {
	if (!isAlive() || m_energyPoints < 1) {
		std::cerr << m_name << " can't be repaired: ";
		printStatus();
		return false;
	}
	return true;
}
