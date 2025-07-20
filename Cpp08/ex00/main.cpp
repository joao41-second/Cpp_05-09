/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 08:46:04 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/20 09:29:44 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include "easyfind.hpp"


const char *NotFound::what() const throw()
{
	return "not find\n";
}

int main() {
	std::vector<int> nbur;
	int val = 100;
	
	for(int i = 0; i < val; i++)
	{
		nbur.push_back(i);
	}

	try {
	
		std::cout  << " values finded is :"<< easyfind(nbur, 50) << std::endl; 
	
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	try {
		
		std::cout << "values finded is :" << easyfind(nbur, 200) << std::endl; 
	
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "thie nbs is :" << nbur[2] << std::endl;


	
}
