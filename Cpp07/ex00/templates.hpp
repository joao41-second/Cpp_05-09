/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:21:01 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/15 08:25:37 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef  TEMPL
#define TEMPL


template<typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = a;
}

template<typename T>

T max(T a, T b)
{
	if(a > b)
		return a;
	return  b;
}

template<typename T>
T min(T a, T b)
{
	if(a < b)
		return a;
	return  b;
}

#endif
