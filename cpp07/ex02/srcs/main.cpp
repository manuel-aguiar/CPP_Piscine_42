/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaria-d <mmaria-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:06 by codespace         #+#    #+#             */
/*   Updated: 2024/04/22 18:20:52 by mmaria-d         ###   ########.fr       */
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

	std::cout << "Array of ints" << std::endl;

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

	std::cout << "\narray of std::strings" << std::endl;

	try
	{
		std::cout << "Array Construction" << std::endl;
		Array<std::string> arr(10);
		arr[1] = "yeah some sentence";
		std::cout << arr[1] << std::endl;


		std::cout << "\nArray Copy" << std::endl;
		Array<std::string> copy(arr);
		copy[1] = "nop, i'm a copy";
		std::cout << "original " << arr[1] << "  copy: " << copy[1] << std::endl;


		std::cout << "\nArray Assign" << std::endl;
		Array<std::string> bigger(24);

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

	std::cout << "\narray of... Arrays of floats, why not, sue me" << std::endl;

	try
	{
		std::cout << "Array Construction" << std::endl;
		Array<
			Array<
				float
			>
		> arr(10);

		arr[1] = Array<float>(5);
		arr[1][0] = 1.1f;
		arr[1][1] = 3.2e+4;
		arr[1][2] = -0.5e-20;
		arr[1][3] = 42.42f;
		arr[1][4] = 24.24f;

		std::cout << arr[1][3] << std::endl;


		std::cout << "\nArray Copy" << std::endl;
		Array<
			Array<
				float
			>
		>  copy(arr);
		copy[1] = Array<float>(10);
		copy[1][3] = 4.2f;
		std::cout << "original " << arr[1][3] << "  copy: " << copy[1][3] << std::endl;


		std::cout << "\nArray Assign" << std::endl;
		Array<
			Array<
				float
			>
		>  bigger(24);

		bigger = arr;
		std::cout << bigger.size() << std::endl;

		std::cout << "assign " << bigger[1][3] << std::endl;


		std::cout << "\nOut of range access: " << std::endl;
		bigger[23] = 38;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nempty array" << std::endl;

	try
	{
		Array<int> arr (0);
		std::cout << arr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\ndefault array" << std::endl;

	try
	{
		Array<int> arr;
		std::cout << arr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n'negative size' array" << std::endl;

	try
	{
		Array<int> arr (-1);
		std::cout << "array size: " << arr.size() << " element 0 : " << arr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n school main: " << std::endl;
	{
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

	return (0);
}
