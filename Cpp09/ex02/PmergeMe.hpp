/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 08:40:17 by jperpct           #+#    #+#             */
/*   Updated: 2025/09/02 09:29:10 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define  PMERGEME_HPP

#include <exception>
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
		std::vector<int> organize(std::vector<int> list);
		std::vector<int> binery_sryche(std::vector<int> list, int nb);
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


#endif
