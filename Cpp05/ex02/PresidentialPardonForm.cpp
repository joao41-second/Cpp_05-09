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
#include "AForm.hpp"
#include <iostream>
#include <ostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("file",145,137)
{
	std::cout <<" start PresidentialPardonForm" << std::endl;
	
	_shrubbery = "std.txt";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): 
	AForm(copy.get_name(),copy.get_sing_it(),copy.get_execute_it())
{

	std::cout <<" copy PresidentialPardonForm" << std::endl;
	this->_shrubbery = copy._shrubbery;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout <<" end PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if(this == &copy)
		return (*this);
	_shrubbery = copy._shrubbery;
	return *this;
}



