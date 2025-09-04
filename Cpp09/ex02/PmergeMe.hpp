/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 08:40:17 by jperpct           #+#    #+#             */
/*   Updated: 2025/09/02 14:17:38 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define  PMERGEME_HPP

#define NB 15

#include <deque>
#include <exception>
#include <ostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <algorithm>

class PmergeMe
{
	private:

    		std::vector<int> _fib;
		std::vector<int> _start;
		std::vector<int> _end;
		//double time;
		std::vector<int> organize_vector(std::vector<int> list);
		std::deque<int> organize_deque(std::deque<int> list);
		int Jacobsthal_number(int);
		
	public:
		PmergeMe(char **argv, int argc);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &copy);
		void organize();

		class Nb_error : public std::exception
		{
			virtual const char * what() const throw();
		};
};


std::ostream& operator<<(std::ostream& os, const std::vector<int> & list);

template <typename cont>
void print_list_limit(int size, cont& c)
{
	
	for (int i = 0;i < (int)c.size() && i < size; i++)
	{	
		if(i != 0)
			std::cout <<' ' <<    c[i];
		else
			std::cout <<   c[i];
	}
	std::cout << std::endl;
}

template <typename cont>
cont binery_sryche(cont list, int nb)
{
	cont  l1;
	cont l2;
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
#endif
