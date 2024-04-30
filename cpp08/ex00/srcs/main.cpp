/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:20:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/30 15:49:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

/*
	Demo class
	Not in the headers, this is just a test drive, see cpp07/ex01 tests on the evaluation sheet
	They can do it, so can i :)
*/

class Demo
{
	public:
		Demo(const int number) : _number(number) {};
		~Demo() {/* oh yeah, OCF for you*/}
		Demo(const Demo& copy) : _number(copy._number) {/* vector will call the copy constructor*/};
		int	getNum(void) const {return _number;}

		/*
			std::find requires the equality operator to function
			so we need to define it
		*/

		bool operator==(const Demo& other) const {return (_number == other._number);}

		/*
			associative.find() requires a lower-than comparator
			(in template, class Compare = std::less by default)
			But the compiler doesn't know what the operator< means in our class
			so we have to provide it :).
			At compile time, the compiler will deduce that std::less for
			std::map and std::set will be Demo::operator<

			btw, std::map::Compare requires the operator to have the const keyword:
				we won't change anything in the caller object, otherwise compilation fails
		*/
		bool operator<(const Demo& other) const {return (_number < other._number);}

	private:
		const int		_number;

		Demo() : _number(0) {}
		Demo& operator=(const Demo& assign) {(void)assign; return (*this);}

};

std::ostream& operator<<(std::ostream& os, const Demo& demo)
{
	os << demo.getNum();
	return (os);
}

/*
	Demo class
*/


int main(void)
{
	std::cout << "**********************************" << std::endl;
	std::cout << "A word on iterators\n" << std::endl;
	{
		std::vector<int> vector;
		vector.push_back(5);
		vector.push_back(3);
		vector.push_back(2);
		vector.push_back(6);
		vector.push_back(7);
		int  target(5);

		try
		{
			std::vector<int>::iterator iter = easyfind(vector, target);
			std::cout << "address of vector                  : " << &vector << std::endl;
			std::cout << "memory address of element in vector: " << &(*iter) << ", value: " << *iter << std::endl;
			/*
				&(*iter) -> counter intuitive but an iterator is a class and not a pointer.
				So you deference it (operator* overload of std::vector::iterator) to get the variable within,
				and then get the address of it.

				Overloading the operator& of an iterator could mean you don't know in the stack wherre the iterator
				is (could be useful), hence why the is no overload there (even though you could do it).
				This way, you can have both, iterator location and variable-pointed-to location
			*/
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}


	std::cout << "vector object is on the stack but internally allocates memory on the heap for class members" << std::endl;
	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Sequence container of ints:\n" << std::endl;
	{
		std::vector<int> vector;
		vector.push_back(5);
		vector.push_back(3);
		vector.push_back(2);
		vector.push_back(8);
		vector.push_back(7);
		int  target(5);

		try
		{
			int res = *easyfind(vector, target);
			res++;
			std::cout << "result: " << res << std::endl;
			std::cout << "ok, manipulating input, changing it to 22: " << std::endl;
			std::vector<int>::iterator iter = easyfind(vector, target);
			*iter = 22;
			std::cout	<< "Ok, try to find target... " << std::endl;
			std::cout << "result: " <<  *iter << ", vector at position: " << *easyfind(vector, target) << std::endl;

			/*
				So, the iterator is itself a copy and not a part of the vector itself

			*/
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "too bad :( we changed the value at the vector via the iterator (a pointer :) )" << std::endl;
		}

	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Sequence container of objects of non integer type:\n" << std::endl;
	{
		std::vector<std::string> vector;
		vector.push_back("cenas");
		vector.push_back("tretas");
		vector.push_back("coisas");
		vector.push_back("existencias");
		vector.push_back("yolo");
		std::string  target("tretas");

		try
		{
			std::string res = *easyfind(vector, target);
			std::cout << "found string: '" << res << "'" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Sequence container of objects of a user defined class:\n" << std::endl;

	{
		std::vector<Demo> vector;
		vector.push_back(Demo(1));
		vector.push_back(Demo(2));
		vector.push_back(Demo(3));
		vector.push_back(Demo(4));
		vector.push_back(Demo(5));

		Demo target = Demo(2);
		try
		{
			std::vector<Demo>::iterator iter = easyfind(vector, target);
			std::cout << "found demo with number " << *iter << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}


	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Hm, what about a std::set<int> ?\n" << std::endl;
	{
		std::set<int> set;
		set.insert(5);
		set.insert(3);
		set.insert(2);
		set.insert(8);
		set.insert(7);
		int  target(5);
		try
		{
			std::set<int>::iterator iter = easyfind(set, target);
			std::cout << "result: " << *iter << std::endl;

			/*
				*iter = 22;

				Doesn't allow, keys are promoted to const keys in the set!!
			*/

			std::cout << "requires its own template given the different inititalizer list :(" << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Since we are on it, let's check generic set std::set<Demo>\n" << std::endl;
	{
		std::set<Demo> set;
		set.insert(Demo(5));
		set.insert(Demo(3));
		set.insert(Demo(2));
		set.insert(Demo(8));
		set.insert(Demo(7));
		Demo  target(5);
		try
		{
			std::set<Demo>::iterator iter = easyfind(set, target);
			std::cout << "Demo found: " << *iter << std::endl;

			/*
				*iter = 22;

				Doesn't allow, keys are promoted to const keys in the set!!
			*/

			std::cout << "again, requires own template.. no wonder these containers exist separetely :(" << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}



	std::cout << "**********************************" << std::endl;
	std::cout << "Associative container of ints (as keys, std::string as values but wtv):\n" << std::endl;
	{
		std::map<int, std::string> map;

		map[5] = "tretas";
		map[1] = "tretas";
		map[4] = "tretas";
		map[2] = "tretas";
		map[6] = "tretas";

		int target = 7;

		try
		{
			std::map<int, std::string>::iterator it = easyfind(map, target);
			std::pair<const int, std::string>& pair = *it;
			std::cout << "map find " << pair.first << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << "**********************************" << std::endl;
	std::cout << "Associative containers, std::string find (generic version):\n" << std::endl;
	{
		std::map<std::string, int> map;

		map["cenas"] = 3;
		map["tretas"] = 2;
		map["coisas"] = 5;
		map["templates"] = 4;
		map["yaya"] = 10;

		std::string target = "templates";

		try
		{
			std::map<std::string, int>::iterator it = easyfind(map, target);
			std::pair<const std::string, int>& pair = *it;
			std::cout << "map find '" << pair.first << "'" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}


	std::cout << "**********************************" << std::endl;
	std::cout << "Associative containers, user-defined class:\n" << std::endl;
	{
		std::map<Demo, int> map;

		map[Demo(3)] = 3;
		map[Demo(2)] = 2;
		map[Demo(5)] = 5;
		map[Demo(4)] = 4;
		map[Demo(10)] = 10;

		Demo target = Demo(4);

		try
		{
			std::map<Demo, int>::iterator it = easyfind(map, target);
			std::pair<const Demo, int>& pair = *it;
			std::cout << "map found demo number: " << pair.first << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout 	<< "**********************************" << std::endl;
	std::cout 	<< "Commented example:\n"
				<<	"int target = 65;\n"
				<< "int res = *easyfind(container, target);" << std::endl;
	std::cout	<< "type checking fails, int vs char" << std::endl;


	{
		std::string container("tretas");
		try
		{

			/*
				this won't compile :0 type mismatch between char and int :0
			*/

			/*
			int target = 65;
			(void)target;
			int res = *easyfind(container, target);
			std::cout << res << std::endl;
			*/


		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}


/*

*/
	return (0);
}
