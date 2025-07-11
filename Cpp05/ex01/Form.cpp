/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:18:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 10:52:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>


Form::Form(std::string name, size_t sign_it,  size_t execute_it):
	_name(name),_execute_it(execute_it),_sign_it(sign_it)
{	
	std::cout << "start the form" << std::endl;
	error(sign_it);
	error(execute_it);
	_signed = 0;
}

Form::Form(const Form &copy):
	_name(copy._name),_execute_it(copy._execute_it),_sign_it(copy._sign_it)
{
	std::cout << "start the_copy form" << std::endl;
	_signed = copy._sign_it;
}
Form::~Form()
{
	std::cout << "end the_copy form" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	this->_signed = 1;
	return *this;
}

bool Form::error(size_t grade)
{ 
	if(grade > 150)
		throw Form::GradeTooLowException();
	else if(grade < 1)
		throw Form::GradeTooHighException();
	return (0);
}

std::string Form::get_name()
{
	return (_name);
}

size_t Form::get_execute_it()
{
	return (_execute_it);
}

size_t Form::get_sing_it()
{
	return (_execute_it);
}

bool Form::get_signed()
{
	return (_signed);
}

const char * Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
};

const char * Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low");
}


std::ostream &operator << (std::ostream &o, Form *copy)
{
	o << copy->get_name() <<", form level for" << copy->get_sing_it() << "the status is the :" << copy->get_signed() ;
	return o;
}
