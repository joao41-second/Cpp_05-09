/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:59:51 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/24 13:22:18 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cmath>
#include <iostream>
#include <iterator>
#include <ostream>


void RPN::exec()
{
	float i1 =0 ,i2 =0 ;
	for(int i = 0;i < (int)_save.size();i++)
	{	
		if(_save[i] -'0' >= 0 && _save[i] -'0' <= 9)	
		{
			_stack.push((_save[i] -'0'));
		}

		if(_stack.size() >= 2)
		{
		switch (_save[i])
		{
			case '+': 
				i2 = _stack.top();
				_stack.pop();
				i1 = _stack.top();
				_stack.pop();
				_stack.push(i1 + i2);
				//std::cout << i1 << " + " << i2 << std::endl;
				break;
			case '-':
				i2 = _stack.top();
				_stack.pop();
				i1 = _stack.top();
				_stack.pop();
				_stack.push(i1 - i2);

				//std::cout << i1 << " - " << i2 << std::endl;
				break;
			case '/':
				i2 = _stack.top();
				_stack.pop();
				i1 = _stack.top();
				_stack.pop();

				//std::cout << i1 << " / " << i2 << std::endl;
				if(i2 == 0)
				{
				  throw	error_infit();
				}else {		
					_stack.push(i1 / i2);
				}
				
				break;
			case '*':
				i2 = _stack.top();
				_stack.pop();
				i1 = _stack.top();
				_stack.pop();
				_stack.push(i1 * i2);

				//std::cout << i1 << " * " << i2 << std::endl;
				break;
			default:
				(void) i1;
			
		}	
		}
	}
	std::cout << "the value is :"  << _stack.top() << " " << std::endl;
}


RPN::RPN(std::string input)
{
	for(int i = 0;i < (int)input.size();i++)
	{	
		if(std::isdigit(input[i]) == false && valid_char.find(input[i]) > 5 )
		{
			throw error_input();
		}
		if( input[i] != ' '  &&  input[i+1] != ' ' && i+1 < (int)input.size() )
		{
			throw error_input();
		}
	}

	_save = input;
	std::cout << "start RPN" << std::endl;
}

RPN::RPN(RPN const  &copy)
{
	this->_save = copy._save;
}

RPN::~RPN()
{
	std::cout << "end RPN" << std::endl;
}

const char * RPN::error_input::what() const throw()
{
	return ("error in input");
}

const char * RPN::error_infit::what() const throw()
{
	return ("x / 0 is infinty");
}

RPN &RPN::operator=(const RPN & copy)
{
	if(this == &copy)
		return *this;
	this->_save = copy._save;
	return *this;
}
