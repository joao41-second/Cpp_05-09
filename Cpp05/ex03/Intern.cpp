/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:28:44 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/12 12:08:38 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>



Intern::Intern()
{
	std::cout << "start the Intern" << std::endl;
}

Intern::Intern(Intern &copy)
{

	std::cout << "start copy the Intern" << std::endl;
	*this = copy;
}
Intern::~Intern()
{

	std::cout << "end the Intern" << std::endl;
	
}

Intern & Intern::operator = (Intern &copy)
{
	if(this == &copy)
		return *this;
	return *this;
}


AForm *Intern::makeForm(std::string name, std::string targat )
{

	AForm *form = NULL;
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	if(name  ==  forms[0])
		 form = new PresidentialPardonForm(targat);
	else if(name  ==  forms[1])
		 form = new RobotomyRequestForm(targat);
	else if(name  ==  forms[2])
		 form = new RobotomyRequestForm(targat);
	else
		throw   NotValidForm();
	return (form);
}


const char* Intern::NotValidForm::what() const throw()
{
	return ("not valid form");
}
