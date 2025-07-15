/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:39:20 by jperpct           #+#    #+#             */
/*   Updated: 2025/07/15 08:50:02 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include "iostream"

void print(int a)
{
	std::cout<< "int is :"  << a << std::endl;
}

int main()
{

	int nb[5] = {1,2,3,4,5};


	iter(nb,5,print);



}
