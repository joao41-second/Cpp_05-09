/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:15:57 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 14:42:39 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include  "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm("robot",72,45)
{
	std::cout <<" start RobotomyRequestForm" << std::endl;
	
	srand(static_cast<unsigned int>(time(0)));
	_target = "std";
}
RobotomyRequestForm::RobotomyRequestForm(std::string name_file): AForm("robot",72,45)
{
	std::cout <<" start ShrubberyCreationForm" << std::endl;

	srand(static_cast<unsigned int>(time(0)));
	
	_target = name_file;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): 
	AForm(copy.get_name(),copy.get_sing_it(),copy.get_execute_it())
{

	std::cout <<" copy RobotomyRequestForm" << std::endl;
	this->_target = copy._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout <<" end RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if(this == &copy)
		return (*this);
	_target = copy._target;
	return *this;
}


void RobotomyRequestForm::exexecute(Bureaucrat  & executor)
{	
	if(executor.getGrade() <= get_sing_it() && this->get_signed() == true)
	{
		std::cout << executor.getName() <<" executed " << get_name() << std::endl;
		 int i = random();
		if(i % 2 == 0)
		{
			std::cout  << "the " << _target << "has been robotomized" << std::endl;
		}
		else
			std::cout  << "the " << _target << "has been not robotomized" << std::endl;
	
	}
	else 
		throw AForm::GradeTooLowException();
}
