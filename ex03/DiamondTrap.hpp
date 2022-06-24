#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	public:

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& other);
		~DiamondTrap(void);

		DiamondTrap&	operator=(DiamondTrap const& other);

		void	printStatus(void) const;

		void	attack(std::string const& target);
		void	whoAmI(void);

	private:

		std::string	m_name;
};

#endif
