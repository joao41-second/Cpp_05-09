/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:35:54 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/21 14:19:46 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <stack>


template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "start MUTANTSTACK" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const std::stack<T> &copy) : std::stack<T>(copy)
{
	std::cout << "start MUTANTSTACK" << std::endl;
}
template<typename T> 
MutantStack<T>::~MutantStack<T>()
{

	std::cout << "end MUTANTSTACK" << std::endl;
}
