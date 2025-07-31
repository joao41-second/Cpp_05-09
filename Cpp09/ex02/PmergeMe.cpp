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


void PmergeMe::organize_2_list(std::vector<int *> s1 , std::vector<int *>s2, std::vector<int *> _s1)
{
	 std::vector<int> s1_copy;
	 std::vector<int> s2_copy;
	for (int i = 0; i < (int) s1.size() ; i++) 
	 {

		s1_copy.push_back(*s1[i]);
	 }
	for (int i = 0; i < (int) s2.size() ; i++) 
	 {
		s2_copy.push_back(*s2[i]);
	 }
	
	
	int l1 = 0;
	int l2 = 0;
	
	for(int i = 0; i < (int)_s1.size(); i++)
	{	
	
		if(l1 >= (int)s1_copy.size() && l2 >=(int) s2_copy.size())
			break;

		if( l1 == (int)s1_copy.size() && l2 < (int)s2_copy.size())
		{
			*_s1[i] = s2_copy[l2];
			l2++;
			continue;
		}

		if( l2 == (int)s2_copy.size() && l1 < (int)s1_copy.size())
		{
			*_s1[i] = s1_copy[l1];

			l1++;
			continue;
		}

		if(s1_copy[l1] < s2_copy[l2])
		{
			*_s1[i] = s1_copy[l1];
			std::cout << " set is" << *_s1[i] << std::endl;
			l1++;
		}
		else
		{
			*_s1[i] = s2_copy[l2];
			std::cout << " set is" << *_s1[i] << std::endl;
			l2++;
		}
	
	}
}

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
	organize_2_list(s1, s2, _s1);	
}
void PmergeMe::organize()
{
	 std::vector<int *> s1;
	 std::vector<int *> s2;
	 std::vector<int *> copy;
	 if(_end.size() == 2)
	 {
	 }


	 for (int i = 0; i < (int)(_end.size() / 2); i++) 
	 {
		s1.push_back(&(_end[i]));
	 }

	std::cout << " "<< std::endl; 


	for (int i = _end.size()/2; i <(int) _end.size() ; i++) 
	 {
		s2.push_back(&(_end[i]));
	 }
	organize_split(s1);	
	organize_split(s2);
	for (int i = 0; i < (int) _end.size() ; i++) 
	 {

		copy.push_back(&_end[i]);
	 }
	organize_2_list(s1, s2, copy);
	std::cout << "lsit end" << std::endl;
	for (int i = 0; i < (int) _end.size() ; i++) 
	 {
		 std::cout << _end[i] << std::endl; 

	 }

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
