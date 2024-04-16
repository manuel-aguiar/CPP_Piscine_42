/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 14:18:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void	write_stdout(const char *str, const char *color)
{
	std::cout << color << str << CLR_RESET << std::endl;
}

void	half_cat_half_dog_new_speak_delete(unsigned int number)
{

	Animal** everyone = new (std::nothrow) Animal* [number];
	unsigned int i;

	for (i = 0; i < number / 2; i++)
		everyone[i] = new (std::nothrow) Cat();
	while (i < number)
		everyone[i++] = new (std::nothrow) Dog();

	std::cout << "\narray construction is complete!\n" << std::endl;

	for (i = 0; i < number; i++)
	{
		if (everyone[i])
			everyone[i]->makeSound();
	}


	for (i = 0; i < number; i++)
	{
		if (everyone[i])
			delete everyone[i];
	}

	delete[] everyone;

	std::cout << "\narray destruction is complete!\n" << std::endl;
}

int main1()
{
	half_cat_half_dog_new_speak_delete(10);

	return (0);
}

int main()
{
	{
		write_stdout("\n		deep copy test: CLASS INSTANCES\n", CLR_BLUE);
		Dog basic;

		std::cout << "deep copy test: copy constructor\n" << std::endl;

		basic.getBrain()->setIdeas(0, "cenas");
		{
			Dog tmp = basic;
			tmp.getBrain()->setIdeas(0, "tretas");
			std::cout << basic.getBrain()->getIdeas(0) << std::endl;
			if (basic.getBrain()->getIdeas(0) == tmp.getBrain()->getIdeas(0))
				write_stdout("same idea, tmp affected basic", CLR_RED);
			else
				write_stdout("different ideas, tmp changed own brain and didn't affect basic", CLR_GRN);
		}
	}
	{
		std::cout << "\ndeep copy test: copy assignment\n" << std::endl;
		Dog basic;

		basic.getBrain()->setIdeas(0, "cenas");
		{
			Dog tmp;

			tmp = basic;
			tmp.getBrain()->setIdeas(0, "tretas");
			std::cout << basic.getBrain()->getIdeas(0) << std::endl;
			if (basic.getBrain()->getIdeas(0) == tmp.getBrain()->getIdeas(0))
				write_stdout("same idea, tmp affected basic", CLR_RED);
			else
				write_stdout("different ideas, tmp changed own brain and didn't affect basic", CLR_GRN);
		}
	}

	{
		write_stdout("\n		deep copy test: BASE CLASS POINTERS\n", CLR_BLUE);
		Animal *dog = new Dog();
		Animal *cat = new Cat();

		dynamic_cast<Dog *>(dog)->getBrain()->setIdeas(0, "i am a dog");
		dynamic_cast<Cat *>(cat)->getBrain()->setIdeas(0, "i am a cat");

		delete dog;
		dog = cat;
		dog->makeSound();
		/*
			We are just changing pointers, you can't deep copy this.... :|
		*/
			write_stdout("Dog says", CLR_RESET);
			write_stdout(dynamic_cast<Cat *>(dog)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			write_stdout("Cat changes his mind", CLR_RESET);
			dynamic_cast<Cat *>(cat)->getBrain()->setIdeas(0, "i am a cat, miauuuuuuu");
			write_stdout("Dog says", CLR_RESET);
			write_stdout(dynamic_cast<Cat *>(dog)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			if (dynamic_cast<Cat *>(dog)->getBrain()->getIdeas(0) == dynamic_cast<Cat *>(cat)->getBrain()->getIdeas(0))
				write_stdout("same idea, cat affected dog, Bbut it should, dog holds a cat pointer in reality", CLR_GRN);
			else
				write_stdout("different ideas, tmp changed own brain and didn't affect basic, wrong, should be the same", CLR_RED);
		delete cat;
	}

	{
		write_stdout("\n		deep copy test: copy by derefencing POINTERS\n", CLR_BLUE);
		Animal *dog = new Dog();
		Animal *cat = new Cat();

		dynamic_cast<Dog *>(dog)->getBrain()->setIdeas(0, "i am a dog");
		dynamic_cast<Cat *>(cat)->getBrain()->setIdeas(0, "i am a cat");

		*dog = *cat;
		dog->makeSound();

			write_stdout("Dog says", CLR_RESET);
			write_stdout(dynamic_cast<Dog *>(dog)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			write_stdout("Cat changes his mind", CLR_RESET);
			dynamic_cast<Cat *>(cat)->getBrain()->setIdeas(0, "i am a cat, miauuuuuuu");
			write_stdout("Dog says", CLR_RESET);
			write_stdout(dynamic_cast<Dog *>(dog)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			if (dynamic_cast<Dog *>(dog)->getBrain()->getIdeas(0) == dynamic_cast<Cat *>(cat)->getBrain()->getIdeas(0))
				write_stdout("same idea, cat affected dog", CLR_RED);
			else
				write_stdout("different ideas, tmp changed own brain and didn't affect basic", CLR_GRN);

		delete dog;
		delete cat;
	}

	{
		write_stdout("\n		deep copy test: TWO DOG POINTERS\n", CLR_BLUE);
		Animal *dog1 = new Dog();
		Animal *dog2 = new Dog();

		dynamic_cast<Dog *>(dog1)->getBrain()->setIdeas(0, "i am a dog ONE");
		dynamic_cast<Dog *>(dog2)->getBrain()->setIdeas(0, "i am a dog TWO");

		write_stdout("\n		deep copy test: COPY BY DEREFENCING (calling Animal copy assign)\n", CLR_BLUE);
		*dog1 = *dog2;
		dog1->makeSound();
		/*
			We are just changing pointers, you can't deep copy this.... :|
		*/
			write_stdout("Dog1 says", CLR_RESET);
			write_stdout(dynamic_cast<Dog *>(dog1)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			write_stdout("Dog2 changes his mind", CLR_RESET);
			dynamic_cast<Dog *>(dog2)->getBrain()->setIdeas(0, "i am a cat, miauuuuuuu");
			write_stdout("Dog1 says", CLR_RESET);
			write_stdout(dynamic_cast<Dog *>(dog1)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			if (dynamic_cast<Dog *>(dog1)->getBrain()->getIdeas(0) == dynamic_cast<Dog *>(dog2)->getBrain()->getIdeas(0))
				write_stdout("same idea, cat affected dog", CLR_RED);
			else
				write_stdout("different ideas, tmp changed own brain and didn't affect basic", CLR_GRN);


		write_stdout("\n		deep copy test: COPY BY DYNAMIC_CAST (calling Dog copy assign)\n", CLR_BLUE);

		dynamic_cast<Dog *>(dog1)->getBrain()->setIdeas(0, "i am a dog ONE");
		dynamic_cast<Dog *>(dog2)->getBrain()->setIdeas(0, "i am a dog TWO");

		*dynamic_cast<Dog *>(dog1) = *dynamic_cast<Dog *>(dog2);
		dog1->makeSound();
		/*
			We are just changing pointers, you can't deep copy this.... :|
		*/
			write_stdout("Dog1 says", CLR_RESET);
			write_stdout(dynamic_cast<Dog *>(dog1)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			write_stdout("Dog2 changes his mind", CLR_RESET);
			dynamic_cast<Dog *>(dog2)->getBrain()->setIdeas(0, "i am a cat, miauuuuuuu");
			write_stdout("Dog1 says", CLR_RESET);
			write_stdout(dynamic_cast<Dog *>(dog1)->getBrain()->getIdeas(0).c_str(), CLR_GRN);
			if (dynamic_cast<Dog *>(dog1)->getBrain()->getIdeas(0) == dynamic_cast<Dog *>(dog2)->getBrain()->getIdeas(0))
				write_stdout("same idea, cat affected dog", CLR_RED);
			else
				write_stdout("different ideas, tmp changed own brain and didn't affect basic", CLR_GRN);

		delete dog1;
		delete dog2;
	}
	{
		/*

		Cat first;

		first.getBrain()->setIdeas(10, "hello tretas");

		Cat second(first);

		first.getBrain()->setIdeas(10, "haha enganei te");

		Cat third;

		third = first;

		std::cout << second.getBrain()->getIdeas(10) << std::endl;
		std::cout << first.getBrain()->getIdeas(10) << std::endl;

		half_cat_half_dog_new_speak_delete(10);
		*/
	}


	return (0);
}


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
