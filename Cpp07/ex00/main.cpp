/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:26:34 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/15 08:31:11 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include "iostream"
#include <ostream>
#include <string>

int main()
{

	std::string a = "hello_word";

	std::string b = "end_word";	

	std::cout << "a ,b  :" << a << " "<< b << std::endl;

		swap(a, b);

	std::cout << "a ,b  :" << a << " " << b << std::endl;

	std::cout << max(1,5) << std::endl;

	std::cout << max('a','5') << std::endl;

	std::cout << min(1,5) << std::endl;

	std::cout << min('a','5') << std::endl;






}
