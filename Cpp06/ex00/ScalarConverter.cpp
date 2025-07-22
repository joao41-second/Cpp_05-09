/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 09:15:51 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/13 11:01:04 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include "colors.hpp"
#include <algorithm>
#include <cctype>
#include <cfloat>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <ostream>
#include <stdexcept>
#include <stdint.h>
#include <string>


ScalarConverter::ScalarConverter()
{
	std::cout << "start the  Scalar Converter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter & copy)
{

	std::cout << "start the Scalar Converter copy" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{

	std::cout << "end the Scalar Converter" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if(this == &copy)
		return (*this);
	return *this;
}


void ScalarConverter::convert(const std::string str)
{

	(void)str;

	if(is_char(str) == true || is_int(str) == true  || is_float(str) == true  || is_double(str) == true  )
	{
		from_char(str);
		from_int(str);
		from_float(str);
		from_double(str);
	}
	else
	{
		std::cout << "not valid number" << std::endl;
	}
	

}



bool ScalarConverter::is_char(std::string str)
{
	if(str.length() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

bool ScalarConverter::is_int(std::string str)
{
	int sig = 0;
	if(str[0] == '+' ||str[0] == '-')
		sig = 1;
	for(int i = sig;i < (int)str.length();i++)	
	{

		if(!std::isdigit(str[i]))
			return false;
	}
	try 
	{
		long long int convert = std::atoll(str.c_str());
		if(convert > INT_MAX || convert < INT_MIN)
			return false;
	}
	catch( std::invalid_argument &e)
	{
		return (false);
	}
	return true;
}

bool ScalarConverter::is_float(std::string str)
{
	(void)str;
	int sig = 0;
	if(str == "nanf")
	{	
		return true;
	}
	if(str[0] == '+' ||str[0] == '-')
		sig = 1;
	if(str[str.length()-1] != 'f')
		return false;
	for(int i = sig;i < (int)str.length()-2;i++)	
	{

		if(!std::isdigit(str[i]) && str[i] != '.')
			return false;
	}
	try 
	{
		str[str.length()-1] = '\0';
		str.replace(str.length()-1,0,"");
		float convert = std::atof(str.c_str());
		if(convert > FLT_MAX || convert < -FLT_MAX)
			return false;
	}
	catch( std::invalid_argument &e)
	{
		return (false);
	}	
	return true;
}

bool ScalarConverter::is_double(std::string str)
{
	(void)str;
	int sig = 0;
	if(str == "nan")
	{	
		return true;
	}
	if(str[0] == '+' ||str[0] == '-')
		sig = 1;
	for(int i = sig; i < (int)str.length();i++)	
	{

		if(!std::isdigit(str[i]) && str[i] != '.')
			return false;
		if( str[i] == '.')
			sig = 2;
	}
	if(sig != 2) 
		return false;
	try 
	{
		double convert = std::atof(str.c_str());
		if(convert > DBL_MAX || convert < -DBL_MAX)
			return false;
	}
	catch( std::invalid_argument &e)
	{
		return (false);
	}	
	return true;
}


void ScalarConverter::from_char(std::string str)
{
	if(is_char(str) == true)
	{

		std::cout << GREEN << "char: "<< str << RESET << std::endl;
		return;
	}
	int nb = std::atoll(str.c_str());
	char c = nb;
	if(nb > 255)
	{
		std::cout << GREEN << "char: "<< "overflow" << RESET << std::endl;
	}
	
	if(!std::isprint(static_cast<unsigned char>(c)) )
	{

		std::cout << GREEN << "char: "<< "not printable" << RESET << std::endl;
		return;
	}
		std::cout << GREEN << "char: "<< c << RESET << std::endl;



}

void ScalarConverter::from_int(std::string str)
{	
	if(is_char(str) == true)
	{
		std::cout << RED <<"int: "<<  (int)static_cast<unsigned char>(str[0]) << RESET << std::endl;
		return;
	}
	long long int i = std::atoll(str.c_str());	
	if(i > INT_MAX || i < INT_MIN)
	{
		std::cout << RED <<"int: "<<  "overflow" << RESET << std::endl;
		return;
	}
	std::cout << RED <<"int: "<<  i << RESET << std::endl;
}

void ScalarConverter::from_float(std::string str)
{

	
	if(is_char(str) == true)
	{
		std::cout << YELLOW <<"float: "<<  (float)static_cast<unsigned char>(str[0]) << "f" << RESET << std::endl;
		return;
	}
	float i = std::atof(str.c_str());
	if(i > FLT_MAX || i < -FLT_MAX)
	{
		std::cout << RED <<"float: "<<  "overflow" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW <<"float: "<<  i << "f"<< RESET << std::endl;

}

void ScalarConverter::from_double(std::string str)
{

	std::string use = ".0" ;
	
	if(is_char(str) == true)
	{

		if( (int)static_cast<unsigned char>(str[0]) % 1 != 0)
			use = "";
		std::cout << YELLOW <<"double: "<<  (float)static_cast<unsigned char>(str[0]) << RESET << std::endl;
		return;
	}
	double i = std::atof(str.c_str());

	if( (int)static_cast<unsigned char>(str[0]) % 1 != 0)
		use = "";
	if(i > FLT_MAX || i < -FLT_MAX)
	{
		std::cout << RED <<"double: "<<  "overflow" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW <<"double: "<<  i << use << RESET << std::endl;

}
