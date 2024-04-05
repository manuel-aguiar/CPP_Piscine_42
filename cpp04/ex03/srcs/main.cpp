/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 11:51:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"
#include "../incs/Ice.hpp"
#include "../incs/Cure.hpp"
#include "../incs/Character.hpp"
#include "../incs/MateriaSource.hpp"


/*

	To be honest, the organization of this project sucks.
	There is no knowledge of memory ownership between MateriaSource.
	Character must destroy Amaterias when destroy
	And so does Materia Source

	Potential for double free is.... enormous.

	Virtual curiosity:
		virtual constructors and copy constructors are not allowed :0
		BUT: with "using" you can effective use inherited constructors
			just not put them in the vtable....? interesting, i dunno

*/

int	main1()
{
	ICharacter* me = new Character("juau");

	me->print_stats();
	me->equip(new Ice());
	me->print_stats();

	Character hey("antónio");
	hey.equip(new Cure());
	Character hello(hey);

	hello.setName("cenas");
	hello.print_stats();

	hey.print_stats();
	hey = hello;
	hey.print_stats();

	const AMateria *save = hey.getSlot(0);

	hey.unequip(0);
	hey.print_stats();

	delete save;
	delete me;

	return (0);
}


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");

	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	//Good polymorphism example, Amateria slot will adjust "this" pointer
	//and call the correct function in the vtable, either Amateria-in-Ice or Amateria-in-Cure
	//a lot of vtables going onnnn
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;

	delete src;

	//uff ugly, dangerous static cast, works because Character is using the same vptr as Icharacter x'D
	// don't do this, pls :)
	// bob think he is a Icharacter interface instance and not a Character instance
	Character antonio(*(Character *)me);

	AMateria *ice = new Ice;
	AMateria *cure = new Cure;

	const AMateria *save = ice;

	std::cout << "okay... copying Ice into Cure" << std::endl;
	*ice = *cure;

	std::cout << "hello?... :0 AMateria?? there is a catch... ;)" << std::endl;

	/*
		Here, we are copying the Amateria-in-Cure to AMateria-in-Ice. The AMateria
		copy/assignment is not on the vtable and is resolved statically.
		No "this" pointer adjustment is needed, because "this" will be AMateria-in-Ice/Cure
		itself, copying its subobject safely.

		Virtual only comes into play when two functions have the exact same prototype
		AMateria operator=, virtual or not, doesn't get overriden by Ice's and Cure's
		because the prototype is different.
			Vtables are constructed because there are explicit overrides from parent to child

		Ice and Cure need AMateria operator= to be able to copy the AMateria subobject inside
		of them

		AMateria::operator=(assign);
			-> good example, assign is type Ice, how come we can pass it? Compiler resolves,
			Ice knows where AMateria subobject-in-Ice is directly from the "this" pointer,
			apply offset known at compile time to get to AMaterria's "this"
				this is a "this" operator adjustment but not of the runtime type
				this can be calculated at compile time safely
				AAAND, there is no vtable involved here, static dispatch

	*/

	delete me;
	delete cure;
	delete save;

	return (0);
}

