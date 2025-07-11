/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:18:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 12:40:23 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string name, size_t sign_it,  size_t execute_it):
	_name(name), _execute_it(execute_it), _sign_it(sign_it)
{	
	std::cout << "start the form" << std::endl;
	error(sign_it);
	error(execute_it);
	_signed = false;
}

AForm::AForm(const AForm &copy):
	_name(copy._name),_execute_it(copy._execute_it),_sign_it(copy._sign_it)
{
	std::cout << "start the_copy form" << std::endl;
	_signed = copy._sign_it;
}
AForm::~AForm()
{
	std::cout << "end the_copy form" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	this->_signed = src._signed;
	return *this;
}

bool AForm::error(size_t grade)
{ 
	if(grade > 150)
		throw AForm::GradeTooLowException();
	else if(grade < 1)
		throw AForm::GradeTooHighException();
	return (0);
}

std::string AForm::get_name()
{
	return (_name);
}

size_t AForm::get_execute_it()
{
	return (_execute_it);
}

size_t AForm::get_sing_it()
{
	return (_execute_it);
}

bool AForm::get_signed()
{
	return (_signed);
}

void AForm::beSigned(Bureaucrat &brucat)
{
	if(brucat.getGrade() <= _sign_it)
	{
		_signed = true;
	}
	else 
		throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
};

const char * AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low");
}


std::ostream &operator << (std::ostream &o, AForm *copy)
{
	o << copy->get_name() <<", form level for" << copy->get_sing_it() << "the status is the :" << copy->get_signed() ;
	return o;
}
