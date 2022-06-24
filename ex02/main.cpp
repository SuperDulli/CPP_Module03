#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	testClapTrap(void);
void	testScavTrap(void);

int	main(void) {
	// testClapTrap();
	// std::cout << std::string(80, '-') << std::endl;
	// testScavTrap();
	// std::cout << std::string(80, '-') << std::endl;

	ClapTrap	clappy("CL4P-TP");
	ClapTrap	ct;
	FragTrap	a;
	FragTrap	b(a);
	FragTrap	frag("FR4G-TP");

	ct = frag;

	std::cout << "clappy: " << std::endl;
	clappy.printStatus();
	std::cout << "ct: " << std::endl;
	ct.printStatus();
	std::cout << "a: " << std::endl;
	a.printStatus();
	std::cout << "b: " << std::endl;
	b.printStatus();
	std::cout << "frag: " << std::endl;
	frag.printStatus();
	std::cout << std::string(80, '-') << std::endl;

	frag.attack(clappy.getName());
	clappy.takeDamage(frag.getAttackDamage());
	frag.attack(clappy.getName());
	clappy.takeDamage(frag.getAttackDamage());
	frag.printStatus();
	frag.highFiveGuys();
	frag.printStatus();
	std::cout << std::string(80, '-') << std::endl;

	frag.setEneryPoints(0);
	frag.attack(clappy.getName());
	frag.highFiveGuys();
	frag.attack(clappy.getName());
	clappy.takeDamage(frag.getAttackDamage());
	frag.printStatus();
	std::cout << "clappy: " << std::endl;
	clappy.printStatus();

	return 0;
}

void	testClapTrap(void) {
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

void	testScavTrap(void) {
	std::cout << std::string(80, '-') << std::endl;
	ClapTrap	clappy("CL4P-TP");
	ClapTrap	ct;
	ScavTrap	a;
	ScavTrap	b(a);
	ScavTrap	scav("SC4V-TP");

	ct = scav;

	std::cout << "clappy: " << std::endl;
	clappy.printStatus();
	std::cout << "ct: " << std::endl;
	ct.printStatus();
	std::cout << "a: " << std::endl;
	a.printStatus();
	std::cout << "b: " << std::endl;
	b.printStatus();
	std::cout << "scav: " << std::endl;
	scav.printStatus();
	std::cout << std::string(80, '-') << std::endl;

	scav.attack(clappy.getName());
	clappy.takeDamage(scav.getAttackDamage());
	scav.guardGate();
	scav.attack(clappy.getName());
	clappy.takeDamage(scav.getAttackDamage());
	scav.guardGate();
	std::cout << "scav: " << std::endl;
	scav.printStatus();
}
