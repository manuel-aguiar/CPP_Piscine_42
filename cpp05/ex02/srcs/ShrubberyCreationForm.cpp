/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:44 by codespace         #+#    #+#             */
/*   Updated: 2024/04/09 14:18:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
								AForm(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC), \
								_target("unknown")
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
								AForm(SHRUB_NAME, SHRUB_SIGN, SHRUB_EXEC), \
								_target(target)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ShrubberyCreationForm Parameter Constructor Called" << std::endl;
	#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
								AForm(copy), \
								_target(copy._target)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
	#endif
	if (this == &copy)
		return ;
	*this = copy;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign)
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ShrubberyCreationForm Copy Assignment Called" << std::endl;
	#endif
	if (this == &assign)
		return (*this);
	AForm::operator=(assign);
	return (*this);
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

/*

	execute is const, so caller cannot be chhanged internally
	can't add a variable _is_executed and change that
	so the same form can be executed multiple times

*/

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	this->beExecuted(executor);
	std::ofstream file(( _target + "_shrubbery" ).c_str());
	if (file.fail())
		throw ShrubberyOpenFileFail();
	file << "Stolen from my sis mnascime :') <3" << "\n\n" \
	<< "                      ___" << "\n" \
	<< "                _,-'\"\"   \"\"\"\"`--." << "\n" \
	<< "             ,-'          __,,-- \\" << "\n" \
	<< "           ,\'    __,--\"\"\"\"dF      )" << "\n" \
	<< "          /   .-\"Hb_,--\"\"dF      /" << "\n" \
	<< "        ,\'       _Hb ___dF\"-._,-'" << "\n" \
	<< "      ,'      _,-\"\"\"\"   \"\"--..__" << "\n" \
	<< "     (     ,-'                  `." << "\n" \
	<< "      `._,'     _   _             ;" << "\n" \
	<< "       ,'     ,' `-'Hb-.___..._,-'" << "\n" \
	<< "       \\    ,'\"Hb.-\'HH`-.dHF\"" << "\n" \
	<< "        `--\'   \"Hb  HH  dF\"" << "\n" \
	<< "                \"Hb HH dF" << "\n" \
	<< "                 \"HbHHdF" << "\n" \
	<< "                  |HHHF" << "\n" \
	<< "                  |HHH|" << "\n" \
	<< "                  |HHH|" << "\n" \
	<< "                  |HHH|" << "\n" \
	<< "                  |HHH|" << "\n" \
	<< "                  dHHHb" << "\n" \
	<< "                .dFd|bHb.               o" << "\n" \
	<< "      o       .dHFdH|HbTHb.          o /" << "\n" \
	<< "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << "\n" \
	<< "##########################################" << std::endl;
	file.close();
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
	const AForm *dummy;

	dummy = &form;
	os << *dummy;
	os << "	target: " << form.getTarget() << std::endl;
	return (os);
}

//Shrubbery open file exception
ShrubberyCreationForm::ShrubberyOpenFileFail::ShrubberyOpenFileFail()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ShrubberyOpenFileFail Constructor Called" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyOpenFileFail::~ShrubberyOpenFileFail() throw()
{
	#ifdef DEBUG_CONSTRUCTOR
		std::cout << "ShrubberyOpenFileFail Destructor Called" << std::endl;
	#endif
}

const char *ShrubberyCreationForm::ShrubberyOpenFileFail::what() const throw()
{
    return ("failed to open file");
}
