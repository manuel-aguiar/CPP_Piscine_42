/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 12:53:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
/*
int	main()
{
	//Animal	hey;
	Cat		hithere;
	Dog		hello;

	return (0);
}


void	half_cat_half_dog_new_speak_delete(unsigned int number)
{
	Animal** everyone = new (std::nothrow) Animal* [number];
	unsigned int i;

	for (i = 0; i < number / 2; i++)
		everyone[i] = new (std::nothrow) Cat();
	while (i < number)
		everyone[i++] = new (std::nothrow) Dog();

	for (i = 0; i < number; i++)
		everyone[i]->makeSound();

	for (i = 0; i < number; i++)
		delete everyone[i];

	delete[] everyone;
}



int main5()
{
	half_cat_half_dog_new_speak_delete(10);

	return (0);
}
*/
int main()
{

	// deep copy test

	Cat first;

	first.getBrain()->setIdeas(10, "hello tretas");

	Cat second(first);

	first.getBrain()->setIdeas(10, "haha enganei te");

	std::cout << second.getBrain()->getIdeas(10) << std::endl;

	first.makeSound();

	Animal* cenas = new Cat();

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
