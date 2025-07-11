/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   From.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:18:36 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/10 16:43:00 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>


Form::Form(std::string name, size_t sign_it,  size_t execute_it):
	_name(name),_execute_it(execute_it),_sign_it(sign_it)
{	
	std::cout << "start the form" << std::endl;
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

void error(size_t vaule)
{
}



