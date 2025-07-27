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
#include <bits/types/__sigset_t.h>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>


void PmergeMe::organize_split(std::vector<int *> _s1 )
{

	 std::vector<int *> s1;
	 std::vector<int *> s2;
	 int temp;
	 if(_s1.size() <= 2)
	 {
		 
		 if( _s1.size() == 2 && *_s1[0] > *_s1[1])
		 {
			 temp = *_s1[0];
			 *_s1[0] = *_s1[1];
			 *_s1[1] = temp;
		 }
			 
		 return;
	 }
	
	 for (int i = 0; i < (int)(_s1.size() / 2); i++) 
	 {
		s1.push_back(_s1[i]);
	 }

	for (int i = _s1.size()/2; i <(int) _s1.size() ; i++) 
	 {
		s2.push_back((_s1[i]));

	 }

	organize_split(s1);
	
	organize_split(s2);
	
	std::cout << " "<< std::endl; 

	for (int i = 0; i < (int) s1.size() ; i++) 
	 {
		 std::cout << *s1[i] << std::endl; 

	 }
	std::cout << " "<< std::endl; 
	std::cout << " "<< std::endl; 
	for (int i = 0; i < (int) s2.size() ; i++) 
	 {
		 std::cout << *s2[i] << std::endl; 

	 }
	std::cout << " "<< std::endl; 


	
	
}
void PmergeMe::organize()
{
	 std::vector<int *> s1;
	 std::vector<int *> s2;
	 if(_end.size() == 2)
	 {
	 }


	 for (int i = 0; i < (int)(_end.size() / 2); i++) 
	 {
		 std::cout << _end[i] << std::endl; 
		s1.push_back(&(_end[i]));
	 }

	std::cout << " "<< std::endl; 


	for (int i = _end.size()/2; i <(int) _end.size() ; i++) 
	 {

		 std::cout << _end[i] << std::endl; 
		s2.push_back(&(_end[i]));

	 }
	organize_split(s1);

	//organize_split(s2);
}

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
	_end = _start;
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
