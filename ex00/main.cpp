#include <string>
#include <iostream>
#include "ClapTrap.hpp"

int	main(void) {
	{
		ClapTrap	a;
		ClapTrap	b(a);
		ClapTrap	npc;
		ClapTrap	dummy;
		ClapTrap	copyTrap;
		ClapTrap	clappy("CL4P-TP");

		npc = b;
		b.setName("1D-TP");
		b.setHitPoints(50);
		b.setEneryPoints(1);
		dummy.setName("CL4P-DUMMY");
		dummy.setHitPoints(2);
		copyTrap = b;
		npc.setName("CLAP-9000");
		npc.setAttackDamage(2);
		clappy.setAttackDamage(3);
		std::cout << std::string(80, '-') << std::endl;

		a.printStatus();
		b.printStatus();
		npc.printStatus();
		copyTrap.printStatus();
		clappy.printStatus();
		std::cout << std::string(80, '-') << std::endl;

		dummy.attack("CL4P-TP");
		clappy.takeDamage(dummy.getAttackDamage());
		clappy.attack("");
		clappy.attack(dummy.getName());
		dummy.takeDamage(clappy.getAttackDamage());
		clappy.attack(dummy.getName());
		dummy.takeDamage(clappy.getAttackDamage());
		dummy.attack(clappy.getName());
		dummy.beRepaired(1);
		npc.printStatus();
		clappy.printStatus();
		std::cout << std::string(80, '-') << std::endl;

		clappy.attack(b.getName());
		b.takeDamage(clappy.getAttackDamage());
		b.beRepaired(21);
		b.beRepaired(21);
		b.attack(clappy.getName());
		b.printStatus();
		clappy.printStatus();
		std::cout << std::string(80, '-') << std::endl;
	}
	return 0;
}
