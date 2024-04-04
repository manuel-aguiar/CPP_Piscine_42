/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/04 15:36:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{

	// deep copy test

	Cat first;
	first.getBrain()->setIdeas(10, "hello tretas");
	Cat second(first);
	first.getBrain()->setIdeas(10, "haha enganei te");
	std::cout << second.getBrain()->getIdeas(10) << std::endl;
	first.makeSound();
	Animal* cenas = new Dog();
	cenas->makeSound();
	delete cenas;

	/*

		Animal animall;

		the above will not compile, animal is an abstract class given it has at least one
		pure viirtual function

	*/


	return (0);
}
/*

int main3()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	const WrongAnimal* bad = new WrongCat();

	bad->makeSound();

	delete bad;

	return (0);
}


int main2()
{
	Animal	ani;
	Cat		queni;
	Dog		cati;

	ani.makeSound();
	queni.makeSound();
	cati.makeSound();

	return (0);
}
*/
