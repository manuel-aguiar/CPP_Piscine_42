/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:38:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 13:20:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

# define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{

	public:
		AMateria(const std::string& type);

		virtual ~AMateria();

		AMateria(const AMateria& copy);
		AMateria& operator= (const AMateria& assign);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		AMateria();
		const std::string type;
};

/*

	C++ does not have interfaces. However it is accepted
	convention that a class which is made of pure virtual functions
	is to be treated as an interface.
		Cannot be instantiated
		Derived must provide all the implementations, otherwise
		they cannot be instantiated either
			it is like a list of requirements that all instances
			of derived classes must abide by

	In the exercise starting with "A" is an abstract class, some pure virtual methods
	and some not, to be inherited

	Starting with "I" is an interface, all pure virtual methods

*/
/*

	Virtual tables and dynamic dispatch
	https://pabloariasal.github.io/2017/06/10/understanding-virtual-tables/


		dispatch: finding the right function to call (polymorphism context)
			dynamic: at runtime

		a regular member function is the same for all instances (there isn't "one function per instance")
		that one function is called everytime one instance of a class calls it -> static dispatch

		due to virtual functions being able to be overriden, calls cannot be statically dispatched at compile time

		So that resolution is made at runtime: dynamic dispatch ("late binding")

		Each class that has virtual functions (declared or inherited) will have
		a vtable at CLASS LEVEL (not instance level)
		AND a vpointer -> a pointer to a virtual table.
		so, base base* = new derived,
		derived will have a pointer (vpointer) to the vtable of class derived

		vtable will have functiuon pointers to the most specific definition
		if base has a definition, points to its own, if derived has a definition, point to its own and not base

		vpointers are a class member variable, so a class that has/inherits virtual functions will automatically
		be increase in size by sizeof(vpointer)

		Execution of a virtual function:
			get pointer to vtable -> get index of function at vtable -> run.


		#include <iostream>

		class Base{
		public:
			virtual void foo() {}
			virtual void bar() {}
		};

		class Derived : public Base {
		public:
			virtual void foo() override {}
		};

		int main()
		{
			Base *ptr = new Derived;

			ptr->foo();
		}

		Base::foo():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        nop
        pop     rbp
        ret
Base::bar():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        nop
        pop     rbp
        ret
Derived::foo():
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        nop
        pop     rbp
        ret
Base::Base() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     edx, OFFSET FLAT:vtable for Base+16
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        nop
        pop     rbp
        ret
Derived::Derived() [base object constructor]:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    Base::Base() [base object constructor]
        mov     edx, OFFSET FLAT:vtable for Derived+16
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], rdx
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 24
        mov     edi, 8
        call    operator new(unsigned long)
        mov     rbx, rax
        mov     rdi, rbx
        call    Derived::Derived() [complete object constructor]
        mov     QWORD PTR [rbp-24], rbx
        mov     rax, QWORD PTR [rbp-24]
        mov     rax, QWORD PTR [rax]
        mov     rdx, QWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-24]
        mov     rdi, rax
        call    rdx
        mov     eax, 0
        mov     rbx, QWORD PTR [rbp-8]
        leave
        ret
vtable for Derived:
        .quad   0
        .quad   typeinfo for Derived
        .quad   Derived::foo()
        .quad   Base::bar()
vtable for Base:
        .quad   0
        .quad   typeinfo for Base
        .quad   Base::foo()
        .quad   Base::bar()
typeinfo for Derived:
        .quad   vtable for __cxxabiv1::__si_class_type_info+16
        .quad   typeinfo name for Derived
        .quad   typeinfo for Base
typeinfo name for Derived:
        .string "7Derived"
typeinfo for Base:
        .quad   vtable for __cxxabiv1::__class_type_info+16
        .quad   typeinfo name for Base
typeinfo name for Base:
        .string "4Base"



	INTERESTING, with -O3, the compiler removes the vtable and resolves statically ;)

	Still, in main, the vtable pointer is directly at the beginning of the object space
	so at rbp-24, where the object begins, is the pointer to the vtable that the computer can load

	When the program starts, the vtables for the classes used are initialized on the .data segment
	(next with initialized static variables, global variables)

*/




#endif
