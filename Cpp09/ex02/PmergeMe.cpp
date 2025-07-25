/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 08:46:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/25 08:55:56 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"


PmergeMe::PmergeMe(char **argc,int argv)
{
	if(argv < 2)
		throw Nb_error();
	

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
