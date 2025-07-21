/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:51:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/20 18:11:15 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

Span::Span(unsigned int N): _N(N)
{
	if(_N == 0 )
		throw  Not_zero();
	std::cout << "start new span" << std::endl;
}


Span::Span(Span const &copy): _N(copy._N)
{
	std::cout << "start new span copy" << std::endl;
	
	for(int i = 0;i <=(int) _N;i++)	
	{
		if(copy._nbs[i] != *copy._nbs.end())
		{
			_nbs.push_back(copy._nbs[i]);
		}else
		{break;}
	}
	
}

Span::~Span()
{
	std::cout << "start end span" << std::endl;
}

Span &Span::operator =(Span const &copy)
{
	if(this == &copy)
		return *this;

	this->_N = copy._N;
	for(int i = 0;i <= (int)_N;i++)	
	{
		if(copy._nbs[i] != *copy._nbs.end())
		{
			this->_nbs.push_back(copy._nbs[i]);
		}else
		{break;}
	}
	return *this;
}

void Span::addNumber(int nb)
{
	if(_nbs.size()+1 <= _N)
		_nbs.push_back(nb);
	else
	 	throw invlalidSize_N(); 
}


int Span::shortestSpan()
{
	int max = 0;
	for(int i = 0;i <= (int)_N;i++)	
	{
		if(_nbs[i] != *_nbs.end())
		{
			if(max == 0 || max < _nbs[i] -_nbs[i-1])
			{
				max =  _nbs[i] -_nbs[i-1];
			}
			if(max == 0 || max < _nbs[i-1] -_nbs[i])
			{
				max =  _nbs[i] -_nbs[i-1];
			}
		}
		else
			break;
	}
	
	return max;
}

int Span::longestSpan()
{
	int min = 0;
	for(int i = 0;i <= (int)_N;i++)	
	{
		if(_nbs[i] != *_nbs.end())
		{
			if(min == 0 ||( min > _nbs[i] -_nbs[i-1] && _nbs[i] -_nbs[i-1] > 0 ))
			{
				min =  _nbs[i] -_nbs[i-1];
			}
			if(min == 0 ||( min > _nbs[i-1] -_nbs[i] &&_nbs[i] -_nbs[i-1] > 0))
			{
				min =  _nbs[i] -_nbs[i-1];
			}
		}
		else
			break;
	}
	
	return min;
}

const char * Span::invlalidSize_N::what() const throw()
{
	return "the max arguments implemented";
}


const char *Span::Not_zero::what() const throw()
{
	return "this class not inicializabel with 0 menbers";
}

const char *Span::not_minal_elements::what() const throw()
{
	return "this class not not_minal_elements for excute this funcion";
}

