/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:21:11 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/10 15:31:57 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>


Bureaucrat::Bureaucrat(std::string name,size_t grade):_name(name)
{
	std::cout << "start Bureaucrat" << std::endl;
	setgrad(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy):_name(copy._name)
{

	std::cout <<  "copy Bureaucrat" << std::endl;
	this->_grade = copy._grade;	
}
Bureaucrat::~Bureaucrat() 
{
	std::cout << "end Bureaucrat" << std::endl;
}

void Bureaucrat::setgrad(size_t grade)
{

	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		 _grade = grade;	
}

size_t Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const 
{
	return _name;
}

void Bureaucrat::increment()
{
	setgrad(_grade -1);	
}

void Bureaucrat::decrement()
{
	setgrad(_grade +1);	
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High");
};

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low");
};

std::ostream &operator << (std::ostream &o, Bureaucrat *copy)
{
	o << copy->getName() <<", bureaucrat grade ," << copy->getGrade();
	return o;
}
