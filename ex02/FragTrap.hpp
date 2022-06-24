#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const& other);
		~FragTrap(void);

		FragTrap&	operator=(FragTrap const& other);

		void	printStatus(void) const;

		void	attack(std::string const& target);
		void	highFiveGuys(void);

};

#endif
