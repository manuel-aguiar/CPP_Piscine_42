/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/04/04 16:11:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	I would have made the public constructor as protected:
		accessible to descendents Cat/Dog but uninstantiable

	apparently as per the evaluation guide, the class must have a virtual function = 0;
	so there it is

	It must have a virtual function such that it is not instantiable
		virtual func() = 0 is C++ syntax
		Any derived class that doesn't present a declaration and implementation for
		such a function, will become an abstract class as well.

*/

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

#include <string>
#include <iostream>

/*
	Abstract class has at least one pure virtual function:
		a function prototype, explicitely without definition
		syntax: virtual func = 0;

	Making all the constructors protected would make it impossible
	to instantiate from main.

	Interestingly enough, you you put the constructors protected,
	derived can add them to their member initialization lists
	(pre-construction)
	but not at the function bodies :0
	Constructor Body is already post-construction
*/

class Animal
{
    public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator= (const Animal& assign);

		const std::string&	getType(void) const;

		virtual void	makeSound(void) const = 0;

    protected:
		// Animal();
		Animal(const std::string& type);
		std::string type;
};

/*
	random note:

	lvalue = has location in memory, persistent
		you do math and save the value somewhere
	rvalue = temporary that is discarded, example middle math evaluation
	x =	1 + 1 + 1, 2 + 1 (2 is discarded), 3 assigned to x

*/

/*

	questions i can't still answer...
	why virtual destructors lead to a delete call in assemby.
	Example:

	#include <iostream>
using namespace std;

class Grandparent {
 public:
    virtual ~Grandparent() {};
  virtual void grandparent_foo() {}
  int grandparent_data;
};

class Parent1 : virtual public Grandparent {
 public:
    virtual ~Parent1() {};
  virtual void parent1_foo() {}
  int parent1_data;
};

class Parent2 : virtual public Grandparent {
 public:
    virtual ~Parent2() {};
  virtual void parent2_foo() {}
  int parent2_data;
};

class Child : public Parent1, public Parent2 {
 public:
  ~Child();
  virtual void child_foo() {}
  int child_data;
};

int main() {
  Child child;
}

Assembly:

Grandparent::~Grandparent() [base object destructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     edx, OFFSET FLAT:vtable for Grandparent+16
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        nop
        pop     rbp
        ret
Grandparent::~Grandparent() [deleting destructor]:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    Grandparent::~Grandparent() [complete object destructor]
        mov     rax, QWORD PTR [rbp-8]
        mov     esi, 16
        mov     rdi, rax
        call    operator delete(void*, unsigned long)                                                         <- what? no "new" anywhere? implying new Grandparent()?
        leave
        ret
Grandparent::grandparent_foo():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        nop
        pop     rbp
        ret
Grandparent::Grandparent() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     edx, OFFSET FLAT:vtable for Grandparent+16
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        nop
        pop     rbp
        ret
Parent1::Parent1() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     QWORD PTR [rbp-16], rsi
        mov     rax, QWORD PTR [rbp-16]
        mov     rdx, QWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax]
        sub     rax, 24
        mov     rax, QWORD PTR [rax]
        mov     rdx, rax
        mov     rax, QWORD PTR [rbp-8]
        add     rdx, rax
        mov     rax, QWORD PTR [rbp-16]
        mov     rax, QWORD PTR [rax+8]
        mov     QWORD PTR [rdx], rax
        nop
        pop     rbp
        ret
Parent2::Parent2() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     QWORD PTR [rbp-16], rsi
        mov     rax, QWORD PTR [rbp-16]
        mov     rdx, QWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax]
        sub     rax, 24
        mov     rax, QWORD PTR [rax]
        mov     rdx, rax
        mov     rax, QWORD PTR [rbp-8]
        add     rdx, rax
        mov     rax, QWORD PTR [rbp-16]
        mov     rax, QWORD PTR [rax+8]
        mov     QWORD PTR [rdx], rax
        nop
        pop     rbp
        ret
Child::Child() [complete object constructor]:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        add     rax, 32
        mov     rdi, rax
        call    Grandparent::Grandparent() [base object constructor]
        mov     rax, QWORD PTR [rbp-8]
        mov     edx, OFFSET FLAT:_ZTT5Child+8
        mov     rsi, rdx
        mov     rdi, rax
        call    Parent1::Parent1() [base object constructor]
        mov     rax, QWORD PTR [rbp-8]
        add     rax, 16
        mov     edx, OFFSET FLAT:_ZTT5Child+24
        mov     rsi, rdx
        mov     rdi, rax
        call    Parent2::Parent2() [base object constructor]
        mov     edx, OFFSET FLAT:_ZTV5Child+24
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        mov     rax, QWORD PTR [rbp-8]
        add     rax, 32
        mov     edx, OFFSET FLAT:_ZTV5Child+136
        mov     QWORD PTR [rax], rdx
        mov     edx, OFFSET FLAT:_ZTV5Child+80
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax+16], rdx
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 48
        lea     rax, [rbp-48]
        mov     rdi, rax
        call    Child::Child() [complete object constructor]
        lea     rax, [rbp-48]
        mov     rdi, rax
        call    Child::~Child() [complete object destructor]
        mov     eax, 0
        leave
        ret
vtable for Grandparent:
        .quad   0
        .quad   typeinfo for Grandparent
        .quad   Grandparent::~Grandparent() [complete object destructor]
        .quad   Grandparent::~Grandparent() [deleting destructor]
        .quad   Grandparent::grandparent_foo()
typeinfo for Grandparent:
        .quad   vtable for __cxxabiv1::__class_type_info+16
        .quad   typeinfo name for Grandparent
typeinfo name for Grandparent:
        .string "11Grandparent"

*/

#endif
