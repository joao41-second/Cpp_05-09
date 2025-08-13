/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:06:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/08/13 14:04:11 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	srand(time(0));

	Span span = Span(100000);

	for (int i = 0; i < 1000; i++)
	{
		span.addNumber(rand() %10000 +1);	
	}

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
}
