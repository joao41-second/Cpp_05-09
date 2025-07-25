/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 08:40:17 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/25 08:52:41 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define  PMERGEME_HPP

#include <exception>
#include <vector>
#include <iostream>
class PmergeMe
{
	private:
		std::vector<int> _start;
		std::vector<int> _end;
		double time;
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

#endif
