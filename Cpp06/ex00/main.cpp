/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:21:04 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/13 10:59:00 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iterator>

int  main(int argc,char **argv)
{	
	(void)argc;
	if(argc > 1)
		ScalarConverter::convert(argv[1]);
}
