#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& other);
		~ScavTrap(void);

		ScavTrap&	operator=(ScavTrap const& other);

		bool	isInGateKeeperMode(void) const;

		void	printStatus(void) const;

		void	attack(std::string const& target);
		void	guardGate(void);

	private:

		bool	m_inGateKeeperMode;

};

#endif
