/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:21:01 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/15 08:49:38 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef  TEMPL
#define TEMPL


#include <cstddef>
#include <sys/types.h>

template<typename T, typename  F>

void iter(T &array,size_t nb, F *(func))
{
	for (size_t i = -1; ++i < nb;)
	{
		func(array[i]);
	}
}
#endif
