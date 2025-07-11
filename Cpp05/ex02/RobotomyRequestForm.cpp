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
#include <iostream>
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm("file",145,137)
{
	std::cout <<" start RobotomyRequestForm" << std::endl;
	
	_shrubbery = "std.txt";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): 
	AForm(copy.get_name(),copy.get_sing_it(),copy.get_execute_it())
{

	std::cout <<" copy RobotomyRequestForm" << std::endl;
	this->_shrubbery = copy._shrubbery;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout <<" end RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if(this == &copy)
		return (*this);
	_shrubbery = copy._shrubbery;
	return *this;
}



