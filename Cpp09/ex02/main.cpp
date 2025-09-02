/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:07:25 by jperpct           #+#    #+#             */
/*   Updated: 2025/09/02 12:29:47 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <ostream>

int main(int argc, char **argv)
{
	try {
		PmergeMe ok(argv,argc);
		ok.organize();
	}
	catch(  std::exception &e)
	{
		std::cout << "error : "<<e.what() << std::endl;
	}
}
