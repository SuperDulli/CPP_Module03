#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	testClapTrap(void);
void	testScavTrap(void);
void	testFragTrap(void);

int	main(void) {
	// testClapTrap();
	// std::cout << std::string(80, '-') << std::endl;
	// testScavTrap();
	// std::cout << std::string(80, '-') << std::endl;
	// testFragTrap();
	// std::cout << std::string(80, '-') << std::endl;
	{
		std::cout << std::string(80, '-') << std::endl;
		DiamondTrap diamond("DI4M0ND-TP");
		diamond.whoAmI();
		diamond.attack("Handsome Jack");
		diamond.takeDamage(42);
		diamond.printStatus();
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		std::cout << std::string(80, '-') << std::endl;
		DiamondTrap diamond("DI4");
		ClapTrap	ct;
		FragTrap	ft;
		ScavTrap	st;
		DiamondTrap	a;
		DiamondTrap	b(a);

		b.setName("COPY-DIAMOND-TP");
		ct = diamond;
		ft = diamond;
		st = diamond;

		ct.printStatus();
		ft.printStatus();
		st.printStatus();
		std::cout << std::string(80, '-') << std::endl;
	}
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
	ClapTrap	clappy("CL4P-TP");
	ClapTrap	ct;
	ScavTrap	a;
	ScavTrap	b(a);
	ScavTrap	scav("SC4V-TP");

	a = clappy;
	ct = scav;

	clappy.printStatus();
	ct.printStatus();
	a.printStatus();
	b.printStatus();
	scav.printStatus();
	std::cout << std::string(80, '-') << std::endl;

	scav.attack(clappy.getName());
	clappy.takeDamage(scav.getAttackDamage());
	scav.guardGate();
	scav.attack(clappy.getName());
	clappy.takeDamage(scav.getAttackDamage());
	scav.guardGate();
	scav.printStatus();
	std::cout << std::string(80, '-') << std::endl;
}

void	testFragTrap(void) {
	ClapTrap	clappy("CL4P-TP");
	ClapTrap	ct;
	FragTrap	a;
	FragTrap	b(a);
	FragTrap	frag("FR4G-TP");

	a = clappy;
	ct = frag;

	clappy.printStatus();
	ct.printStatus();
	a.printStatus();
	b.printStatus();
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
	clappy.printStatus();
	std::cout << std::string(80, '-') << std::endl;
}
