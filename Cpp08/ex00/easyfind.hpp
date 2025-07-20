/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 08:37:10 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/20 09:26:09 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASY
#define EASY

#include <algorithm>
#include <exception>

class NotFound : public std::exception
{
	virtual const char *what() const throw();
};


template <typename T> typename T::value_type easyfind(T &cont, int nb);

template<typename T> typename T::value_type easyfind(T &cont, int nb )
{
	typename T::iterator it;
	it = std::find(cont.begin(),cont.end(),nb);
	if(it == cont.end())
		throw  NotFound();
	return *it;
}


#endif
