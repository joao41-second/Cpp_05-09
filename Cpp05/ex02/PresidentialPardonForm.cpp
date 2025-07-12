/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:42:03 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 14:23:33 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <ostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential",25,5)
{
	std::cout <<" start PresidentialPardonForm" << std::endl;
	
	_target = "std.txt";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name_file): AForm("presidential",25,5)
{
	std::cout <<" start ShrubberyCreationForm" << std::endl;

	srand(static_cast<unsigned int>(time(0)));
	
	_target = name_file;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): 
	AForm(copy.get_name(),copy.get_sing_it(),copy.get_execute_it())
{

	std::cout <<" copy PresidentialPardonForm" << std::endl;
	this->_target = copy._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout <<" end PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if(this == &copy)
		return (*this);
	_target = copy._target;
	return *this;
}


void PresidentialPardonForm::exexecute(Bureaucrat  & executor)
{	
	if(executor.getGrade() <= get_sing_it() && this->get_signed() == true)
	{
		std::cout << executor.getName() <<" executed " << get_name() << std::endl;
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		
	
	}
	else 
		throw AForm::GradeTooLowException();
}
