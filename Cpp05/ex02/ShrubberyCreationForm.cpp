/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:42:03 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/11 14:14:35 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <iterator>
#include <ostream>
#include <fstream> 

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("file",145,137)
{
	std::cout <<" start ShrubberyCreationForm" << std::endl;
	
	_shrubbery = "std.txt";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name_file): AForm("file",145,137)
{
	std::cout <<" start ShrubberyCreationForm" << std::endl;
	
	_shrubbery = name_file;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy): 
	AForm(copy.get_name(),copy.get_sing_it(),copy.get_execute_it())
{

	std::cout <<" copy ShrubberyCreationForm" << std::endl;
	this->_shrubbery = copy._shrubbery;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout <<" end ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if(this == &copy)
		return (*this);
	_shrubbery = copy._shrubbery;
	return *this;
}
void ShrubberyCreationForm::exexecute(Bureaucrat  & executor)
{	
	if(executor.getGrade() <= get_sing_it() && this->get_signed() == true)
	{
		std::cout << executor.getName() <<" executed " << get_name() << std::endl;
		std::ofstream file(_shrubbery.c_str(),std::ios::out);
		if(file.is_open())
		{
		file << "       *\n";
    		file << "      ***\n";
    		file << "     *****\n";
		file << "    *******\n";
		file << "   *********\n";
		file << "  ***********\n";
		file << " *************\n";
		file << "      |||\n";
		file << "      |||\n";
		file.close();
		}
	}
	else 
		throw AForm::GradeTooLowException();
} 
