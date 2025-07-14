/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:34:27 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/14 09:57:34 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <string>

Data::Data(std::string name): _name(name)
{
	std::cout << "start the  Scalar Converter" << std::endl;
}

Data::Data(Data & copy)
{

	std::cout << "start the Scalar Converter copy" << std::endl;
	this->_name = copy._name;
	*this = copy;
}

Data::~Data()
{

	std::cout << "end the Scalar Converter" << std::endl;
}

Data & Data::operator=(Data &copy)
{
	if(this == &copy)
		return (*this);
	this->_name = copy._name;
	return *this;
}


std::string Data::get_name()
{
	return _name;
}
