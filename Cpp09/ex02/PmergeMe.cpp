/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 08:46:58 by jperpct           #+#    #+#             */
/*   Updated: 2025/09/02 11:34:39 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"
#include <algorithm>
#include <bits/types/__sigset_t.h>
#include <iostream>
#include <ostream>
#include <vector>

int swap_ = 0 ;

void swap(int &v1, int &v2)
{	
	int temp;
	if(v1 > v2)
	{
		swap_++;
		temp = v1;
		v1 = v2;
		v2 = temp;
	}
}

int PmergeMe::Jacobsthal_number(int n)
{
	if(n == 1)
		return (1);
	else if (n <= 0)
		return (0);
	return (Jacobsthal_number(n-1) + 2 *Jacobsthal_number(n-2));
}

std::vector<int> PmergeMe::binery_sryche(std::vector<int> list, int nb)
{
	std::vector<int> l1;
	std::vector<int> l2;
	int temp;
	if(list.size() == 1 )
	{
		if(nb > list[0])
			list.push_back(nb);
		else
		{
			temp = list[0]; 
			list.clear();
			list.push_back(nb);
			list.push_back(temp);
		}	
		return (list);
	}
	l2.assign(list.begin()+list.size() /2,list.end());	
	l1.assign(list.begin(), list.begin()+list.size() /2);

		if(list[list.size() / 2] > nb )
			l1 = binery_sryche(l1, nb);
		else
			l2 = binery_sryche(l2, nb);	
	list.assign(l1.begin(),l1.end());
	list.insert(list.end(),l2.begin(),l2.end());
	return list;
}

void PmergeMe::organize()
{
	clock_t inicio = clock();
	_end = organize_vector(_end);
    clock_t fim = clock();
 double tempoExecucao = double(fim - inicio) * 1000 / CLOCKS_PER_SEC;
std::cout << "Tempo de execucao: " << tempoExecucao << " ms" << std::endl;
	std::cout << _end << std::endl;
}

std::vector<int> PmergeMe::organize_vector(std::vector<int> list)
{
	int odd;
	int odd_c = -1;
	std::vector<int> large;
	std::vector<int> large_copy;
	std::vector<int> smale;	
	if(list.size() % 2 != 0)
	{
		odd_c = 1;
		odd = list.back();
		list.pop_back();
	}
	if(list.empty())
	{
		list.push_back(odd);
		return (list);
	}
	for (int i = 0;i < (int)list.size();i+=2)
	{
		swap(list[i],list[i+1]);
		smale.push_back(list[i]);
		large.push_back(list[i+1]);
	}	
	if(smale.size() > 1)
		smale = organize_vector(smale);
	if(odd_c == 1)
		smale = binery_sryche(smale, odd);
	int k =1; 
	
	large_copy = large;
	while(!large.empty())
	{
		if(Jacobsthal_number(k) > (int)large.size())
			break;
		for(int i = 0; Jacobsthal_number(k-1)+1 <= Jacobsthal_number(k)-i;i++)
		{
			std::vector<int>::iterator it = std::find(
					large.begin(),large.end(),
					large_copy[Jacobsthal_number(k)-i-1]);
			if(it != large.end())
			{
				smale = binery_sryche(smale, *it);
			}
		}
		k++;
	}
	return(smale);	
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
	_fib = copy._fib;
	std::cout << "start copy PmergeMe" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	if(this == &copy)
		return *this;
	_start = copy._start;
	_end = copy._end;	
	_fib = copy._fib;
	return *this;
}


const char *PmergeMe::Nb_error::what() const throw()
{
	return "the number list not valid";
}

std::ostream& operator<<(std::ostream& os, const std::vector<int> & list)
{
	for (int i = 0;i < (int)list.size(); i++)
	{	
		if(i != 0)
			os <<',' <<    list[i];
		else
			os <<    list[i];
	}
	os << '.';
	return  os;
}
