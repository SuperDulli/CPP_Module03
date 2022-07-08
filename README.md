# CPP_Module03
Inheritance

## ex00: Aaaaaaand... OPEN!

create the base class for the next exercises

### ClapTrap class:

attributes:
- name
- hit points (hp) (10)
- energy points (ep) (10)
- attack damage (0)

member functions:
- `void attack(std::string const& target)`
- `void takeDamage(unsigned int amount)`
- `void beRepaired(unsigned int amount)`

Attacking and repairing costs one energy point each.
If ClapTrap has no hp or ep left he can't do anything.

## ex01: Serena, my love!

### ScavTrap class:

inherits from ClapTrap and prints diffrent messages in its Constructor/Destructor and attack() function.

attributes:
- inGuardKeeperMode

member functions:
- `void guardGate(void)`

## ex02: Repetive work

basicly ex01

### FragTrap class

inherits from ClapTrap and prints diffrent messages in its Constructor/Destructor and attack() function.

member functions:
- `void highFiveGuys(void)`


## ex03: Now it's weird!

solve the problems of Diamond inheritance

### DiamondTrap class:

It inherits from both ScavTrap and FragTrap. This creates a problem because they are both derived from ClapTrap, so the ClapTrap constructor would get called twice when instantiating a DiamondTrap.

To solve this Scav- and FragTrap will inhertit in a **virtual** way from ClapTrap. Then the ClapTrap object is only build once.

For its attack function it will use the implementation of the ScavTrap.

The *scope resulution operator* **::** is used to alot in this excercise to use the symbol from the right Parent class.

attributes:
- name (with the same variable name as in the ClapTrap class)

member functions:
- `void whoAmI(void)` - prints out the value of its name attribute and then the one of the ClapTraps, which ends in "_clap_name".
