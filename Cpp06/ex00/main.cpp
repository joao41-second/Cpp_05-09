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

int  main()
{
	
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("o");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("A");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("97");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("+1");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("-100000000000000000000000000");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("1.0");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("-1.0");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("-1.0f");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("-1a.0f");
	std::cout << "------" <<std::endl;
	ScalarConverter::convert("nan");
	std::cout << "------" <<std::endl;


}
