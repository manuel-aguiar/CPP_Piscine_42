/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:36:51 by codespace         #+#    #+#             */
/*   Updated: 2024/04/03 15:49:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main()
{
	/*

		Construction via VTT: construction vtable for [ancestor]-in-Child;
		Grandparent first, then parents;
		parents need the virtual-base offset in their construction vtable to
		access grandparent member variables and proceeed with construction

	*/


    DiamondTrap cenas;

	cenas.whoAmI();
	cenas.guardGate();
	cenas.highFivesGuys();

	ClapTrap *clap = &cenas;
	ScavTrap *scav = &cenas;
	FragTrap *frag = &cenas;

	/*

		Compiler simple pointer arithmatic, &cenas returns the correct offset
		of its subobject whose type matches the pointer dereference

		Notice grandparent address is higher than parents

		Sizeof a derived class is not the sum of the parts,
		there is padding, vptr optimization (reutilizing scavtrap as diamondtraps vtable)
		and more stuff
	*/

	/*
	Example of memory layout in virtual inheritance

		Size	Value
		8 bytes	_vptr$Parent1
		4 bytes	parent1_data (+ 4 bytes padding)
		8 bytes	_vptr$Parent2
		4 bytes	parent2_data
		4 bytes	child_data
		8 bytes	_vptr$Grandparent
		4 bytes	grandparent_data (+ 4 bytes padding)

		Child vtable ptr = parent1 vtable ptr, saves one vtable ptr


	*/

	std::cout << "clap subobject: " << clap << std::endl;
	std::cout << "scav subobject: " << scav << std::endl;
	std::cout << "frag subobject: " << frag << std::endl;



	/*

		virtual destructors at all levels allow "this" pointer adjustment
		via vtable (vptr - 16), DiamondTrap destructor is called instead of the pointer one
		non-virtual thunks everywhere, moving subobject to DiamondTrap and
		calling its destructor who destroys all subclasses

		Reverse order to construction, remember memory layout

	*/

	clap = new DiamondTrap;
	delete clap;
	scav = new DiamondTrap;
	delete scav;
	frag = new DiamondTrap;
	delete frag;




	/*
    potato.attack("antonio");
    potato.my_stats();
    potato.beRepaired(100);
    potato.my_stats();
    potato.attack("antonio");
    potato.my_stats();
    potato.takeDamage(3000);
    potato.my_stats();
    potato.beRepaired(100);
    potato.my_stats();
    potato.attack("antonio");
    potato.my_stats();

    ScavTrap cenas (potato);
    cenas.my_stats();
    cenas = potato;
    cenas.my_stats();
	*/

    return (0);
}
