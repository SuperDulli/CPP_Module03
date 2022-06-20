#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& other);
		~ClapTrap(void);

		ClapTrap&	operator=(ClapTrap const& other);

		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEneryPoints(void) const;
		unsigned int	getAttackDamage(void) const;

		void	setName(std::string name);
		void	setHitPoints(unsigned int hitPoints);
		void	setEneryPoints(unsigned int energyPoints);
		void	setAttackDamage(unsigned int attackDamage);

		bool	isAlive(void) const;

		void	printStatus(void) const;

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:

		std::string		m_name;
		unsigned int	m_hitPoints;
		unsigned int	m_energyPoints;
		unsigned int	m_attackDamage;

};

#endif
