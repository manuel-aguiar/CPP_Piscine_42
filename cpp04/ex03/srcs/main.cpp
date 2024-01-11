/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:44 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 12:09:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"
#include "../incs/Ice.hpp"
#include "../incs/Cure.hpp"
#include "../incs/Character.hpp"
#include "../incs/MateriaSource.hpp"


int	main()
{
	ICharacter* me = new Character("juau");

	me->print_stats();
	me->equip(new Ice());
	me->print_stats();

	Character hey("antónio");
	hey.equip(new Cure());
	Character hello(hey);

	hello.rename("cenas");
	hello.print_stats();

	hey.print_stats();
	hey = hello;
	hey.print_stats();

	AMateria *save = hey.getSlot(0);

	hey.unequip(0);
	hey.print_stats();

	delete save;
	delete me;

	return (0);
}

/*
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
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
*/
