/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 08:46:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/25 09:12:36 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"
#include <iterator>


PmergeMe::PmergeMe(char **argc,int argv)
{
	long int temp;
	std::vector<int>::iterator t;
	if(argv <= 2)
		throw Nb_error();
	for (int i = 1;i < argv; i++)
	{
		temp = std::atol(argc[i]);
		if(i != 1)
		{
			t = std::find(_start.begin(),_start.end(),temp);
			if(t != _start.end())
				throw Nb_error();
		}
		if(temp > INT_MAX || temp < INT_MIN )
			throw Nb_error();
		_start.push_back(temp);
	}
	std::cout << "start PmergeMe" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "end PmergeMe" << std::endl;
}


PmergeMe::PmergeMe(PmergeMe  const &copy)
{
	_start = copy._start;
	_end = copy._end;
	std::cout << "start copy PmergeMe" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	if(this == &copy)
		return *this;
	_start = copy._start;
	_end = copy._end;	
	return *this;
}


const char *PmergeMe::Nb_error::what() const throw()
{
	return "the number list not valid";
}
