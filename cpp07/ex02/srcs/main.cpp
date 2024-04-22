/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:06 by codespace         #+#    #+#             */
/*   Updated: 2024/04/22 10:23:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

#include <cstdlib>

int main3(void)
{
	int *a = new int;
	std::cout << *a << std::endl;
	return (0);
}

#define MAX_VAL 750

int main3(int, char **) {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;
  return 0;
}

int main(void)
{
	/*
		Wide try-catch, new[] can fail at any moment :)
	*/
	try
	{
		std::cout << "Array Construction" << std::endl;
		Array<int> arr(10);
		arr[1] = 42;
		std::cout << arr[1] << std::endl;


		std::cout << "\nArray Copy" << std::endl;
		Array<int> copy(arr);
		copy[1] = 24;
		std::cout << "original " << arr[1] << "  copy: " << copy[1] << std::endl;


		std::cout << "\nArray Assign" << std::endl;
		Array<int> bigger(24);

		bigger = arr;
		std::cout << bigger.size() << std::endl;

		std::cout << "assign " << bigger[1] << std::endl;


		std::cout << "\nOut of range access: " << std::endl;
		bigger[23] = 38;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
