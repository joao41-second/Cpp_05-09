/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:26:15 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/21 14:43:16 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK 
#define MUTANTSTACK

#include <stack>
#include <iostream>
template <typename T> 
class MutantStack : public std::stack<T>
{
	public:
		typedef typename  std::stack<T>::container_type::iterator iterator;
		MutantStack();
		MutantStack(const std::stack<T> &copy);
		~MutantStack();
		MutantStack&  operator=(const MutantStack &copy);			

	std::stack<int>::container_type::iterator begin()
	{
		return (std::stack<T>::c.begin());
	}
	std::stack<int>::container_type::iterator end()
	{
		return (std::stack<T>::c.end());
	}

};

#include "MutantStack.tpp"
#endif
